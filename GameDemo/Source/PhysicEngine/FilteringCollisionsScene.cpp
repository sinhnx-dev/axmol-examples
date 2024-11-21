#include "FilteringCollisionsScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool FilteringCollisionsScene::init()
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

    auto label = Label::createWithTTF("Filtering Collisions Scene", "fonts/Marker Felt.ttf", 24);
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

    auto s_centre = Vec2(visibleSize.width / 2, visibleSize.height / 2);
    this->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_SHAPE);
    getPhysicsWorld()->setGravity(Vec2(0,-100));
    auto body     = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    auto edgeNode = Node::create();
    edgeNode->setPosition(s_centre);
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    auto sprite1 = addSpriteAtPosition(Vec2(s_centre.x - 200, s_centre.y-100));
    sprite1->getPhysicsBody()->setCategoryBitmask(0x02);   // 0010
    sprite1->getPhysicsBody()->setCollisionBitmask(0x01);  // 0001

    auto sprite2 = addSpriteAtPosition(Vec2(s_centre.x - 200, s_centre.y + 200));
    sprite2->getPhysicsBody()->setCategoryBitmask(0x02);   // 0010
    sprite2->getPhysicsBody()->setCollisionBitmask(0x01);  // 0001


    auto sprite3 = addSpriteAtPosition(Vec2(s_centre.x + 200, s_centre.y + 200));
    sprite3->getPhysicsBody()->setCategoryBitmask(0x03);   // 0011
    sprite3->getPhysicsBody()->setCollisionBitmask(0x03);  // 0011

    auto sprite4 = addSpriteAtPosition(Vec2(s_centre.x + 200, s_centre.y-100));
    sprite4->getPhysicsBody()->setCategoryBitmask(0x01);   // 0001
    sprite4->getPhysicsBody()->setCollisionBitmask(0x02);  // 0010

    return true;
}

ax::Sprite* FilteringCollisionsScene::addSpriteAtPosition(ax::Vec2 position)
{
    ax::Sprite* sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(position);
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(true);
    sprite->addComponent(physicsBody);
    this->addChild(sprite);
    return sprite;
}