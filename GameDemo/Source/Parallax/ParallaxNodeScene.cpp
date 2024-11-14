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

    // create ParallaxNode
    auto paraNode = utils::createInstance<ParallaxNode>();

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

    auto moveLeft   = MoveBy::create(5, Vec2(-50, 0));
    auto moveRight = moveLeft->reverse();
    auto seq    = Sequence::create(moveLeft, moveRight, nullptr);
    paraNode->runAction((RepeatForever::create(seq)));

    this->addChild(paraNode);

    return true;
}