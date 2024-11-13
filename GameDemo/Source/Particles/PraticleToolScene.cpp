#include "PraticleToolScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool PraticleToolScene::init()
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

    auto menu = utils::createInstance<PopSceneMenu>();
    if (menu != nullptr)
    {
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }
    
    ParticleSystemQuad* funkyEmitter = ParticleSystemQuad::create("res/Praticles/Funky.plist");
    funkyEmitter->setPosition(origin.x + visibleSize.width * 0.25, origin.y + visibleSize.height * 0.5);
    this->addChild(funkyEmitter);

    ParticleSystemQuad* sinhnxEmitter = ParticleSystemQuad::create("res/Praticles/sinhnx.plist");
    sinhnxEmitter->setPosition(origin.x + visibleSize.width * 0.75, origin.y + visibleSize.height * 0.25);
    this->addChild(sinhnxEmitter);
    return true;
}