#ifndef __MAIN_MENU_H__
#define __MAIN_MENU_H__

#include "axmol.h"

class MainMenu : public ax::Menu
{
public:
    bool init() override;
    CREATE_FUNC(MainMenu);

private:
    ax::Director* _director;
    ax::Vector<ax::MenuItem*> getMenuItems();
    ax::MenuItemImage* getMenuItem(ax::Vec2 postiton, float scale, const char* labelText, ax::Vec2 labelPosition);
    ax::MenuItemImage* getMenuItem(ax::Vec2 postiton,
                                   float scale,
                                   const char* labelText,
                                   ax::Vec2 labelPosition,
                                   const ax::ccMenuCallback& callback);
    static ax::Sprite* btnGreen;
    static ax::Sprite* btnOrange;
};

#endif  // __MAIN_MENU_H__
