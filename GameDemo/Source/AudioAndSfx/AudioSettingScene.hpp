#ifndef __AUDIO_SETTING_SCENE_HPP
#define __AUDIO_SETTING_SCENE_HPP

#include "axmol.h"

class AudioSettingScene : public ax::Scene
{
public:
    bool init() override;

private:
    void menuBackCallback(ax::Object* sender);
};

#endif  // __AUDIO_SETTING_SCENE_HPP
