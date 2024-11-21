#ifndef _FILTERING_COLLISIONS_SCENE_HPP
#define _FILTERING_COLLISIONS_SCENE_HPP

#include "axmol.h"

class FilteringCollisionsScene : public ax::Scene
{
public:
    bool init() override;

private:
    ax::Sprite* addSpriteAtPosition(ax::Vec2 position);
};

#endif  // _FILTERING_COLLISIONS_SCENE_HPP