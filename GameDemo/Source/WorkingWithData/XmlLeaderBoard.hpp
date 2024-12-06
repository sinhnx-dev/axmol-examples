#ifndef _XML_LEADER_BOARD_HPP_
#define _XML_LEADER_BOARD_HPP_

#include "axmol.h"
#include "3rdparty/pugixml/pugixml.hpp"
#include "PlayerHighScore.hpp"
#include "Player.h"
#include <vector>
#include <string>

class XmlLeaderBoard : public PlayerHighScore
{
private:
    pugi::xml_document doc;
    pugi::xml_parse_result parse_result;
    std::vector<Player> loadLeaderBoard();
    bool saveToFile(std::vector<Player> players);

public:
    XmlLeaderBoard(std::string filePath);
    ~XmlLeaderBoard();
};

#endif  // _XML_LEADER_BOARD_HPP_