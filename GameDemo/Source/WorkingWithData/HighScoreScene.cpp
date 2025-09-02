#include "HighScoreScene.hpp"

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
    setTitle("High Score");

    return true;
}
void HighScoreScene::showHighScore(std::vector<Player> players)
{
    Label* lblHighScore;
    unsigned long i = players.size() / 2;
    for (Player u : players)
    {
        lblHighScore = Label::createWithTTF(u.name + ": " + std::to_string(u.score), "fonts/Marker Felt.ttf", 20);
        lblHighScore->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2 - i++ * 30));
        addChild(lblHighScore);
    }
}