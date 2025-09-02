#ifndef _UI_COMPONENTS_SCENE_HPP
#define _UI_COMPONENTS_SCENE_HPP

#include "axmol.h"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#include "Scenes/TemplateScene.hpp"

class UiComponentsScene : public TemplateScene
{
public:
    bool init() override;

private:
    ax::ui::LoadingBar *loadingBar;
    void updateLoadingBar(float delta);
};

#endif  // _UI_COMPONENTS_SCENE_HPP
