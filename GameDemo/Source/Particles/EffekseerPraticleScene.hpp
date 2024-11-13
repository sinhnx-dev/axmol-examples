#ifndef _EFFEKSEER_PARTICLE_SCENE_HPP
#define _EFFEKSEER_PARTICLE_SCENE_HPP

#include "axmol.h"

// #include "extensions/Effekseer/EffekseerForCocos2d-x/EffekseerForCocos2d-x.h"

class EffekseerPraticleScene : public ax::Scene
{
public:
    bool init() override;

    void update(float delta) override;
private:
    // Effekseer::EffectManager*		manager = nullptr;
    int count = 0;
};

#endif  // _EFFEKSEER_PARTICLE_SCENE_HPP
