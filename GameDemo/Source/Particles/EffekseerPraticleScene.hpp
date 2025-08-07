#ifndef _EFFEKSEER_PARTICLE_SCENE_HPP
#define _EFFEKSEER_PARTICLE_SCENE_HPP

#include "axmol.h"
#include "Scenes/TemplateScene.hpp"
#include "EffekseerForCocos2d-x.h"

// #include "extensions/Effekseer/EffekseerForCocos2d-x/EffekseerForCocos2d-x.h"

class EffekseerPraticleScene : public TemplateScene
{
public:
    bool init() override;

    void update(float delta) override;

    ~EffekseerPraticleScene() override;
    void visit(ax::Renderer *renderer, const ax::Mat4& parentTransform, uint32_t parentFlags) override;
private:
    efk::EffectManager*		manager = nullptr;
    int count = 0;
};

#endif  // _EFFEKSEER_PARTICLE_SCENE_HPP
