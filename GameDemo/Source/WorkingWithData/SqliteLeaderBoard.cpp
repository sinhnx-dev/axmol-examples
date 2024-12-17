#include "SqliteLeaderBoard.hpp"
#include "axmol.h"
using namespace std;

SqliteLeaderBoard::SqliteLeaderBoard(string& dbName)
{
    pdb = NULL;
    createDb(dbName);
}

bool SqliteLeaderBoard::createDb(string& dbName)
{
    // std::string dbPath = "res/data/" + dbName;
    std::string dbPath = ax::FileUtils::getInstance()->getWritablePath() + dbName;
    printf("%s\n", dbPath.c_str());
    int result = sqlite3_open(dbPath.c_str(), &pdb);

    if (result == SQLITE_OK)
    {
        printf("open database successful!\n");
        int result = 0;
        std::string sql;
        sql = "create table if not exists LeadersBoard (user_name varchar(50) PRIMARY KEY, scores INT);";

        result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);

        if (result == SQLITE_OK)
        {
            // table created successfully
            printf("table created successfully\n");
            return true;
        }
        else
        {
            // table was NOT created successfully
            printf("table was NOT created successfully\n");
        }
    }
    else
        printf("open database failed!\n");
    return false;
}

bool SqliteLeaderBoard::insertLeaderBoard(std::string name, int score)
{
    int result = 0;
    std::string sql;
    sql = "insert into LeadersBoard(user_name, scores) values('" + name + "', " + std::to_string(score) + ");";
    printf("sql = \"%s\"\n", sql.c_str());

    result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);
    printf("result = %d\n", result);
    if (result == SQLITE_OK)
    {
        printf("inserted to leader board.\n");
        return true;
    }
    sql = "update LeadersBoard set scores = " + std::to_string(score) + " where user_name='" + name +
          "' and scores < " + std::to_string(score) + ";";
    result = sqlite3_exec(pdb, sql.c_str(), NULL, NULL, NULL);
    if (result == SQLITE_OK)
    {
        printf("update to leader board.\n");
        return true;
    }
    return false;
}

bool SqliteLeaderBoard::insertLeaderBoard(Player u)
{
    return insertLeaderBoard(u.name, u.score);
}
std::vector<Player> SqliteLeaderBoard::loadLeaderBoard(int no)
{
    vector<Player> players = vector<Player>();

    std::string sql = "SELECT user_name, scores " + std::string(" FROM LeadersBoard") +
                      std::string(" ORDER BY scores DESC") + std::string(" LIMIT ") + std::to_string(no) +
                      std::string(";");
    sqlite3_stmt* statement;
    printf("%s\n", sql.c_str());
    int rs = sqlite3_prepare_v2(pdb, sql.c_str(), -1, &statement, 0);
    printf("rs = %d\n", rs);
    if (rs == SQLITE_OK)
    {
        printf("run sql completed\n");
        int result = 0;
        while (true)
        {
            result = sqlite3_step(statement);
            if (result == SQLITE_ROW)
            {
                // do something with the row.
                Player u;
                u.name  = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement, 0)));
                u.score = sqlite3_column_int(statement, 1);
                players.push_back(u);
            }
            else
            {
                break;
            }
        }
    }
    return players;
}
SqliteLeaderBoard::~SqliteLeaderBoard()
{
    printf("close connection...\n");
    sqlite3_close(pdb);
}