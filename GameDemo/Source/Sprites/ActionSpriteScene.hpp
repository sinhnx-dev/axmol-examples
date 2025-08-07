#ifndef _ACTION_SPRITE_SCENE_HPP
#define _ACTION_SPRITE_SCENE_HPP

#include "Scenes/TemplateScene.hpp"
#include <string>

class ActionSpriteScene : public TemplateScene
{
public:
    bool init() override;

private:
    ax::Sprite* createSprite(std::string label, ax::Vec2 position);
};

#endif  // _ACTION_SPRITE_SCENE_HPP