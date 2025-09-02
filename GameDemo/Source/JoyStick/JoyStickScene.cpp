#include "JoystickScene.hpp"

USING_NS_AX;

bool JoystickScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("JoyStick Demo");

    this->joystick = Joystick::create(Vec2(150, 150));
    this->addChild(joystick);

    this->player = Sprite::create("HelloWorld.png");
    this->player->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    this->addChild(this->player);

    this->scheduleUpdate();

    return true;
}
void JoystickScene::update(float dt)
{
    if (this->joystick->getIsActive())
    {
        this->player->setRotation(this->joystick->getDirection());

        float angl   = this->joystick->getDirection();
        float length = this->joystick->getIntensity() * 0.05;
        float spf    = _director->getSecondsPerFrame();

        float rad = AX_DEGREES_TO_RADIANS(0);
        if (angl < 90)
            rad = AX_DEGREES_TO_RADIANS(angl - 90);
        else if (angl < 180)
            rad = AX_DEGREES_TO_RADIANS(angl + 90);
        else if (angl < 270)
            rad = AX_DEGREES_TO_RADIANS(angl - 90);
        else if (angl < 360)
            rad = AX_DEGREES_TO_RADIANS(angl + 90);
        auto move = MoveBy::create(spf, Vec2(cos(rad) * length, sin(rad) * length));

        this->player->runAction(move);
    }
}