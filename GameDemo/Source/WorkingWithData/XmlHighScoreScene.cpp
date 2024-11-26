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

    XmlLeaderBoard xml = XmlLeaderBoard("res/data/LeaderBoard.xml");
    std::vector<Player> players = xml.loadLeaderBoard();
    ShowHighScore(players);
    players.push_back(Player{"sinhnx", 50});
    std::sort(players.begin(), players.end(), PlayerHighScore::HighScoreCmp);
    xml.saveToFile(players);
    return true;
}