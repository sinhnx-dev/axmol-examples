#include "TinySkiMapScene.hpp"

#define USE_AUDIO_ENGINE 1

#if USE_AUDIO_ENGINE
#    include "audio/AudioEngine.h"
#endif

USING_NS_AX;

bool TinySkiMapScene::init()
{
    if(!TemplateScene::init())
    {
        return false;
    }
    setTitle("Tiny Ski Map");

    // _tileMap = new TMXTiledMap();
    // _tileMap->initWithTMXFile("res/tilemap/pixelshmup.tmx");
    // _tileMap = TMXTiledMap::create("res/tilemap/pixelshmup.tmx");
    _tileMap = utils::createInstance<TMXTiledMap>();
    _tileMap->initWithTMXFile("res/tilemap/pixelshmup.tmx");

    auto bg1 = _tileMap->getLayer("bg1");
    auto bg2 = _tileMap->getLayer("bg2");
    // bg2->setVisible(false);

    this->addChild(_tileMap, -1);

    // AudioEngine::play2d("res/tilemap/TileMap.caf");

    return true;
}