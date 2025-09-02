#ifndef _PARALLAX_NODE_SCENE_HPP
#define _PARALLAX_NODE_SCENE_HPP

#include "axmol.h"
#include "Scenes/TemplateScene.hpp"

class ParallaxNodeScene : public TemplateScene
{
public:
    bool init() override;

    // void update(float delta) override;
private:
   ax::ParallaxNode* paraNode;
   void setParallaxNode();
   void setParallaxInfinity();
};

#endif  // _PARALLAX_NODE_SCENE_HPP
