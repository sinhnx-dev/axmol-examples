#ifndef _PARALLAX_INFINITE_NOTE_HPP
#define _PARALLAX_INFINITE_NOTE_HPP

#include "axmol.h"
#include <iostream>
#include <string>

using namespace std;
USING_NS_AX;

struct ParallaxLayerData
{
    Vec2 ratio;
    Vec2 positionOffset;
    Vec2 scaleOffset;

    Sprite* spriteA;
    Sprite* spriteB;

    ParallaxLayerData()
    {
        spriteA = nullptr;
        spriteB = nullptr;
    };

    void swapSprites(void)
    {
        Sprite* temp = spriteA;
        spriteA      = spriteB;
        spriteB      = temp;
    };
};

class ParallaxInfiniteNode : public Node
{
    Size m_visibleSize;
    Vec2 m_origin;
    Vec2 m_position;
    Vec2 m_speed;

    map<const string, ParallaxLayerData> m_layerData;

public:
    static Node* createNode();
    virtual bool init();
    virtual void setPosition(const Vec2& position);
    virtual const Vec2& getPosition() const;

    void addLayer(const string& fileName,
                  int z,
                  const Vec2& parallaxRatio,
                  const Vec2& positionOffset,
                  const Vec2& scaleOffset);
    void update(float delta);
};

#endif /* _PARALLAX_INFINITE_NOTE_HPP */
