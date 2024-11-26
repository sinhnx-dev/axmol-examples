#ifndef _XML_LEADER_BOARD_HPP_
#define _XML_LEADER_BOARD_HPP_

#include "axmol.h"
#include "3rdparty/pugixml/pugixml.hpp"
#include "Player.h"
class XmlLeaderBoard
{
private:
    std::string filePath;
    pugi::xml_document doc;
    pugi::xml_parse_result parse_result;
    bool isUpdate;
public:
    XmlLeaderBoard(std::string filePath);
    ~XmlLeaderBoard();
    bool insertLeaderBoard(Player u);
    std::vector<Player> loadLeaderBoard();
    bool saveToFile(std::vector<Player> players);
};

#endif  // _XML_LEADER_BOARD_HPP_