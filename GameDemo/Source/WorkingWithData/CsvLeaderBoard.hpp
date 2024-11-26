#ifndef _PLAYER_CSV_FILE_HPP
#define _PLAYER_CSV_FILE_HPP

#include "Player.h"
#include "PlayerHighScore.hpp"

class CsvLeaderBoard : public PlayerHighScore
{
public:
    CsvLeaderBoard(std::string filePath);
    ~CsvLeaderBoard();
    // std::vector<Player> GetPlayersHighScore() override;
    // bool AddPlayerHighScore(Player player) override;

private:
    
};

#endif  // _PLAYER_CSV_FILE_HPP