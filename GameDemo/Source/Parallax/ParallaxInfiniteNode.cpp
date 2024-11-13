#include "axmol.h"
#include "ParallaxInfiniteNode.hpp"

USING_NS_AX;

Node* ParallaxInfiniteNode::createNode()
{
    return ParallaxInfiniteNode::create();
}

bool ParallaxInfiniteNode::init()
{
    // Save the screen coordinates
    m_visibleSize = Director::getInstance()->getVisibleSize();   // Screen's visible size
    m_origin = Director::getInstance()->getVisibleOrigin();      // Screen's visible origin
    
    // Schedule Update
    scheduleUpdate();
    
    return true;
}

void ParallaxInfiniteNode::addLayer(const string &fileName,
                                    int z,
                                    const Vec2& parallaxRatio,
                                    const Vec2& positionOffset,
                                    const Vec2& scaleOffset
                                    )
{
    // Create Sprite A
    auto spriteA = Sprite::create(fileName);
    spriteA->setLocalZOrder(z);
    spriteA->setPosition(positionOffset.x, positionOffset.y);
    spriteA->setScale(scaleOffset.x, scaleOffset.y);
    this->addChild(spriteA);
    
    // Create Sprite B
    auto spriteB = Sprite::create(fileName);
    spriteB->setLocalZOrder(z);
    spriteB->setPosition(positionOffset.y , positionOffset.y);
    spriteB->setScale(scaleOffset.x, scaleOffset.y);
    this->addChild(spriteB);
    
    // Create Layer Data and save the information
    ParallaxLayerData data;
    data.ratio = parallaxRatio;
    data.positionOffset = positionOffset;
    data.scaleOffset = scaleOffset;
    data.spriteA = spriteA;
    data.spriteB = spriteB;
    m_layerData[fileName] = data;
}

// This doesn't actually change the position of the node!
// It just records where it should have been, so that it can move the layers accordingly
void ParallaxInfiniteNode::setPosition(const Vec2 &position)
{
    m_speed = position - m_position; // Calculate the amount of movement
    m_position = position;           // Update the position to the current position
}

const Vec2& ParallaxInfiniteNode::getPosition() const
{
    return m_position;               // Return the current position
}

// On every frame, calculate the position of A and B sprites for each layer
void ParallaxInfiniteNode::update(float delta)
{
    // Loop over all the layers
    for(auto &layer: m_layerData)
    {
        // Calculate speed for this layer considering the movement ratio
        Vec2 speed;
        speed.x = m_speed.x * layer.second.ratio.x * delta;
        speed.y = m_speed.y * layer.second.ratio.y * delta;
        
        // Calculate and update the position for sprite A (master)
        auto posA = layer.second.spriteA->getPosition();
        posA += speed;
        layer.second.spriteA->setPosition(posA);
        
        // Calculate the position of Sprite B relative to sprite A
        if(posA.x <= m_visibleSize.width * 0.5) // If sprite A is on the left side of the screen
        {
            // Place the slave sprite on the right
            // -1 is to cover any possible gaps between the two layers
            auto x = posA.x + layer.second.spriteA->getContentSize().width * layer.second.scaleOffset.x - 1;
            auto y = posA.y;
            layer.second.spriteB->setPosition(x, y);
        }
        else // If sprite A is on the right side of the screen
        {
            // Place the slave sprite on the left
            // +1 is to cover any possible gaps between the two layers
            auto x = posA.x - layer.second.spriteA->getContentSize().width * layer.second.scaleOffset.x + 1;
            auto y = posA.y;
            layer.second.spriteB->setPosition(x, y);
        }
        
        // The sprite that is covering most of the screen should become sprite A
        auto limitL = (m_visibleSize.width - layer.second.spriteA->getContentSize().width * layer.second.scaleOffset.x) * 0.5;
        auto limitR = (m_visibleSize.width + layer.second.spriteA->getContentSize().width * layer.second.scaleOffset.x) * 0.5;
        
        // If the master sprite (A) goes beyond the limit, swap sprite
        if(posA.x < limitL || posA.x > limitR)
        {
            //m_layerData[layer.first].swapSprites();
            layer.second.swapSprites();
        }
    }
}
