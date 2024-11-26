#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "CsvLeaderBoard.hpp"

using namespace std;

CsvLeaderBoard::CsvLeaderBoard(std::string filePath) : PlayerHighScore(filePath)
{
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
        std::sort(_players.begin(), _players.end(), PlayerHighScore::HighScoreCmp);
        // Close the file
        file.close();
    }
}

CsvLeaderBoard::~CsvLeaderBoard()
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