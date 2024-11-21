#include "ParallaxNodeScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool ParallaxNodeScene::init()
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

    auto menu = utils::createInstance<PopSceneMenu>();
    if (menu != nullptr)
    {
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    
    setParallaxNode();
    // setParallaxInfinity();

    return true;
}

void ParallaxNodeScene::setParallaxNode()
{

    // create ParallaxNode
    paraNode = utils::createInstance<ParallaxNode>();
    auto bg4 = Sprite::create("res/Parallax/Layer4.png");
    bg4->setAnchorPoint(Vec2(0, 0));
    bg4->setScale(1.5);
    paraNode->addChild(bg4, -4, Vec2(1.0f, 0.5f), Vec2::ZERO);

    //
    auto bg3 = Sprite::create("res/Parallax/Layer3.png");
    bg3->setAnchorPoint(Vec2(0, 0));
    bg3->setScale(1.5);
    paraNode->addChild(bg3, -3, Vec2(2.0f, 2.5f), Vec2::ZERO);
    //
    auto bg2 = Sprite::create("res/Parallax/Layer2.png");
    bg2->setAnchorPoint(Vec2(0, 0));
    bg2->setScale(1.5);
    paraNode->addChild(bg2, -2, Vec2(3.0f, 1.0f), Vec2::ZERO);

    //
    auto bg1 = Sprite::create("res/Parallax/Layer1.png");
    bg1->setAnchorPoint(Vec2(0, 0));
    bg1->setScale(1.5);
    paraNode->addChild(bg1, -1, Vec2(4.0f, 0.5f), Vec2::ZERO);

    auto moveLeft  = MoveBy::create(5, Vec2(-50, 0));
    auto moveRight = moveLeft->reverse();
    auto seq       = Sequence::create(moveLeft, moveRight, nullptr);
    paraNode->runAction((RepeatForever::create(seq)));

    this->addChild(paraNode);
}

void ParallaxNodeScene::setParallaxInfinity()
{
    auto bg41 = Sprite::create("res/Parallax/Layer4.png");
    bg41->setAnchorPoint(Vec2(0, 0));
    bg41->setScale(1.5);
    paraNode->addChild(bg41, -4, Vec2(1.0f, 0.0f), Vec2::ZERO);
    auto bg42 = Sprite::create("res/Parallax/Layer4.png");
    bg42->setAnchorPoint(Vec2(0, 0));
    bg42->setScale(1.5);
    paraNode->addChild(bg42, -4, Vec2(1.0f, 0.0f), Vec2(bg42->getContentSize().width * 1.5, 0));

    //
    auto bg31 = Sprite::create("res/Parallax/Layer3.png");
    bg31->setAnchorPoint(Vec2(0, 0));
    bg31->setScale(1.5);
    paraNode->addChild(bg31, -3, Vec2(2.0f, 0.0f), Vec2::ZERO);
    auto bg32 = Sprite::create("res/Parallax/Layer3.png");
    bg32->setAnchorPoint(Vec2(0, 0));
    bg32->setScale(1.5);
    paraNode->addChild(bg32, -3, Vec2(2.0f, 0.0f), Vec2(bg32->getContentSize().width * 1.5, 0));
    //
    auto bg21 = Sprite::create("res/Parallax/Layer2.png");
    bg21->setAnchorPoint(Vec2(0, 0));
    bg21->setScale(1.5);
    paraNode->addChild(bg21, -2, Vec2(3.0f, 0.0f), Vec2::ZERO);
    auto bg22 = Sprite::create("res/Parallax/Layer2.png");
    bg22->setAnchorPoint(Vec2(0, 0));
    bg22->setScale(1.5);
    paraNode->addChild(bg22, -2, Vec2(3.0f, 0.0f), Vec2(bg22->getContentSize().width * 1.5, 0));

    //
    auto bg11 = Sprite::create("res/Parallax/Layer1.png");
    bg11->setAnchorPoint(Vec2(0, 0));
    bg11->setScale(1.5);
    paraNode->addChild(bg11, -1, Vec2(4.0f, 0.0f), Vec2::ZERO);
    auto bg12 = Sprite::create("res/Parallax/Layer1.png");
    bg12->setAnchorPoint(Vec2(0, 0));
    bg12->setScale(1.5);
    paraNode->addChild(bg12, -1, Vec2(4.0f, 0.0f), Vec2(bg12->getContentSize().width * 1.5, 0));

    auto moveLeft  = MoveBy::create(20, Vec2(-(bg12->getContentSize().width * 1.5 / 4), 0));
    auto moveRight = MoveBy::create(0, Vec2((bg12->getContentSize()).width * 1.5 / 4, 0));
    auto seq       = Sequence::create(moveLeft, moveRight, nullptr);

    paraNode->runAction((RepeatForever::create(seq)));
}