#include "FirstScene.hpp"
#include "SecondScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool FirstScene::init()
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

    auto label = Label::createWithTTF("First Scene", "fonts/Marker Felt.ttf", 24);
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
        MenuItemFont::setFontSize(24);
        auto miNextScene = MenuItemFont::create("Next to Second Scene", AX_CALLBACK_1(FirstScene::nextScene, this));
        miNextScene->setPosition(
            Vec2(safeOrigin.x + safeArea.size.width / 2, visibleSize.height/2));
        menu->addChild(miNextScene);
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    return true;
}

void FirstScene::nextScene(ax::Object* sender)
{
    AXLOG("push scene...");
    auto secondScene = utils::createInstance<SecondScene>();
    _director->pushScene(secondScene);
}