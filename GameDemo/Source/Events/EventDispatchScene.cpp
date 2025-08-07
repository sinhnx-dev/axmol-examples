#include "EventDispatchScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool EventDispatchScene::init()
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

    auto sprite = Sprite::create("HelloWorld.png");
    if (sprite == nullptr)
    {
        AXLOG("Can't load 'HelloWorld.png' file");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
        // add the sprite as a child to this layer
        this->addChild(sprite, 0);
    }

    _lblMouseInfo = Label::createWithTTF("Mouse Event: ...", "fonts/Marker Felt.ttf", 24);
    _lblMouseInfo->setPosition(Vec2(visibleSize.width / 2, 100));
    this->addChild(_lblMouseInfo);

    //  Create a "one by one" touch event listener (processes one touch at a time)
    auto listener1 = EventListenerTouchOneByOne::create();
    listener1->setSwallowTouches(true);
    // trigger when you push down
    listener1->onTouchBegan = [](Touch* touch, Event* event) {
        AXLOG("onTouchBegan event");
        // AXLOG("%s", typeid(event->getCurrentTarget()).name());
        return true;  // if you are consuming it
    };
    // trigger when moving touch
    listener1->onTouchMoved = [](Touch* touch, Event* event) {
        AXLOG("onTouchMoved event");
        // your code
    };
    // trigger when you let up
    listener1->onTouchEnded = [=](Touch* touch, Event* event) {
        // your code
        AXLOG("onTouchEnded event");
    };
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener1, _lblMouseInfo);

    // Keyboard Events
    auto kbListener           = EventListenerKeyboard::create();
    kbListener->onKeyReleased = [](EventKeyboard::KeyCode keyCode, Event* event) {
        int speed = 10;
        Vec2 loc  = event->getCurrentTarget()->getPosition();
        switch (keyCode)
        {
        case EventKeyboard::KeyCode::KEY_LEFT_ARROW:
        case EventKeyboard::KeyCode::KEY_A:
            event->getCurrentTarget()->setPosition(loc.x - speed, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_RIGHT_ARROW:
        case EventKeyboard::KeyCode::KEY_D:
            event->getCurrentTarget()->setPosition(loc.x + speed, loc.y);
            break;
        case EventKeyboard::KeyCode::KEY_UP_ARROW:
        case EventKeyboard::KeyCode::KEY_W:
            event->getCurrentTarget()->setPosition(loc.x, loc.y + speed);
            break;
        case EventKeyboard::KeyCode::KEY_DOWN_ARROW:
        case EventKeyboard::KeyCode::KEY_S:
            event->getCurrentTarget()->setPosition(loc.x, loc.y - speed);
            break;
        case EventKeyboard::KeyCode::KEY_SPACE:
            AXLOG("Space Key is press");
            break;
        default:
            break;
        }
    };
    // Add listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(kbListener, sprite);

    /* Mouse Event */
    auto _mouseListener           = EventListenerMouse::create();
    _mouseListener->onMouseMove   = AX_CALLBACK_1(EventDispatchScene::onMouseMove, this);
    _mouseListener->onMouseUp     = AX_CALLBACK_1(EventDispatchScene::onMouseUp, this);
    _mouseListener->onMouseDown   = AX_CALLBACK_1(EventDispatchScene::onMouseDown, this);
    _mouseListener->onMouseScroll = AX_CALLBACK_1(EventDispatchScene::onMouseScroll, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(_mouseListener, this);

    /* Custom Listener */
    auto customListener = EventListenerCustom::create("game_custom_event1", [=](EventCustom* event) {
        std::string str("Custom event 1 received, ");
        char* buf = static_cast<char*>(event->getUserData());
        str += buf;
        str += " times";
        // _lblMouseInfo->setString(str.c_str());
        AXLOG("%s", str.c_str());
    });
    _eventDispatcher->addEventListenerWithSceneGraphPriority(customListener, this);

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
bool EventDispatchScene::onMouseDown(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    AXLOG("Mouse Down detected");
    _lblMouseInfo->setString("Mouse Event: onMouseDown");
}

bool EventDispatchScene::onMouseUp(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    AXLOG("Mouse Up detected");

    _lblMouseInfo->setString("Mouse Event: onMouseUp");
    return true;  // if you are consuming it
}

bool EventDispatchScene::onMouseMove(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    AXLOG("Mouse move detected with position: x: %f, y: %f", e->getLocation().x, e->getLocation().y);
    _lblMouseInfo->setString("Mouse Event: onMouseMove");
    return true;  // if you are consuming it
}

bool EventDispatchScene::onMouseScroll(Event* event)
{
    // to illustrate the event....
    EventMouse* e = (EventMouse*)event;
    AXLOG("Mouse Scroll detected with position: x: %f, y: %f", e->getLocation().x, e->getLocation().y);
    _lblMouseInfo->setString("Mouse Event: onMouseScroll");

    // handle EventCustom
    static int count = 0;
    ++count;
    char buf[10];
    snprintf(buf, sizeof(buf), "%d", count);
    EventCustom cevent("game_custom_event1");
    cevent.setUserData(buf);
    _eventDispatcher->dispatchEvent(&cevent);
    return true;  // if you are consuming it
}
