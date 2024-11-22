#include "VideoPlayerScene.hpp"
#include "../PopSceneMenu.hpp"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

USING_NS_AX;

bool VideoPlayerScene::init()
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

    auto label = Label::createWithTTF("Video Player", "fonts/Marker Felt.ttf", 24);
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

    auto videoPlayer = ui::VideoPlayer::create();
    videoPlayer->setURL("https://www.w3schools.com/html/mov_bbb.mp4");
    videoPlayer->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    // videoPlayer->setFullScreenEnabled(true);
    videoPlayer->setContentSize(Size(visibleSize.width*0.8, visibleSize.height*0.8));
    this->addChild(videoPlayer);
    videoPlayer->play();

    auto basicMC = ui::BasicMediaController::create(videoPlayer);
    basicMC->setPosition(Vec2(visibleSize.width/2, 20));
    this->addChild(basicMC);

    return true;
}