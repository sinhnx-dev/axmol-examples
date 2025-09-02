#include "TemplateScene.hpp"
#include "PopSceneMenu.hpp"

USING_NS_AX;

bool TemplateScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }
    visibleSize = _director->getVisibleSize();
    _lblTitle = Label::createWithTTF("Template Scene", "fonts/Marker Felt.ttf", 24);
    if (_lblTitle == nullptr)
    {
        AXLOG("can't load font'fonts/Marker Felt.ttf'");
    }
    else
    {
        _lblTitle->setPosition(
            Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - _lblTitle->getContentSize().height));
        this->addChild(_lblTitle, 1);
    }

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

void TemplateScene::setTitle(std::string title)
{
    _lblTitle->setString(title);
}