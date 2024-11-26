#include "JsonLeaderBoard.hpp"
#include "axmol.h"
using namespace std;

JsonLeaderBoard::JsonLeaderBoard(std::string filePath) : PlayerHighScore(filePath)
{
    loadLeaderBoard();
}

vector<Player> JsonLeaderBoard::loadLeaderBoard()
{
    _players            = vector<Player>();
    std::string content = ax::FileUtils::getInstance()->getStringFromFile(_filePath.c_str());
    jDoc.Parse(content.c_str());
    const rapidjson::Value& ranking = jDoc["LeaderBoard"];
    if (ranking.IsArray())
    {
        for (int i = 0; i < ranking.Size(); ++i)
        {
            if (ranking[i].HasMember("name") && ranking[i].HasMember("scores"))
            {
                Player p;
                p.name  = string(ranking[i]["name"].GetString());
                p.score = ranking[i]["scores"].GetInt();
                _players.push_back(p);
            }
        }
    }
    else
    {
        AXLOG("not is array...");
    }
    return _players;
}

bool JsonLeaderBoard::saveToFile(std::vector<Player> players)
{
    rapidjson::Document doc;
    doc.SetObject();
    rapidjson::Document::AllocatorType& allocator = doc.GetAllocator();

    rapidjson::Value aUsers(rapidjson::Type::kArrayType);
    for (const Player u : players)
    {
        rapidjson::Value o;
        o.SetObject();

        rapidjson::Value uName(rapidjson::Type::kStringType);
        uName.SetString(u.name.c_str(), strlen(u.name.c_str()), jDoc.GetAllocator());
        o.AddMember("name", uName, allocator);

        rapidjson::Value uScore(rapidjson::Type::kNumberType);
        uScore.SetInt(u.score);
        o.AddMember("scores", u.score, allocator);

        aUsers.PushBack(o, allocator);
    }
    doc.AddMember("LeaderBoard", aUsers, allocator);
    rapidjson::StringBuffer strbuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strbuf);
    doc.Accept(writer);

    if (ax::FileUtils::getInstance()->writeStringToFile(strbuf.GetString(), _filePath))
    {
        return true;
    }
    return false;
}

JsonLeaderBoard::~JsonLeaderBoard()
{
    if (_isUpdate)
        saveToFile(_players);
}