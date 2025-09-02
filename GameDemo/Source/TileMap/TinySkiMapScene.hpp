#ifndef _TINY_SKIMAP_SCENE_HPP
#define _TINY_SKIMAP_SCENE_HPP

#include "axmol.h"
#include "Scenes/TemplateScene.hpp"

class TinySkiMapScene : public TemplateScene
{
public:
    bool init() override;

private:
    ax::TMXTiledMap* _tileMap;
};

#endif  // _TINY_SKIMAP_SCENE_HPP