#include "JsonHighScoreScene.hpp"
#include "JsonLeaderBoard.hpp"

// USING_NS_AX;

bool JsonHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }

    SetTitle("JSON Leader Board");
    JsonLeaderBoard json = JsonLeaderBoard("res/data/LeaderBoard.json");
    json.AddPlayerHighScore(Player{"abc", 100});
    ShowHighScore(json.GetPlayersHighScore());

    std::string sbuf;
    ax::FileUtils::getInstance()->getContents("res/data/LeaderBoard.json", &sbuf);
    AXLOG("%s", sbuf.c_str());

    return true;
}