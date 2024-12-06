#include "HighScoreScene.hpp"
#include "../PopSceneMenu.hpp"

#include <vector>
#include <string>
USING_NS_AX;

bool HighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!TemplateScene::init())
    {
        return false;
    }

    return true;
}
void HighScoreScene::ShowHighScore(std::vector<Player> players)
{
    Label* lblHighScore;
    int i = -players.size() / 2;
    for (Player u : players)
    {
        lblHighScore = Label::createWithTTF(u.name + ": " + std::to_string(u.score), "fonts/Marker Felt.ttf", 20);
        lblHighScore->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - i++ * 30));
        addChild(lblHighScore);
    }
}