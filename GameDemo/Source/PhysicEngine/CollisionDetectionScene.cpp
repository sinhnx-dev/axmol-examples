#include "CollisionDetectionScene.hpp"
#include "Scenes/PopSceneMenu.hpp"

USING_NS_AX;

bool CollisionDetectionScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    visibleSize     = _director->getVisibleSize();
    auto origin     = _director->getVisibleOrigin();
    auto safeArea   = _director->getSafeAreaRect();
    auto safeOrigin = safeArea.origin;

    label = Label::createWithTTF("Collision Detection Scene", "fonts/Marker Felt.ttf", 24);
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
    getPhysicsWorld()->setGravity(Vec2(0, -15));
    auto body     = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);
    edgeNode = Node::create();
    edgeNode->setPosition(s_centre);
    edgeNode->setPhysicsBody(body);
    this->addChild(edgeNode);

    // create a sprite
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2::ZERO);
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    physicsBody->setDynamic(false);
    // apply physicsBody to the sprite
    sprite->setTag(10);
    sprite->addComponent(physicsBody);
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
    edgeNode->addChild(sprite);

    // adds contact event listener
    auto contactListener            = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = AX_CALLBACK_1(CollisionDetectionScene::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
    schedule(AX_SCHEDULE_SELECTOR(CollisionDetectionScene::tickAndAddSprite), 0.5f);
    printf("visibleSize: %f, %f\n", visibleSize.width, visibleSize.height);

    return true;
}

bool CollisionDetectionScene::onContactBegin(ax::PhysicsContact& contact)
{
    auto nodeA = contact.getShapeA()->getBody()->getNode();
    auto nodeB = contact.getShapeB()->getBody()->getNode();
    if (nodeA && nodeB)
    {
        if (nodeA->getTag() == 10)
        {
            nodeB->removeFromParentAndCleanup(true);
        }
        else if (nodeB->getTag() == 10)
        {
            AXLOG("nodeA tag=10");
            nodeA->removeFromParentAndCleanup(true);
        }
    }
    // nodeA->removeFromParentAndCleanup(true);
    // nodeB->removeFromParentAndCleanup(true);
    // label->setString("");
    static int no=0;
    no++; 
    AXLOG("onContactBegin: %d", no);
    return true;
}

void CollisionDetectionScene::tickAndAddSprite(float dt)
{
    auto s_centre = Vec2(visibleSize.width / 2, visibleSize.height / 2);
    auto sprite   = addSpriteAtPosition(Vec2(ax::random(-300, 300),ax::random(-300, 300)));
    auto physicsBody = sprite->getPhysicsBody();
    physicsBody->setVelocity(Vec2(ax::random(-300, 300), ax::random(-300, 300)));
    physicsBody->setContactTestBitmask(0xFFFFFFFF);
}
ax::Sprite* CollisionDetectionScene::addSpriteAtPosition(ax::Vec2 position)
{
    printf("position: %f, %f\n", position.x, position.y);
    ax::Sprite* sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(position);
    sprite->setScale(0.5);
    auto physicsBody = PhysicsBody::createBox(sprite->getContentSize(), PhysicsMaterial(0.1f, 1.0f, 0.0f));
    // physicsBody->setDynamic(true);
    sprite->setTag(11);
    edgeNode->addChild(sprite);
    sprite->addComponent(physicsBody);
    return sprite;
}