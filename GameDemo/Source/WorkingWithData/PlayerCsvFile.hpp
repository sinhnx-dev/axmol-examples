#ifndef _PLAYER_CSV_FILE_HPP
#define _PLAYER_CSV_FILE_HPP

#include "Player.h"

class PlayerCsvFile
{
public:
    PlayerCsvFile(std::string filePath);
    ~PlayerCsvFile();
    static std::vector<std::string> Split(std::string str, std::string regexStr);
    std::vector<Player> GetPlayersHighScore();
    bool AddPlayerHighScore(Player player);

private:
    std::string _filePath;
    std::vector<Player> _players;
    static bool highScoreCmp(Player p1, Player p2);
    bool _isUpdate;
};

#endif  // _PLAYER_CSV_FILE_HPP