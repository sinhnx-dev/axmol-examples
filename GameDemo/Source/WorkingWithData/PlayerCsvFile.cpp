#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "PlayerCsvFile.hpp"

using namespace std;

PlayerCsvFile::PlayerCsvFile(std::string filePath)
{
    _filePath = filePath;
    // Open the file using ifstream
    ifstream file(_filePath);
    // confirm file opening
    if (!file.is_open())
    {
        // print error message
        cerr << "Failed to open file: " << _filePath << endl;
    }
    else
    {
        // Read the file line by line into a string
        string line;
        Player user;
        while (getline(file, line))
        {
            std::vector<std::string> lst = Split(line, ",");
            if (lst.size() > 1)
            {
                try
                {
                    user.score = std::stoi(lst.at(1));
                }
                catch (std::invalid_argument ex)
                {
                    continue;
                }
                user.name = lst.at(0);
                _players.push_back(user);
            }
        }
        std::sort(_players.begin(), _players.end(), PlayerCsvFile::highScoreCmp);
        // Close the file
        file.close();
    }
}
std::vector<std::string> PlayerCsvFile::Split(std::string str, std::string regexStr)
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
std::vector<Player> PlayerCsvFile::GetPlayersHighScore()
{
    return _players;
}

bool PlayerCsvFile::AddPlayerHighScore(Player player)
{
    int size = _players.size();
    if (size < 10 || _players.at(size - 1).score < player.score)
    {
        _players.push_back(player);
        _isUpdate = true;
    }
    std::sort(_players.begin(), _players.end(), PlayerCsvFile::highScoreCmp);
    if (_players.size() > 10)
    {
        _players.pop_back();
    }
    return _isUpdate;
}

PlayerCsvFile::~PlayerCsvFile()
{
    cout << "destroy PlayerCsvFile..." << endl;
    if (_isUpdate)
    {
        // save _players to _filePath
        std::ofstream outputFile(_filePath);
        if (!outputFile.is_open())
        {
            // print error message
            cerr << "Failed to open file: " << _filePath << endl;
        }
        else
        {
            for (Player p : _players)
            {
                outputFile << p.name << "," << p.score << "\n";
            }
            // Close the file
            outputFile.close();  // Close the file after writing
            cout << "Players has been written to the csv file." << endl;
        }
    }
}
bool PlayerCsvFile::highScoreCmp(Player p1, Player p2)
{
    return p1.score > p2.score;
}