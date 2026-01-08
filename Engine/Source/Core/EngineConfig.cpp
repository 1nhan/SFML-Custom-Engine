#include <Core/EngineConfig.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <cassert>


/**
 * @brief EngineConfig()
 * - nlohmann/json 이용해서 Config를 관리합니다.
 * - std::ifstream을 통해 생성자와 Content/Config.json간 연결합니다.
 * - json 객체를 생성하여 파일로 파싱된 데이터를 전송합니다.
 * - 
 * - maximumDeltaTime의 값을 json으로 전달해 관리합니다. json은 SF시간에 대한 것을 모르기 때문에 sf::seconds로 변환해야 합니다. 
 */
EngineConfig::EngineConfig()
{
    std::ifstream file("Content/Config.json");
    assert(file);
    
    nlohmann::json json = nlohmann::json::parse(file);
    WINDOWTITLE         = json["WINDOWTITLE"];
    WINDOWSIZE          = {json["WINDOWSIZE"][0], 
                           json["WINDOWSIZE"][1]};
    disableSfmlLogs     = json["disableSfmlLogs"];
    maximumDeltaTime    = sf::seconds(json["maximumDeltaTime"]);
    globalVolume        = json["globalVolume"];
}