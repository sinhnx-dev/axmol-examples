#include "EffekseerPraticleScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;

bool EffekseerPraticleScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = _director->getVisibleSize();
    auto origin      = _director->getVisibleOrigin();
    auto safeArea    = _director->getSafeAreaRect();
    auto safeOrigin  = safeArea.origin;

    auto menu = utils::createInstance<PopSceneMenu>();
    if (menu != nullptr)
    {
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    // manager = Effekseer::EffectFactory
    return true;
}

void EffekseerPraticleScene::update(float delta) {
    // Effect1
	// if (count % 300 == 0)
	// {
	// 	/**
	// 		拡大率を指定してエフェクトファイルを読み込みます。

	// 		You read an effect file with specifying scale.

	// 		您通過指定比例讀取效果文件。

	// 		您通过指定比例读取效果文件。
	// 	*/
	// 	auto effect = Effekseer::Effect::create("res/Praticles/Laser01.efk", 13.0f);
	// 	if (effect != nullptr)
	// 	{
	// 		/**
	// 			エミッターを生成し、パラメーターを設定してレイヤーに追加します。

	// 			You generate an emitter, set parameters and add it to the layer.

	// 			您會生成一個發射極，並通過將參數添加到該層。

	// 			您会生成一个发射极，并通过将参数添加到该层。
	// 		*/

	// 		auto emitter = Effekseer::EffectEmitter::create(manager);
	// 		emitter->setEffect(effect);
	// 		emitter->setPlayOnEnter(true);
			
	// 		emitter->setRotation3D(ax::Vec3(0, 90, 0));
	// 		emitter->setPosition(Vec2(320, 150));
			
	// 		// emitter->setScale(13);
	// 		this->addChild(emitter, 0);

	// 		// No need (because it uses autorelease after 1.41)
	// 		//effect->release();
	// 	}
	// }
}