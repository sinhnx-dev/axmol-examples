#include "PhysicWorldScene.hpp"
#include "Scenes/PopSceneMenu.hpp"

USING_NS_AX;

bool PhysicWorldScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    auto label = Label::createWithTTF("Physic World", "fonts/Marker Felt.ttf", 24);
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
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto s_centre    = Vec2(visibleSize.width / 2, visibleSize.height / 2);
    auto body        = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode    = Node::create();
    edgeNode->setPosition(s_centre);
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);
    // create a sprite
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2::ZERO);
    edgeNode->addChild(sprite);
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(false);
    // apply physicsBody to the sprite
    sprite->addComponent(physicsBody);
    // add five dynamic bodies
    for (int i = 0; i < 5; ++i)
    {
        sprite = Sprite::create("HelloWorld.png");
        sprite->setPosition(Vec2(Vec2::ZERO.x + ax::random(-300, 300), Vec2::ZERO.y + ax::random(-300, 300)));
        sprite->setScale(0.5f);
        physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
        // set the body isn't affected by the physics world's gravitational force
        physicsBody->setGravityEnable(false);
        // set initial velocity of physicsBody
        physicsBody->setVelocity(Vec2(ax::random(-500, 500), ax::random(-500, 500)));
        physicsBody->setTag(10);
        sprite->addComponent(physicsBody);
        edgeNode->addChild(sprite);
    }

    return true;
}