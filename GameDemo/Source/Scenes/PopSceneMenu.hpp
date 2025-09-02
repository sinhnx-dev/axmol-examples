#ifndef _POP_SCENE_MENU_HPP
#define _POP_SCENE_MENU_HPP

#include "axmol.h"

class PopSceneMenu : public ax::Menu
{
public:
    bool init() override;

private:
    ax::Director* _director;
    ax::Vector<ax::MenuItem*> _menuItems;
    void menuItemPopScene(ax::Object* sender);
};

#endif  // _POP_SCENE_MENU_HPP
