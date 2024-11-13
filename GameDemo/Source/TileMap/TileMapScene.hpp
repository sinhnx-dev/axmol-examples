#ifndef _TILE_MAP_SCENE_HPP
#define _TILE_MAP_SCENE_HPP

#include "axmol.h"
#include "GameInfoLayer.hpp"

class TileMapScene : public ax::Scene
{
public:
    bool init() override;
    void setViewPointCenter(ax::Point position);
    ax::Point tileCoordForPosition(ax::Point position);
    void setPlayerPosition(ax::Point position);

private:
    ax::TMXTiledMap* _tileMap;
    ax::TMXLayer* _background;
    ax::Sprite* _player;
    ax::TMXLayer* _meta;
    ax::TMXLayer* _foreground;
    GameInfoLayer* _gameInfo;
    int _numCollected;
};

#endif  // _TILE_MAP_SCENE_HPP