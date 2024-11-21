#include "TinySkiMapScene.hpp"
#include "../PopSceneMenu.hpp"

#define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#    include "audio/AudioEngine.h"
#endif

USING_NS_AX;

bool TinySkiMapScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    auto label = Label::createWithTTF("TileMap", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        AXLOG("can't load font'fonts/Marker Felt.ttf'");
    }
    else
    {
        label->setPosition(
            Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height));
        this->addChild(label, 1);
    }

    auto menu = utils::createInstance<PopSceneMenu>();
    if (menu != nullptr)
    {
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    // _tileMap = new TMXTiledMap();
    // _tileMap->initWithTMXFile("res/tilemap/pixelshmup.tmx");
    // _tileMap = TMXTiledMap::create("res/tilemap/pixelshmup.tmx");
    _tileMap = utils::createInstance<TMXTiledMap>();
    _tileMap->initWithTMXFile("res/tilemap/pixelshmup.tmx");

    auto bg1 = _tileMap->getLayer("bg1");
    auto bg2 = _tileMap->getLayer("bg2");
    // bg2->setVisible(false);

    this->addChild(_tileMap);

    AudioEngine::play2d("res/tilemap/TileMap.caf");

    return true;
}