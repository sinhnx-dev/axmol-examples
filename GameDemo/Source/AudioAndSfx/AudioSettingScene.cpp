#include "AudioSettingScene.hpp"

USING_NS_AX;

bool AudioSettingScene::init()
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

    auto audioBox = Sprite::createWithSpriteFrameName("Box_Blue_Rounded.png");
    audioBox->setPosition(origin.x + visibleSize.x / 2, origin.y + visibleSize.y / 2);
    audioBox->setScale(0.75);
    this->addChild(audioBox);

    auto mi =
        MenuItemSprite::create(Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
                               Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"), 
                               AX_CALLBACK_1(AudioSettingScene::menuBackCallback, this));
    float x     = safeOrigin.x + safeArea.size.width - mi->getContentSize().width / 2;
    float y     = mi->getContentSize().height / 2;
    mi->setPosition(Vec2(x, y));
    auto menu = Menu::create(mi, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 10);
    
    return true;
}

void AudioSettingScene::menuBackCallback(ax::Object* sender)
{
    AXLOG("pop scene...");
    _director->popScene();
}