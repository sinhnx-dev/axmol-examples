#include "PopSceneMenu.hpp"

USING_NS_AX;

bool PopSceneMenu::init()
{
    //////////////////////////////
    // 1. super init first
    _director        = Director::getInstance();
    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    auto backItem = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
                                           Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
                                           AX_CALLBACK_1(PopSceneMenu::menuItemPopScene, this));
    if (backItem == nullptr || backItem->getContentSize().width <= 0 || backItem->getContentSize().height <= 0)
    {
        AXLOG("error load image");
        return false;
    }
    float scale = 0.5;
    backItem->setScale(scale);
    float x = safeOrigin.x + safeArea.size.width - backItem->getContentSize().width / 2 * scale;
    float y = safeOrigin.y + backItem->getContentSize().height / 2 * scale;
    backItem->setPosition(Vec2(x, y));
    _menuItems.pushBack(backItem);
    if (!Menu::initWithArray(_menuItems))
    {
        return false;
    }
    this->setPosition(Vec2::ZERO);

    return true;
}

void PopSceneMenu::menuItemPopScene(ax::Object* sender)
{
    _director->popScene();
    AXLOG("Pop Scene run.");
}