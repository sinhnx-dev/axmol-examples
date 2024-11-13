#include "BasicSpriteScene.hpp"

USING_NS_AX;

bool BasicSpriteScene::init()
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

    auto sprite1 = Sprite::create("HelloWorld.png");
    sprite1->setPosition(Vec2(visibleSize.width / 2, 150));
    this->addChild(sprite1);

    auto sprite2 = Sprite::create("HelloWorld.png");
    sprite2->setPosition(Vec2(visibleSize.width / 2, 250));
    sprite2->setAnchorPoint(Vec2(0, 0));
    sprite2->setRotation(45);
    sprite2->setScale(0.5);
    this->addChild(sprite2);

    auto sprite3 = Sprite::create("HelloWorld.png");
    sprite3->setPosition(Vec2(visibleSize.width / 2, 250));
    sprite3->setAnchorPoint(Vec2(1, 1));
    sprite3->setRotation(45);
    sprite3->setScale(0.5);
    this->addChild(sprite3);

    return true;
}