#include "CustomParticleScene.hpp"

USING_NS_AX;

bool CustomParticleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("Custom Particle Scene");

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    Image* image = new Image();
    image->initWithImageFile("res/Praticles/Funky.png");

    Texture2D* texture = new Texture2D();
    texture->initWithImage(image);

    ParticleSystemQuad* emitter = ParticleSystemQuad::create();

    emitter->setTexture(texture);
    emitter->setBlendFunc(BlendFunc::ADDITIVE);
    // Common Properties
    emitter->setPosition(origin.x + visibleSize.width * 0.5, origin.y + visibleSize.height * 0.5);
    emitter->setVisible(true);
    emitter->setEmissionRate(50.0);
    emitter->setDuration(ParticleSystem::DURATION_INFINITY);

    emitter->setLife(3.0);
    emitter->setLifeVar(1.0);

    emitter->setStartSpin(1.0);
    emitter->setStartSpinVar(0.2);
    emitter->setEndSpin(1.0);
    emitter->setEndSpinVar(0.2);

    emitter->setStartSize(10.0);
    emitter->setStartSizeVar(5.0);
    emitter->setEndSize(1.0);
    emitter->setEndSizeVar(0.1);

    emitter->setStartColor(Color4F(1.0, 1.0, 1.0, 1.0));
    emitter->setStartColorVar(Color4F(1.0, 1.0, 1.0, 1.0));
    emitter->setEndColor(Color4F(1.0, 1.0, 1.0, 1.0));
    emitter->setEndColorVar(Color4F(1.0, 1.0, 1.0, 1.0));

    // Mode: Gravity
    emitter->setEmitterMode(ParticleSystem::Mode::GRAVITY);
    emitter->setGravity(Vec2(0, 9.8));
    emitter->setSpeed(10.0);
    emitter->setSpeedVar(2.0);
    emitter->setTangentialAccel(100.0);
    emitter->setTangentialAccelVar(50.0);
    emitter->setRadialAccel(20.0);
    emitter->setRadialAccelVar(5.0);
    
    // // Mode: Radial
    // emitter->setEmitterMode(ParticleSystem::Mode::RADIUS);
    // emitter->setStartRadius(10.0);
    // emitter->setStartRadiusVar(5.0);
    // emitter->setEndRadius(150.0);
    // emitter->setEndRadiusVar(20.0);
    // emitter->setRotatePerSecond(90.0);
    // emitter->setRotatePerSecondVar(20.0);
    
    this->addChild(emitter);

    return true;
}