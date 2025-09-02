#include "ActionSpriteScene.hpp"

USING_NS_AX;

bool ActionSpriteScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("Sprite Action");
    
    auto sprite1 = createSprite("Move by", Vec2(100, visibleSize.height - 50));
    this->addChild(sprite1);
    // Move a sprite 100 pixels to the right & 10 pixels to the top over 2 seconds
    auto moveBy = MoveBy::create(2, Vec2(300, 0));
    sprite1->runAction(moveBy);

    auto sprite2 = createSprite("Move to", Vec2(100, visibleSize.height - 50));
    this->addChild(sprite2);
    // Move a sprite 100 pixels to the right & 10 pixels to the top over 2 seconds
    auto moveTo = MoveTo::create(2, Vec2(300, 0));
    sprite2->runAction(moveTo);

    auto sprite3 = createSprite("sequences", Vec2(110, visibleSize.height - 150));
    this->addChild(sprite3);
    // create a delay
    auto delay = DelayTime::create(1);
    sprite3->runAction(Sequence::create(MoveBy::create(2, Vec2(200, 0)), delay, MoveBy::create(2, Vec2(0, -200)), nullptr));

    auto sprite4 = createSprite("Spawn", Vec2(110, visibleSize.height - 150));
    this->addChild(sprite4);
    sprite4->runAction(Spawn::create(MoveBy::create(2, Vec2(200, 0)), MoveBy::create(2, Vec2(0, -200)), nullptr));

    return true;
}

ax::Sprite* ActionSpriteScene::createSprite(std::string labelText, ax::Vec2 position)
{
    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(position);
    sprite->setScale(0.5);
    auto label = Label::createWithTTF(labelText, "fonts/Ignotum Regular.ttf", 40);
    label->setPosition(Vec2(0, sprite->getContentSize().height - label->getContentSize().height));
    sprite->addChild(label);
    return sprite;
}