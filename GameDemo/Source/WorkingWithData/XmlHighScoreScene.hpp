#ifndef _XML_HIGH_SCORE_SCENE_HPP
#define _XML_HIGH_SCORE_SCENE_HPP

#include "HighScoreScene.hpp"
#include "Player.h"
#include <vector>
#include <string>

class XmlHighScoreScene : public HighScoreScene
{
public:
    bool init() override;

private:
};

#endif  // _XML_HIGH_SCORE_SCENE_HPP