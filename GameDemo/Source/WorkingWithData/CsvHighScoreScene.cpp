#include "CsvHighScoreScene.hpp"
#include "CsvLeaderBoard.hpp"

// USING_NS_AX;

bool CsvHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }

    SetTitle("CSV Leader Board");
    CsvLeaderBoard csv = CsvLeaderBoard("res/data/LeaderBoard.csv");
    csv.AddPlayerHighScore(Player{"abc", 100});
    ShowHighScore(csv.GetPlayersHighScore());

    std::string sbuf;
    ax::FileUtils::getInstance()->getContents("res/data/LeaderBoard.csv", &sbuf);
    AXLOG("%s", sbuf.c_str());

    return true;
}