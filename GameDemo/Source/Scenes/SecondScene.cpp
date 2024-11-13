#include "SecondScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool SecondScene::init()
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

    auto label = Label::createWithTTF("Second Scene", "fonts/Marker Felt.ttf", 24);
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

    // auto mi = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
    //                                  Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
    //                                  AX_CALLBACK_1(SecondScene::backScene, this));
    // float x = safeOrigin.x + safeArea.size.width - mi->getContentSize().width / 2;
    // float y = mi->getContentSize().height / 2;
    // mi->setPosition(Vec2(x, y));
    // auto menu = Menu::create(mi, nullptr);
    // menu->setPosition(Vec2::ZERO);
    // this->addChild(menu, 10);
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

void SecondScene::backScene(ax::Object* sender)
{
    AXLOG("pop scene...");
    _director->popScene();
}