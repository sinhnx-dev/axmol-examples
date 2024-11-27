#ifndef _JOYSTICK_HPP_
#define _JOYSTICK_HPP_

#include "axmol.h"

class Joystick : public ax::Node
{

public:
    static Joystick* create(ax::Point pos);
    void setOnActiveChange(const std::function<void()>& func);
    float getDirection() const;
    bool getIsActive() const;
    void setJoystickRadius(float radius);
    float getIntensity();

private:
    virtual bool init();

    void onTouchesMoved(const std::vector<ax::Touch*>& touches, ax::Event* event);
    void onTouchesBegan(const std::vector<ax::Touch*>& touches, ax::Event* event);
    void onTouchesEnded(const std::vector<ax::Touch*>& touches, ax::Event* event);

    void setIsActive(bool active);

    std::function<void()> _onActiveChange;

    void joystickBoundaryUpdate();

    ax::Point _mainPosition;
    ax::Sprite* _joystickSprite = nullptr;
    ax::Sprite* _bgSprite       = nullptr;

    float _radiusSq           = 16000.0f;
    int _touchToTrack         = 0;
    bool _isActive            = false;
    bool _didSetChangeCommand = false;
};

#endif /* _JOYSTICK_HPP_ */