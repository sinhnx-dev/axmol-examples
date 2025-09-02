#include "VideoPlayerScene.hpp"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"

USING_NS_AX;

bool VideoPlayerScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("Video Player");

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

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