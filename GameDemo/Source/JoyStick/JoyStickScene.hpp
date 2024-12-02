#ifndef _JOY_STICK_SCENE_HPP_
#define _JOY_STICK_SCENE_HPP_

#include "axmol.h"
#include "Joystick.hpp"
#include "../Scenes/TemplateScene.hpp"

class JoystickScene : public TemplateScene
{
public:
    bool init() override;

private:
    Joystick* joystick;
    ax::Sprite* player;
    void update(float dt) override;
};

#endif  // _JOY_STICK_SCENE_HPP_