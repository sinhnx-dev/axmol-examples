#include "PraticleToolScene.hpp"

USING_NS_AX;

bool PraticleToolScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("Particle Tool");

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;
    
    ParticleSystemQuad* funkyEmitter = ParticleSystemQuad::create("res/Praticles/Funky.plist");
    funkyEmitter->setPosition(origin.x + visibleSize.width * 0.25, origin.y + visibleSize.height * 0.5);
    this->addChild(funkyEmitter);

    ParticleSystemQuad* sinhnxEmitter = ParticleSystemQuad::create("res/Praticles/sinhnx.plist");
    sinhnxEmitter->setPosition(origin.x + visibleSize.width * 0.75, origin.y + visibleSize.height * 0.25);
    this->addChild(sinhnxEmitter);
    return true;
}