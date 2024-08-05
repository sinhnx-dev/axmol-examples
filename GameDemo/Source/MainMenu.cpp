#include "MainMenu.h"
#include "AudioAndSfx/AudioSettingScene.h"

USING_NS_AX;

bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Menu::initWithArray(getMenuItems()))
    {
        return false;
    }
    return true;
}

ax::MenuItemImage* MainMenu::getMenuItem(Vec2 postiton, float scale, const char* labelText, Vec2 labelPosition)
{
    auto mi = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
                                    "res/ButtonsText/ButtonText_Small_Orange_Square.png");
    mi->setPosition(postiton);
    mi->setScale(scale);
    auto lbl = Label::Label::createWithTTF(labelText, "fonts/Ignotum Regular.ttf", 48);
    lbl->setPosition(labelPosition);
    mi->addChild(lbl);
    return mi;
}
ax::MenuItemImage* MainMenu::getMenuItem(Vec2 postiton,
                                         float scale,
                                         const char* labelText,
                                         Vec2 labelPosition,
                                         const ax::ccMenuCallback& callback)
{
    auto mi = getMenuItem(postiton, scale, labelText, labelPosition);
    mi->setCallback(callback);
    return mi;
}

ax::Vector<ax::MenuItem*> MainMenu::getMenuItems()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    // creating a Menu from a Vector of items
    ax::Vector<ax::MenuItem*> menuItems;

    // first menu item image (0, 0)
    auto mi00 = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
                                      "res/ButtonText_Small_Orange_Square.png",
                                      [&](Ref* sender) { Director::getInstance()->end(); });
    // auto mi00 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ButtonText_Small_Green_Square.png"),
    // Sprite::createWithSpriteFrameName("ButtonText_Small_Orange_Square.png"),
    //                                   [&](Ref* sender) { Director::getInstance()->end(); });
    auto miScale = (visibleSize.width / 6) / mi00->getContentSize().width;
    auto miStartPosition =
        Vec2(visibleSize.width - mi00->getContentSize().width * miScale * 5, (visibleSize.height) * 7 / 8.8);
    auto lblPosition = Vec2(mi00->getContentSize().width / 2, mi00->getContentSize().height / 2);
    auto xMove       = mi00->getContentSize().width * miScale;
    auto yMove       = -mi00->getContentSize().height * miScale;
    auto lbl00       = Label::createWithTTF("Sprite demo", "fonts/Ignotum Regular.ttf", 48);
    lbl00->setPosition(lblPosition);
    mi00->addChild(lbl00);
    mi00->setScale(miScale);
    mi00->setPosition(miStartPosition);
    menuItems.pushBack(mi00);

    // menu item image (1, 0)
    // auto mi10 = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
    // "res/ButtonText_Small_Orange_Square.png",
    //                                   [&](Ref* sender) { Director::getInstance()->end(); });
    auto mi10 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ButtonText_Small_Green_Square.png"),
                                       Sprite::createWithSpriteFrameName("ButtonText_Small_Orange_Square.png"),
                                       [&](Ref* sender) { Director::getInstance()->end(); });
    mi10->setPosition(miStartPosition + Vec2(xMove * 1, yMove * 0));
    mi10->setScale(miScale);
    auto lbl10 = Label::Label::createWithTTF("Scene demo", "fonts/Ignotum Regular.ttf", 48);
    lbl10->setPosition(lblPosition);
    mi10->addChild(lbl10);
    menuItems.pushBack(mi10);

    // menu item image (2, 0)
    auto mi20 = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
                                      "res/ButtonText_Small_Orange_Square.png",
                                      [&](Ref* sender) { Director::getInstance()->end(); });
    mi20->setPosition(miStartPosition + Vec2(xMove * 2, yMove * 0));
    mi20->setScale(miScale);
    auto lbl20 = Label::Label::createWithTTF("Item 20", "fonts/Ignotum Regular.ttf", 48);
    lbl20->setPosition(lblPosition);
    mi20->addChild(lbl20);
    menuItems.pushBack(mi20);

    // menu item image (3, 0)
    auto mi30 = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
                                      "res/ButtonsText/ButtonText_Small_Orange_Square.png",
                                      [&](Ref* sender) { Director::getInstance()->end(); });
    mi30->setPosition(miStartPosition + Vec2(xMove * 3, yMove * 0));
    mi30->setScale(miScale);
    auto lbl30 = Label::Label::createWithTTF("Item 30", "fonts/Ignotum Regular.ttf", 48);
    lbl30->setPosition(lblPosition);
    mi30->addChild(lbl30);
    menuItems.pushBack(mi30);

    // menu item image (4, 0)
    auto mi40 = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
                                      "res/ButtonText_Small_Orange_Square.png",
                                      [&](Ref* sender) { Director::getInstance()->end(); });
    mi40->setPosition(miStartPosition + Vec2(xMove * 4, yMove * 0));
    mi40->setScale(miScale);
    auto lbl40 = Label::Label::createWithTTF("Item 40", "fonts/Ignotum Regular.ttf", 48);
    lbl40->setPosition(lblPosition);
    mi40->addChild(lbl40);
    menuItems.pushBack(mi40);

    // menu item image (0, 1)
    auto mi01 =
        getMenuItem(miStartPosition + Vec2(xMove * 0, yMove * 1), miScale, "Audio, checkbox and Slider", lblPosition);
    // mi01->setCallback([&](Ref* sender) { _director->end(); });
    menuItems.pushBack(mi01);
    (menuItems.at(menuItems.size() - 1))->setCallback([&](Ref* sender) { Director::getInstance()->end(); });

    // menu item image (1, 1)
    menuItems.pushBack(getMenuItem(miStartPosition + Vec2(xMove * 1, yMove * 1), miScale, "Audio Settings", lblPosition,
                                   [&](Ref* sender) {
        Director::getInstance()->end();
        // create a scene. it's an autorelease object
        auto audioScene = utils::createInstance<AudioSettingScene>();
        // run
        // Director::getInstance()->runWithScene(audioScene);
        Director::getInstance()->replaceScene(audioScene);
        // Director::getInstance()->replaceScene(TransitionZoomFlipX::create(2, audioScene)); // -> ERROR?
        // Director::getInstance()->pushScene(audioScene); // -> ERROR?

        log("Audio Settings Scene !");
    }));
    // menu item image (2, 1)
    menuItems.pushBack(getMenuItem(miStartPosition + Vec2(xMove * 2, yMove * 1), miScale, "Menu 21", lblPosition,
                                   [&](Ref* sender) { Director::getInstance()->end(); }));
    // menu item image (3, 1)
    menuItems.pushBack(getMenuItem(miStartPosition + Vec2(xMove * 3, yMove * 1), miScale, "Menu 31", lblPosition,
                                   [&](Ref* sender) { Director::getInstance()->end(); }));
    // menu item image (4, 1)
    menuItems.pushBack(getMenuItem(miStartPosition + Vec2(xMove * 4, yMove * 1), miScale, "Menu 41", lblPosition,
                                   [&](Ref* sender) { Director::getInstance()->end(); }));
    return menuItems;
}