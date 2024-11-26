#ifndef _JSON_LEADER_BOARD_HPP_
#define _JSON_LEADER_BOARD_HPP_

#include "3rdparty/rapidjson/document.h"
#include "3rdparty/rapidjson/writer.h"
#include "3rdparty/rapidjson/stringbuffer.h"
#include "Player.h"
#include "PlayerHighScore.hpp"

class JsonLeaderBoard : public PlayerHighScore
{
private:
  rapidjson::Document jDoc;
  // bool insertLeaderBoard(Player p);
  std::vector<Player> loadLeaderBoard();
  bool saveToFile(std::vector<Player> players);

public:
  JsonLeaderBoard(std::string filePath);
  ~JsonLeaderBoard();
};

#endif // _JSON_LEADER_BOARD_HPP_