#include "XmlHighScoreScene.hpp"
#include "XmlLeaderBoard.hpp"
#include "PlayerHighScore.hpp"
#include "axmol.h"

USING_NS_AX;

bool XmlHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }

    SetTitle("XML Leader Board");

    // XmlLeaderBoard xml          = XmlLeaderBoard("res/data/LeaderBoard.xml");
    XmlLeaderBoard xml = XmlLeaderBoard(FileUtils::getInstance()->getWritablePath() + "LeaderBoard.xml");
    xml.AddPlayerHighScore(Player{"sinhnx", 80});
    std::vector<Player> players = xml.GetPlayersHighScore();
    ShowHighScore(players);
    return true;
}