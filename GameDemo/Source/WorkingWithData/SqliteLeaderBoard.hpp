#ifndef _SQLITE_LEADER_BOARD_HPP
#define _SQLITE_LEADER_BOARD_HPP

#include "sqlite3/sqlite3.h"
#include "Player.h"

class SqliteLeaderBoard
{
private:
    sqlite3* pdb;
    bool createDb(std::string& dbPath);

public:
    SqliteLeaderBoard(std::string& dbPath);
    ~SqliteLeaderBoard();
    bool insertLeaderBoard(std::string name, int score);
    bool insertLeaderBoard(Player u);
    std::vector<Player> loadLeaderBoard(int no);
};

#endif  // _SQLITE_LEADER_BOARD_HPP