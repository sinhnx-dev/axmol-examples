#ifndef _EVENT_DISPATCH_SCENE_HPP
#define _EVENT_DISPATCH_SCENE_HPP

#include "axmol.h"
#include "Scenes/TemplateScene.hpp"

class EventDispatchScene : public TemplateScene
{
public:
    bool init() override;

    // Mouse Events
    bool onMouseDown(ax::Event* event);
    bool onMouseUp(ax::Event* event);
    bool onMouseMove(ax::Event* event);
    bool onMouseScroll(ax::Event* event);
private:
    ax::Label* _lblMouseInfo;
};

#endif  // _EVENT_DISPATCH_SCENE_HPP
