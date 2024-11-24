#ifndef _SECOND_SCENE_HPP
#define _SECOND_SCENE_HPP

#include "axmol.h"

class TemplateScene : public ax::Scene
{
public:
    bool init() override;
    void SetTitle(std::string title);
    ax::Size visibleSize;
    ax::Vec2 origin;
    ax::Rect safeArea;
    ax::Vec2 safeOrigin;
private:
    ax::Label* label;
};

#endif  // _SECOND_SCENE_HPP