#include "ParallaxInfiniteScene.hpp"
#include "../PopSceneMenu.hpp"

USING_NS_AX;
using namespace std;

bool ParallaxInfiniteScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto menu = utils::createInstance<PopSceneMenu>();
    if (menu != nullptr)
    {
        this->addChild(menu, 1);
    }
    else
    {
        AXLOG("Menu init error!");
    }

    // Max Speed
    m_speed = 100;
    
    // Screen coordinates
    auto visibleSize = _director->getVisibleSize();   // Screen's visible size
    Vec2 origin = _director->getVisibleOrigin();      // Screen's visible origin
    float x = origin.x + visibleSize.width * 0.5;     // x for the center of the screen
    float y = origin.y + visibleSize.height * 0.5;    // y for the center of the screen
        
    // Create a parallax node
    auto paraNode = utils::createInstance<ParallaxInfiniteNode>();
    
    // Add parallax layer sprites to the parallax node
    paraNode->addLayer("res/Parallax/Layer1.png", 3, Vec2(4.0, 0), Vec2(x, y), Vec2(1.5, 1.5));
    paraNode->addLayer("res/Parallax/Layer2.png", 2, Vec2(2.0, 0), Vec2(x, y), Vec2(1.5, 1.5));
    paraNode->addLayer("res/Parallax/Layer3.png", 1, Vec2(1.0, 0), Vec2(x, y), Vec2(1.5, 1.5));
    paraNode->addLayer("res/Parallax/Layer4.png", 0, Vec2(0.5, 0), Vec2(x, y), Vec2(1.5, 1.5));
    
    // Add parallax node to the scene
    this->addChild(paraNode, 0, 1);
    
    // Setup the accelerometer event handler
    Device::setAccelerometerEnabled(true);
    
    // The callback method
    function<void(Acceleration*, Event*)> callback = AX_CALLBACK_2(ParallaxInfiniteScene::accellerometerCallback, this);
    auto listener = EventListenerAcceleration::create(callback); // Create an accelerometer listener
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    scheduleUpdate();
    
    return true;
}

void ParallaxInfiniteScene::accellerometerCallback(Acceleration *acceleration, Event *event)
{
    auto paraNode = this->getChildByTag(1);
    auto pos = paraNode->getPosition();
    auto x = acceleration->x;  
    pos.x += m_speed * x;
    paraNode->setPosition(pos);
}

void ParallaxInfiniteScene::update(float delta)
{
    auto paraNode = this->getChildByTag(1);
    auto pos = paraNode->getPosition();
    pos.x -= m_speed * 0.5;
    paraNode->setPosition(pos);
}
