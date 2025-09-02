#include "AudioSettingScene.hpp"
#include "ui/CocosGUI.h"
#include "ui/UIWidget.h"
#define USE_AUDIO_ENGINE 1
#if USE_AUDIO_ENGINE
#    include "audio/AudioEngine.h"
#endif

USING_NS_AX;

bool AudioSettingScene::init()
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

    auto audioBox = Sprite::createWithSpriteFrameName("Box_Blue_Rounded.png");
    audioBox->setPosition(origin.x + visibleSize.x / 2, origin.y + visibleSize.y / 2);
    audioBox->setScale(0.75);
    this->addChild(audioBox);

    // The background music
    _piano      = AudioEngine::play2d("res/audio/piano-loops.wav", true, 1.0f);
    auto slider = ui::Slider::create();
    slider->loadBarTexture("res/ui/Slider_Back.png");
    slider->loadSlidBallTextures("res/ui/SliderNode_Normal.png", "res/ui/SliderNode_Press.png",
                                 "res/ui/SliderNode_Disable.png");
    slider->loadProgressBarTexture("res/ui/Slider_PressBar.png");
    slider->addEventListener([&](Object* sender, ui::Slider::EventType type) {
        if (type == ui::Slider::EventType::ON_PERCENTAGE_CHANGED)
        {
            auto s = dynamic_cast<ui::Slider*>(sender);
            AXLOG("music percent: %d", s->getPercent());
            AudioEngine::setVolume(_piano, (float)s->getPercent() / 100);
        }
    });
    slider->setPercent(100);
    slider->setPosition(Vec2(audioBox->getContentSize().width / 2, audioBox->getContentSize().height / 2 + 150));
    auto lblVolume = Label::createWithSystemFont("Volume", "fonts/Arial.ttf", 20);
    lblVolume->setAnchorPoint(Vec2(0, 0.5));
    lblVolume->setPosition(Vec2(slider->getContentSize().width * 1.1, slider->getContentSize().height / 2));
    slider->addChild(lblVolume);
    audioBox->addChild(slider);

    auto checkbox = ui::CheckBox::create("res/ui/CheckBox_Normal.png", "res/ui/CheckBox_Press.png",
                                         "res/ui/CheckBoxNode_Normal.png", "res/ui/CheckBoxNode_Disable.png",
                                         "res/ui/CheckBox_Disable.png");
    auto cbLabel  = Label::createWithSystemFont("Background Music", "fonts/Arial.ttf", 20);
    cbLabel->setAnchorPoint(Vec2(0, 0.5));
    cbLabel->setPosition(Vec2(checkbox->getContentSize().width * 1.2, checkbox->getContentSize().height / 2));
    checkbox->addChild(cbLabel);
    checkbox->setSelected(true);
    checkbox->addEventListener([&](Object* sender, ui::CheckBox::EventType type) {
        switch (type)
        {
        case ui::CheckBox::EventType::SELECTED:
            AXLOG("Background Music Selected");
            AudioEngine::resume(_piano);
            break;
        case ui::CheckBox::EventType::UNSELECTED:
            AXLOG("Background Music Unselected");
            AudioEngine::pause(_piano);
            break;
        default:
            break;
        }
    });
    checkbox->setPosition(
        Vec2(audioBox->getContentSize().width / 2 - 100, audioBox->getContentSize().height / 2 + 100));
    audioBox->addChild(checkbox);

    // MenuItemFont::setFontSize(28);
    auto miSoundEffect = MenuItemFont::create("Play Audio Effect", [&](Object* sender) {
        AXLOG("Play Audio Effect!");
        AudioEngine::play2d("res/audio/sound-short-generic.wav");
    });
    miSoundEffect->setPosition(Vec2::ZERO);
    audioBox->addChild(Menu::create(miSoundEffect, nullptr));

    auto mi = MenuItemSprite::create(Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
                                     Sprite::createWithSpriteFrameName("Icon_Small_Blank_Return.png"),
                                     AX_CALLBACK_1(AudioSettingScene::menuBackCallback, this));
    float x = safeOrigin.x + safeArea.size.width - mi->getContentSize().width / 2;
    float y = mi->getContentSize().height / 2;
    mi->setPosition(Vec2(x, y));
    auto menu = Menu::create(mi, nullptr);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 10);

    return true;
}

void AudioSettingScene::menuBackCallback(ax::Object* sender)
{
    AXLOG("pop scene...");
    _director->popScene();
}

AudioSettingScene::~AudioSettingScene()
{
#if USE_AUDIO_ENGINE
    AudioEngine::stopAll();
    AudioEngine::end();
#endif
    AXLOG("AudioSettingScene destroyed");
}