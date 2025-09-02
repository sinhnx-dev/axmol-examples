#ifndef _PARALLAX_SCENE_HPP
#define _PARALLAX_SCENE_HPP

#include "axmol.h"
#include "ParallaxInfiniteNode.hpp"
#include "Scenes/TemplateScene.hpp"

USING_NS_AX;

class ParallaxInfiniteScene : public TemplateScene
{
    float m_speed;

public:
    // static cocos2d::Scene* createScene();
    bool init() override;
    void update(float delta) override;

    void accellerometerCallback(Acceleration* acceleration, Event* event);
};

#endif /* _PARALLAX_SCENE_HPP */
