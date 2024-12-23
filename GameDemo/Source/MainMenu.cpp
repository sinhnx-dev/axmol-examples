#include "MainMenu.h"

#include "Particles/BuiltInParticleScene.hpp"
#include "Particles/CustomParticleScene.hpp"
#include "Particles/EffekseerPraticleScene.hpp"
#include "Particles/PraticleToolScene.hpp"

#include "Parallax/ParallaxNodeScene.hpp"
#include "Parallax/ParallaxInfiniteScene.hpp"

#include "Sprites/BasicSpriteScene.hpp"
#include "Sprites/ActionSpriteScene.hpp"

#include "Scenes/FirstScene.hpp"

#include "GameUI/LabelDemoScene.hpp"
#include "GameUI/UiComponentsScene.hpp"
#include "GameUI/VideoPlayerScene.hpp"

#include "Events/EventDispatchScene.hpp"

#include "TileMap/TileMapScene.hpp"
#include "TileMap/TinySkiMapScene.hpp"

#include "PhysicEngine/PhysicWorldScene.hpp"
#include "PhysicEngine/FilteringCollisionsScene.hpp"
#include "PhysicEngine/CollisionDetectionScene.hpp"
#include "PhysicEngine/ContactsJointsScene.hpp"

#include "AudioEngine/AudioSettingScene.hpp"

#include "WorkingWithData/HighScoreScene.hpp"
#include "WorkingWithData/CsvHighScoreScene.hpp"
#include "WorkingWithData/SqliteHighScoreScene.hpp"
#include "WorkingWithData/XmlHighScoreScene.hpp"
#include "WorkingWithData/JsonHighScoreScene.hpp"

#include "Joystick/JoystickScene.hpp"

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

// ax::MenuItemImage* MainMenu::getMenuItem(Vec2 postiton, float scale, const char* labelText, Vec2 labelPosition)
// {
//     auto mi = MenuItemImage::create("res/ButtonsText/ButtonText_Small_Green_Square.png",
//                                     "res/ButtonsText/ButtonText_Small_Orange_Square.png");
//     mi->setPosition(postiton);
//     mi->setScale(scale);
//     auto lbl = Label::Label::createWithTTF(labelText, "fonts/Ignotum Regular.ttf", 48);
//     lbl->setPosition(labelPosition);
//     mi->addChild(lbl);
//     return mi;
// }
ax::MenuItemSprite* MainMenu::getMenuItemSprite(Vec2 postiton, float scale, const char* labelText, Vec2 labelPosition)
{
    auto mi = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ButtonText_Small_Green_Square.png"),
                                     Sprite::createWithSpriteFrameName("ButtonText_Small_Orange_Square.png"), nullptr);
    mi->setPosition(postiton);
    mi->setScale(scale);
    auto lbl = Label::Label::createWithTTF(labelText, "fonts/Ignotum Regular.ttf", 32);
    lbl->setPosition(labelPosition);
    mi->addChild(lbl);
    return mi;
}
ax::MenuItemSprite* MainMenu::getMenuItemSprite(Vec2 postiton,
                                                float scale,
                                                const char* labelText,
                                                Vec2 labelPosition,
                                                const ax::ccMenuCallback& callback)
{

    auto mi = getMenuItemSprite(postiton, scale, labelText, labelPosition);
    mi->setCallback(callback);
    return mi;
}
// ax::MenuItemImage* MainMenu::getMenuItem(Vec2 postiton,
//                                          float scale,
//                                          const char* labelText,
//                                          Vec2 labelPosition,
//                                          const ax::ccMenuCallback& callback)
// {
//     auto mi = getMenuItem(postiton, scale, labelText, labelPosition);
//     mi->setCallback(callback);
//     return mi;
// }

