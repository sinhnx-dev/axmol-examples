#include "CsvHighScoreScene.hpp"
#include "PlayerCsvFile.hpp"

// USING_NS_AX;

bool CsvHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }

    SetTitle("Leader Board");
    PlayerCsvFile csv = PlayerCsvFile("res/data/users.csv");
    csv.AddPlayerHighScore(Player{"abc", 90});
    ShowHighScore(csv.GetPlayersHighScore());

    std::string sbuf;
    ax::FileUtils::getInstance()->getContents("res/data/users.csv", &sbuf);
    AXLOG("%s", sbuf.c_str());

    return true;
}