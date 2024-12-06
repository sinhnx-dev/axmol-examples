#ifndef _PLAYER_CSV_FILE_HPP
#define _PLAYER_CSV_FILE_HPP

#include "Player.h"
#include "PlayerHighScore.hpp"
#include <vector>
#include <string>

class CsvLeaderBoard : public PlayerHighScore
{
public:
    CsvLeaderBoard(std::string filePath);
    ~CsvLeaderBoard();

private:
};

#endif  // _PLAYER_CSV_FILE_HPP