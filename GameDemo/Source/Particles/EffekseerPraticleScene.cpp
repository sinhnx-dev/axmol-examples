#include "EffekseerPraticleScene.hpp"

USING_NS_AX;

bool EffekseerPraticleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }
    setTitle("Effekseer Praticle");

    scheduleUpdate();

    manager = efk::EffectManager::create(Director::getInstance()->getVisibleSize());

    return true;
}

void EffekseerPraticleScene::update(float delta)
{
    if (count % 300 == 0)
    {
        auto effect = efk::Effect::create("res/Praticles/Laser01.efk", 20.0f);
        if (effect != nullptr)
        {
            auto emitter = efk::EffectEmitter::create(manager);
            emitter->setEffect(effect);
            emitter->setPlayOnEnter(true);

            emitter->setRotation3D(ax::Vec3(0, 90, 0));
            emitter->setPosition(Vec2(320, 150));

            // emitter->setScale(13);
            this->addChild(emitter, 0);
        }
    }
	// Effect2
	if (count % 300 == 120)
	{
		auto effect = efk::Effect::create("res/Praticles/Homing_Laser01.efk");
		if (effect != nullptr)
		{
			auto emitter = efk::EffectEmitter::create(manager);
			emitter->setEffect(effect);
			emitter->setPlayOnEnter(true);

			emitter->setPosition(Vec2(320, 150));
			emitter->setScale(4);
			this->addChild(emitter, 0);
			emitter->setTargetPosition(ax::Vec3(320, 480, 0));
		}
	}
    if (count % 300 == 150)
    {
        auto effect = efk::Effect::create("res/Praticles/ex01-spread.efk", 20.0f);
        if (effect != nullptr)
        {
            auto emitter = efk::EffectEmitter::create(manager);
            emitter->setEffect(effect);
            emitter->setPlayOnEnter(true);

            emitter->setRotation3D(ax::Vec3(0, 90, 0));
            emitter->setPosition(Vec2(320, 300));

            emitter->setScale(3);
            this->addChild(emitter, 0);
        }
    }
    manager->update();
    count++;
}

EffekseerPraticleScene::~EffekseerPraticleScene()
{
    if (manager)
    {
        manager->release();
        manager = nullptr;
    }
}

void EffekseerPraticleScene::visit(ax::Renderer *renderer, const ax::Mat4& parentTransform, uint32_t parentFlags)
{
	manager->begin(renderer, _globalZOrder);
	ax::Scene::visit(renderer, parentTransform, parentFlags);
	manager->end(renderer, _globalZOrder);
}