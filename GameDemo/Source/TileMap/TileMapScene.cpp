#include "TileMapScene.hpp"
#define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#    include "audio/AudioEngine.h"
#endif

USING_NS_AX;

bool TileMapScene::init()
{
    if(!TemplateScene::init())
    {
        return false;
    }
    setTitle("Tile Map !");

    _tileMap = new TMXTiledMap();
    _tileMap->initWithTMXFile("res/tilemap/TileMap.tmx");
    _background = _tileMap->getLayer("Background");
    _meta       = _tileMap->getLayer("Meta");
    // _meta->setVisible(false);

    _foreground = _tileMap->getLayer("Foreground");

    TMXObjectGroup* objGroup = _tileMap->getObjectGroup("Objects");
    if (objGroup == NULL)
    {
        AXLOG("tile map has no objects object layer");
        return false;
    }
    // ValueVector spawnPoint = objGroup->getObjects();
    ValueMap spawnPoint = objGroup->getObject("SpawnPoint");
    int x               = spawnPoint.at("x").asInt();
    int y               = spawnPoint.at("y").asInt();
    printf("x = %d, y = %d\n", x, y);

    addChild(_tileMap);

    _player = new Sprite();
    _player->initWithFile("res/tilemap/Player.png");
    _player->setPosition(Vec2(x, y));
    addChild(_player);

    _numCollected = 0;
    _gameInfo     = new GameInfoLayer();
    _gameInfo->init();
    this->addChild(_gameInfo);
    _gameInfo->numCollectedChanged(_numCollected);

    setViewPointCenter(_player->getPosition());

    auto touchEvent          = EventListenerTouchOneByOne::create();
    touchEvent->onTouchBegan = [](Touch* touch, Event* event) {
        AXLOG("onTouchBegan event");
        return true;
    };
    touchEvent->onTouchMoved = [](Touch* touch, Event* event) { AXLOG("onTouchMoved event"); };
    touchEvent->onTouchEnded = [this](Touch* touch, Event* event) {
        // this->touchEndEvent(touch, event);
        Point touchLocation = touch->getLocationInView();
        touchLocation       = Director::getInstance()->convertToGL(touchLocation);
        touchLocation       = this->convertToNodeSpace(touchLocation);

        Point playerPos = _player->getPosition();
        Point diff      = touchLocation - playerPos;

        if (abs(diff.x) > abs(diff.y))
        {
            if (diff.x > 0)
            {
                playerPos.x += _tileMap->getTileSize().width;
            }
            else
            {
                playerPos.x -= _tileMap->getTileSize().width;
            }
        }
        else
        {
            if (diff.y > 0)
            {
                playerPos.y += _tileMap->getTileSize().height;
            }
            else
            {
                playerPos.y -= _tileMap->getTileSize().height;
            }
        }
        // safety check on the bounds of the map
        if (playerPos.x <= (_tileMap->getMapSize().width * _tileMap->getTileSize().width) &&
            playerPos.y <= (_tileMap->getMapSize().height * _tileMap->getTileSize().height) && playerPos.y >= 0 &&
            playerPos.x >= 0)
        {
            this->setPlayerPosition(playerPos);
        }
        this->setViewPointCenter(_player->getPosition());
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchEvent, _player);

    return true;
}

void TileMapScene::setViewPointCenter(Point position)
{
    Size winSize = Director::getInstance()->getWinSize();
    int x        = MAX(position.x, winSize.width / 2);
    int y        = MAX(position.y, winSize.height / 2);
    x            = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
    y            = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height / 2);
    Point actualPosition = Vec2(x, y);
    Point centerOfView   = Vec2(winSize.width / 2, winSize.height / 2);
    Point viewPoint      = centerOfView - actualPosition;
    _gameInfo->setPosition(viewPoint);
    this->setPosition(viewPoint);
}

Point TileMapScene::tileCoordForPosition(Point position)
{
    int x = position.x / _tileMap->getTileSize().width;
    int y =
        (_tileMap->getMapSize().height * _tileMap->getTileSize().height - position.y) / _tileMap->getTileSize().height;
    return Point(x, y);
}
void TileMapScene::setPlayerPosition(Point position)
{
    Point tileCoord = this->tileCoordForPosition(position);
    int tileGid     = _meta->getTileGIDAt(tileCoord);
    if (tileGid)
    {
        ax::Value prop = _tileMap->getPropertiesForGID(tileGid);
        if (!prop.isNull())
        {
            ax::ValueMap vm = prop.asValueMap();
            if (vm.find("Collidable") != vm.cend() && !vm.at("Collidable").asString().compare("True"))
            {
                // AudioEngine::play2d("res/tilemap/hit.caf");
                return;
            }
            if (vm.find("Collectable") != vm.cend() && !vm.at("Collectable").asString().compare("True"))
            {
                _meta->removeTileAt(tileCoord);
                _foreground->removeTileAt(tileCoord);
                _numCollected++;
                _gameInfo->numCollectedChanged(_numCollected);
                AudioEngine::play2d("res/tilemap/pickup.caf");
            }
            else
            {
                AudioEngine::play2d("res/tilemap/move.caf");
            }
        }
    }
    _player->setPosition(position);
}