#ifndef _SECOND_SCENE_HPP
#define _SECOND_SCENE_HPP

#include "axmol.h"

class SecondScene : public ax::Scene
{
public:
    bool init() override;

private:
    void backScene(ax::Object* sender);
};

#endif  // _SECOND_SCENE_HPP