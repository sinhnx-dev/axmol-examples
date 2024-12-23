#ifndef _HIGH_SCORE_SCENE_HPP
#define _HIGH_SCORE_SCENE_HPP

#include "../Scenes/TemplateScene.hpp"
#include "Player.h"

class HighScoreScene : public TemplateScene
{
public:
    bool init() override;
    void ShowHighScore(std::vector<Player> players);
private:
};

#endif  // _HIGH_SCORE_SCENE_HPP