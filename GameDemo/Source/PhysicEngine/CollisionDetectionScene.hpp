#ifndef _COLLISION_DETECTION_SCENE_HPP
#define _COLLISION_DETECTION_SCENE_HPP

#include "axmol.h"

class CollisionDetectionScene : public ax::Scene
{
public:
    bool init() override;

private:
    ax::Label* label;
    ax::Vec2 visibleSize;
    ax::Node* edgeNode;
    
    bool onContactBegin(ax::PhysicsContact& contact);
    ax::Sprite* addSpriteAtPosition(ax::Vec2 position);
    void tickAndAddSprite(float dt);
};

#endif  // _COLLISION_DETECTION_SCENE_HPP