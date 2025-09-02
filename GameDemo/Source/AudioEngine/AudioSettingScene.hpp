#ifndef __AUDIO_SETTING_SCENE_HPP
#define __AUDIO_SETTING_SCENE_HPP

#include "axmol.h"

class AudioSettingScene : public ax::Scene
{
public:
    bool init() override;
    ~AudioSettingScene() override;

private:
    void menuBackCallback(ax::Object* sender);
    int _piano;
};

#endif  // __AUDIO_SETTING_SCENE_HPP
