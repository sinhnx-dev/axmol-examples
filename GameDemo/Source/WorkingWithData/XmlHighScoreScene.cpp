#include "XmlHighScoreScene.hpp"
#include "XmlLeaderBoard.hpp"
#include "PlayerHighScore.hpp"

// USING_NS_AX;

bool XmlHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }

    SetTitle("XML Leader Board");

    XmlLeaderBoard xml          = XmlLeaderBoard("res/data/LeaderBoard.xml");
    xml.AddPlayerHighScore(Player{"sinhnx", 80});
    std::vector<Player> players = xml.GetPlayersHighScore();
    ShowHighScore(players);
    return true;
}