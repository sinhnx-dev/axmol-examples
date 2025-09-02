#include "JsonHighScoreScene.hpp"
#include "JsonLeaderBoard.hpp"
#include "axmol.h"

USING_NS_AX;

bool JsonHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }
    setTitle("JSON Leader Board");
    
    // JsonLeaderBoard json = JsonLeaderBoard("res/data/LeaderBoard.json");
    JsonLeaderBoard json = JsonLeaderBoard(FileUtils::getInstance()->getWritablePath() + "LeaderBoard.json");
    json.AddPlayerHighScore(Player{"abc", 100});
    showHighScore(json.GetPlayersHighScore());

    std::string sbuf;
    ax::FileUtils::getInstance()->getContents("res/data/LeaderBoard.json", &sbuf);
    AXLOG("%s", sbuf.c_str());

    return true;
}