#ifndef _PLAYER_HIGH_SCORE_HPP_
#define _PLAYER_HIGH_SCORE_HPP_

#include "Player.h"

class PlayerHighScore
{
public:
    PlayerHighScore(std::string filePath);
    ~PlayerHighScore();
    virtual std::vector<Player> GetPlayersHighScore();
    virtual bool AddPlayerHighScore(Player player);
    static bool HighScoreCmp(Player p1, Player p2);
    static std::vector<std::string> Split(std::string str, std::string regexStr);
    static inline int MAX_TOP_PLAYER = 10;

protected:
    std::string _filePath;
    std::vector<Player> _players;
    bool _isUpdate;
};

#endif  // _PLAYER_HIGH_SCORE_HPP_