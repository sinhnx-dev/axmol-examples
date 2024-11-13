#ifndef _EVENT_DISPATCH_SCENE_HPP
#define _EVENT_DISPATCH_SCENE_HPP

#include "axmol.h"

class EventDispatchScene : public ax::Scene
{
public:
    bool init() override;

    // Mouse Events
    void onMouseDown(ax::Event* event);
    void onMouseUp(ax::Event* event);
    void onMouseMove(ax::Event* event);
    void onMouseScroll(ax::Event* event);
private:
    ax::Label* _lblMouseInfo;
};

#endif  // _EVENT_DISPATCH_SCENE_HPP
