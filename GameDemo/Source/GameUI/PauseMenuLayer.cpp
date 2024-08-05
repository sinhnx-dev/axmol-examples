// #include "MainScene.h"
#include "PauseMenuLayer.h"

USING_NS_AX;

// on "init" you need to initialize your instance
bool PauseMenuLayer::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    auto audioBox = Sprite::createWithSpriteFrameName("Box_Blue_Rounded.png");
    audioBox->setPosition(origin.x + visibleSize.x / 2,origin.y + visibleSize.y/2);
    this->addChild(audioBox);
}

// void PauseMenuLayer::update(float delta)
// {

// }