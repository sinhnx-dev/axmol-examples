#include "GameInfoLayer.hpp"

USING_NS_AX;

bool GameInfoLayer::init()
{
  if (Layer::init())
  {
    Size winSize = Director::getInstance()->getWinSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    AXLOG("%lf, %lf", winSize.width, winSize.height);
    _label = Label::createWithTTF("Items: 0", "fonts/Marker Felt.ttf", 24);
    _label->setColor(Color3B::BLACK);
    int margin = 10;
    _label->setPosition(Vec2(
        origin.x + winSize.width - _label->getContentSize().width / 2,
        origin.x + _label->getContentSize().height / 2 + margin));

    this->addChild(_label);
  }
}
void GameInfoLayer::numCollectedChanged(int numCollected)
{
  _label->setString(StringUtils::format("Items: %d", numCollected));
}