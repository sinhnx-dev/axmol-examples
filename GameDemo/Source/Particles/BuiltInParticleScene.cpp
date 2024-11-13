#include "BuiltInParticleScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool BuiltInParticleScene::init()
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

    auto fireworks = ParticleFireworks::create();
    addChild(fireworks, 10);

    auto fire = ParticleFire::create();
    fire->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 2));
    fire->setScale(0.5);
    addChild(fire, 10);

    auto snow = ParticleSnow::create();
    snow->setPosition(Vec2(visibleSize.width / 2, visibleSize.height));
    addChild(snow, 10);

    auto menu = utils::createInstance<PopSceneMenu>();
    if (menu != nullptr)
    {
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    return true;
}