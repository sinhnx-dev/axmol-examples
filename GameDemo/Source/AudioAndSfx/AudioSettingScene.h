#ifndef __AUDIO_SETTING_SCENE
#define __AUDIO_SETTING_SCENE

#include "axmol.h"


class AudioSettingScene : public ax::Scene
{
public:
    bool init() override;
    void update(float delta) override;

    static AudioSettingScene* scene();
    CREATE_FUNC(AudioSettingScene);

    // // touch
    // void onTouchesBegan(const std::vector<ax::Touch*>& touches, ax::Event* event);
    // void onTouchesMoved(const std::vector<ax::Touch*>& touches, ax::Event* event);
    // void onTouchesEnded(const std::vector<ax::Touch*>& touches, ax::Event* event);

    // // mouse
    // void onMouseDown(ax::Event* event);
    // void onMouseUp(ax::Event* event);
    // void onMouseMove(ax::Event* event);
    // void onMouseScroll(ax::Event* event);

    // // Keyboard
    // void onKeyPressed(ax::EventKeyboard::KeyCode code, ax::Event* event);
    // void onKeyReleased(ax::EventKeyboard::KeyCode code, ax::Event* event);

    // // a selector callback
    // void menuCloseCallback(Ref* sender);

private:
};

#endif  // __AUDIO_SETTING_SCENE
