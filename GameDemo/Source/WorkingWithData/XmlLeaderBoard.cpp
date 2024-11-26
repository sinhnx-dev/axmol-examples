#include "XmlLeaderBoard.hpp"

using namespace std;
using namespace pugi;

XmlLeaderBoard::XmlLeaderBoard(std::string filePath) : PlayerHighScore(filePath)
{
    parse_result = doc.load_file(filePath.c_str());
    if (parse_result)
    {
        cout << "Load result: " << parse_result.description() << endl;
        cout << "Status: " << parse_result.status << endl;
        cout << "Encoding: " << parse_result.encoding << endl;
        loadLeaderBoard();
    }
    else
    {
        std::cout << "XML [" << filePath << "] parsed with errors, attr value: ["
                  << doc.child("node").attribute("attr").value() << "]\n";
        std::cout << "Error description: " << parse_result.description() << "\n";
        std::cout << "Error offset: " << parse_result.offset << " (error at [..." << filePath << parse_result.offset
                  << "]\n\n";
    }
}

vector<Player> XmlLeaderBoard::loadLeaderBoard()
{
    _players = vector<Player>();
    if (parse_result)
    {
        xml_node leaderBoard = doc.first_child();
        for (xml_node player = leaderBoard.first_child(); player; player = player.next_sibling())
        {
            Player p;
            p.name  = player.attribute("name").as_string();
            p.score = player.attribute("scores").as_int();
            _players.push_back(p);
        }
    }
    return _players;
}
bool XmlLeaderBoard::saveToFile(std::vector<Player> players)
{
    doc.remove_children();
    xml_node leaderBoard = doc.append_child("LeaderBoard");
    for (Player p : players)
    {
        xml_node newPlayerNode                   = leaderBoard.append_child("Player");
        newPlayerNode.append_attribute("name")   = p.name;
        newPlayerNode.append_attribute("scores") = p.score;
    }
    // doc.save(cout);
    doc.save_file(_filePath.c_str());
    _isUpdate = false;
    return false;
}
XmlLeaderBoard::~XmlLeaderBoard()
{
    if (_isUpdate)
        saveToFile(_players);
}