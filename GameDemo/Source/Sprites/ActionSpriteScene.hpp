#ifndef _ACTION_SPRITE_SCENE_HPP
#define _ACTION_SPRITE_SCENE_HPP

#include "axmol.h"
#include <string>

class ActionSpriteScene : public ax::Scene
{
public:
    bool init() override;

private:
    ax::Sprite* createSprite(std::string label, ax::Vec2 position);
};

#endif  // _ACTION_SPRITE_SCENE_HPP