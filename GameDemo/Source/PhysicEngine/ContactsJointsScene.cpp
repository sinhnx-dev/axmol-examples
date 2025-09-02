#include "ContactsJointsScene.hpp"
#include "Scenes/PopSceneMenu.hpp"

USING_NS_AX;

bool ContactsJointsScene::init()
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

    auto label = Label::createWithTTF("Contacts/Joints Scene", "fonts/Marker Felt.ttf", 24);
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
    // sprite->setScale(0.3f);
    edgeNode->addChild(sprite);
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(false);
    sprite->addComponent(physicsBody);

    auto sprite2 = Sprite::create("HelloWorld.png");
    sprite2->setPosition(Vec2(-200, 200));
    sprite2->setScale(0.3f);
    edgeNode->addChild(sprite2);
    auto physicsBody2 = PhysicsBody::createBox(sprite2->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody2->setDynamic(true);
    sprite2->addComponent(physicsBody2);

    // auto joint = PhysicsJointFixed::construct(sprite->getPhysicsBody(), sprite2->getPhysicsBody(), Vec2(0.5f, 0.5f));
    // auto joint = PhysicsJointLimit::construct(sprite->getPhysicsBody(), sprite2->getPhysicsBody(), Vec2(0.5f, 0.5f), Vec2(0.5f, 0.5f), 10, 200);
    // auto joint = PhysicsJointPin::construct(sprite->getPhysicsBody(), sprite2->getPhysicsBody(), Vec2(0.5f, 0.5f));
    auto joint = PhysicsJointDistance::construct(sprite->getPhysicsBody(), sprite2->getPhysicsBody(), Vec2(0.5f, 0.5f), Vec2(0.5f, 0.5f));
    joint->setCollisionEnable(false);
    getPhysicsWorld()->addJoint(joint);

    return true;
}