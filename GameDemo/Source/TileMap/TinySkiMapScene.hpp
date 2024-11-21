#ifndef _TINY_SKIMAP_SCENE_HPP
#define _TINY_SKIMAP_SCENE_HPP

#include "axmol.h"

class TinySkiMapScene : public ax::Scene
{
public:
    bool init() override;

private:
    ax::TMXTiledMap* _tileMap;
};

#endif  // _TINY_SKIMAP_SCENE_HPP