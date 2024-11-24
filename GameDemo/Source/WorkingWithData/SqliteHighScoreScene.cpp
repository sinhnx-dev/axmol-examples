#include "SqliteHighScoreScene.hpp"
#include "SqliteLeaderBoard.hpp"

// USING_NS_AX;

bool SqliteHighScoreScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!HighScoreScene::init())
    {
        return false;
    }

    SetTitle("SQLite Leader Board");
    std::string lbdb                  = "LeaderBoard.db";
    SqliteLeaderBoard leaderBoard = SqliteLeaderBoard(lbdb);

    std::string userName = "sinhnx";
    Player p;
    p.name  = userName;
    p.score = 90;
    if (leaderBoard.insertLeaderBoard(p))
    {
        AXLOG("can't insert to LeadersBoard\n");
    }
    else
    {
        AXLOG("Insert completed!");
    }

    std::vector<Player> players = leaderBoard.loadLeaderBoard(10);
    ShowHighScore(players);

    return true;
}