ax::Vector<ax::MenuItem*> MainMenu::getMenuItems()
{
    auto visibleSize = Director::getInstance()->getVisibleSize();
    // creating a Menu from a Vector of items
    ax::Vector<ax::MenuItem*> menuItems;

    // first menu item image (0, 0)
    auto mi00 =
        MenuItemSprite::create(Sprite::createWithSpriteFrameName("ButtonText_Small_Green_Square.png"),
                               Sprite::createWithSpriteFrameName("ButtonText_Small_Orange_Square.png"), nullptr);
    auto miScale = (visibleSize.width / 6) / mi00->getContentSize().width;
    auto miStartPosition =
        Vec2(visibleSize.width - mi00->getContentSize().width * miScale * 5, (visibleSize.height) * 7 / 8.8);
    auto lblPosition = Vec2(mi00->getContentSize().width / 2, mi00->getContentSize().height / 2);
    auto xMove       = mi00->getContentSize().width * miScale;
    auto yMove       = -mi00->getContentSize().height * miScale;
    auto lbl00       = Label::createWithTTF("Sprite demo", "fonts/Ignotum Regular.ttf", 32);
    lbl00->setPosition(lblPosition);
    mi00->addChild(lbl00);
    mi00->setScale(miScale);
    mi00->setPosition(miStartPosition);
    mi00->setCallback([&](ax::Object*) {
        AXLOG("Basic Sprite Scene !");
        auto basicSpriteScene = utils::createInstance<BasicSpriteScene>();
        Director::getInstance()->pushScene(TransitionZoomFlipY::create(2, basicSpriteScene));
    });
    menuItems.pushBack(mi00);

    // menu item image (1, 0)
    auto mi10 = MenuItemSprite::create(Sprite::createWithSpriteFrameName("ButtonText_Small_Green_Square.png"),
                                       Sprite::createWithSpriteFrameName("ButtonText_Small_Orange_Square.png"),
                                       [&](ax::Object*) {
        AXLOG("Action Sprite Scene !");
        auto actionSpriteScene = utils::createInstance<ActionSpriteScene>();
        Director::getInstance()->replaceScene(actionSpriteScene);
    });
    mi10->setPosition(miStartPosition + Vec2(xMove * 1, yMove * 0));
    // mi10->setScale(miScale);
    auto lbl10 = Label::Label::createWithTTF("Sprite Action", "fonts/Ignotum Regular.ttf", 48);
    lbl10->setPosition(lblPosition);
    mi10->addChild(lbl10);

    // menu item image (1, 0)
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 1, yMove * 0), miScale, "Sprite Action",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Sprite Action Scene !");
        auto scene = utils::createInstance<ActionSpriteScene>();
        Director::getInstance()->pushScene(scene);
    }));
    // menu item image (2, 0)
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 2, yMove * 0), miScale, "Scene Demo",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Scene Demo!");
        auto firstScene = utils::createInstance<FirstScene>();
        Director::getInstance()->pushScene(firstScene);
    }));
    // menu item image (3, 0)
    auto mi01 = getMenuItemSprite(miStartPosition + Vec2(xMove * 3, yMove * 0), miScale, "Label Demo", lblPosition);
    menuItems.pushBack(mi01);
    (menuItems.at(menuItems.size() - 1))->setCallback([&](ax::Object*) {
        AXLOG("Label Demo Scene !");
        auto scene = utils::createInstance<LabelDemoScene>();
        Director::getInstance()->pushScene(TransitionZoomFlipX::create(2, scene));
    });
    // menu item image (4, 0)
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 4, yMove * 0), miScale, "UI Components",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("UI Components Scene !");
        auto scene = utils::createInstance<UiComponentsScene>();
        Director::getInstance()->pushScene(scene);
    }));

    // menu item row 1
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 0, yMove * 1), miScale, "EventDepatch",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("EventDepatch Scene !");
        auto scene = utils::createInstance<EventDispatchScene>();
        Director::getInstance()->pushScene(TransitionZoomFlipY::create(2, scene));
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 1, yMove * 1), miScale, "Built In Praticle",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Built-In Praticle Scene !");
        auto builtInScene = utils::createInstance<BuiltInParticleScene>();
        Director::getInstance()->pushScene(TransitionZoomFlipY::create(2, builtInScene));
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 2, yMove * 1), miScale, "Custom Praticle",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Custom Praticle Scene !");
        auto builtInScene = utils::createInstance<CustomParticleScene>();
        Director::getInstance()->pushScene(TransitionZoomFlipY::create(2, builtInScene));
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 3, yMove * 1), miScale, "Praticle Tool",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Praticle Tool Scene !");
        auto scene = utils::createInstance<PraticleToolScene>();
        Director::getInstance()->pushScene(TransitionZoomFlipY::create(2, scene));
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 4, yMove * 1), miScale, "Parallax Infinite", lblPosition,
                                         [&](ax::Object*) {
        AXLOG("ParallaxInfiniteScene Scene !");
        auto scene = utils::createInstance<ParallaxInfiniteScene>();
        Director::getInstance()->pushScene(scene);
    }));

    //menu item row 2
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 0, yMove * 2), miScale, "ParalaxNode", lblPosition,
                                         [&](ax::Object*) {
        AXLOG("ParalaxNode !");
        auto scene = utils::createInstance<ParallaxNodeScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 1, yMove * 2), miScale, "Tile Map", lblPosition,
                                         [&](ax::Object*) {
        AXLOG("Tile Map Scene !");
        // auto scene = utils::createInstance<TileMapScene>();
        auto scene = utils::createInstance<TinySkiMapScene>();
        Director::getInstance()->pushScene(scene);
    }));
    
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 2, yMove * 2), miScale, "Video Player", lblPosition,
                                         [&](ax::Object*) {
        AXLOG("VideoPlayer Scene !");
        auto scene = utils::createInstance<VideoPlayerScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 3, yMove * 2), miScale, "???", lblPosition,
                                         [&](ax::Object*) {
        AXLOG("?? Scene !");
        auto scene = utils::createInstance<VideoPlayerScene>();
        Director::getInstance()->pushScene(scene);
    }));

    //row 3
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 0, yMove * 3), miScale, "Physic Engine",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Physic Engine Scene !");
        auto audioScene = utils::createInstance<PhysicWorldScene>();
        Director::getInstance()->pushScene(audioScene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 1, yMove * 3), miScale, "Filtering Collisions",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Filtering Collisions");
        auto scene = utils::createInstance<FilteringCollisionsScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 2, yMove * 3), miScale, "Collision Detection",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Collision Detection");
        auto scene = utils::createInstance<CollisionDetectionScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 3, yMove * 3), miScale, "Contacts/Joints",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("ContactsJointsScene");
        auto scene = utils::createInstance<ContactsJointsScene>();
        Director::getInstance()->pushScene(scene);
    }));
    

    // row 4
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 0, yMove * 4), miScale, "Audio Settings",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Audio Settings Scene !");
        auto audioScene = utils::createInstance<AudioSettingScene>();
        Director::getInstance()->pushScene(audioScene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 1, yMove * 4), miScale, "Joystick",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("JoyStick Scene !");
        auto scene = utils::createInstance<JoystickScene>();
        Director::getInstance()->pushScene(scene);
    }));
    
    // row 5
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 0, yMove * 5), miScale, "Csv High Scores",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("Csv High Scores Scene!");
        auto scene = utils::createInstance<CsvHighScoreScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 1, yMove * 5), miScale, "Sqlite High Scores",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("SQLite High Scores Scene!");
        auto scene = utils::createInstance<SqliteHighScoreScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 2, yMove * 5), miScale, "XML High Scores",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("XML High Scores Scene!");
        auto scene = utils::createInstance<XmlHighScoreScene>();
        Director::getInstance()->pushScene(scene);
    }));
    menuItems.pushBack(getMenuItemSprite(miStartPosition + Vec2(xMove * 3, yMove * 5), miScale, "JSON High Scores",
                                         lblPosition, [&](ax::Object*) {
        AXLOG("JSON High Scores Scene!");
        auto scene = utils::createInstance<JsonHighScoreScene>();
        Director::getInstance()->pushScene(scene);
    }));

    return menuItems;
}