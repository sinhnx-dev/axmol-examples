#ifndef _SQLITE_HIGH_SCORE_SCENE_HPP
#define _SQLITE_HIGH_SCORE_SCENE_HPP

#include "HighScoreScene.hpp"
#include "Player.h"

class SqliteHighScoreScene : public HighScoreScene
{
public:
    bool init() override;
private:
};

#endif  // _SQLITE_HIGH_SCORE_SCENE_HPP