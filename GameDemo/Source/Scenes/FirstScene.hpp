#ifndef _FIRST_SCENE_HPP
#define _FIRST_SCENE_HPP

#include "axmol.h"

class FirstScene : public ax::Scene
{
public:
    bool init() override;

private:
    void nextScene(ax::Object* sender);
};

#endif  // _FIRST_SCENE_HPP