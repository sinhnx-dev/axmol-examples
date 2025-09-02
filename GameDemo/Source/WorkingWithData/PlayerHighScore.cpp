#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "PlayerHighScore.hpp"

using namespace std;

PlayerHighScore::PlayerHighScore(std::string filePath)
{
    _filePath = filePath;
    _isUpdate = false;
}
std::vector<std::string> PlayerHighScore::Split(std::string str, std::string regexStr)
{
    std::vector<std::string> v;
    std::regex re(regexStr);
    std::regex_token_iterator<std::string::iterator> d(str.begin(), str.end(), re, -1);
    // default constructor = end-of-sequence:
    std::regex_token_iterator<std::string::iterator> rend;
    while (d != rend)
        v.push_back(std::string(*d++));
    return v;
}
std::vector<Player> PlayerHighScore::GetPlayersHighScore()
{
    return _players;
}

bool PlayerHighScore::AddPlayerHighScore(Player player)
{
    int size = (int)_players.size();
    if (size < MAX_TOP_PLAYER || _players.at(size - 1).score < player.score)
    {
        _players.push_back(player);
        _isUpdate = true;
    }
    std::sort(_players.begin(), _players.end(), PlayerHighScore::HighScoreCmp);
    if (_players.size() > MAX_TOP_PLAYER)
    {
        _players.pop_back();
    }
    return _isUpdate;
}

PlayerHighScore::~PlayerHighScore()
{
    cout << "destroy PlayerHighScore..." << endl;
}
bool PlayerHighScore::HighScoreCmp(Player p1, Player p2)
{
    return p1.score > p2.score;
}