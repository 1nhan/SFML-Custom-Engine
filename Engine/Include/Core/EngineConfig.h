#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Time.hpp>
#include <string>

/**
 * @brief struct EngineConfig
 * -
 * - 
 * - maximumDeltaTime을 통해 비현실적인 deltaTime_에 대해 이뤄지는 시뮬레이션에 대한 프레임을 조절하기위해 deltaTime_최대값을 지정합니다.
 */
struct EngineConfig
{
    sf::Vector2f            WINDOWSIZE;
    std::string             WINDOWTITLE;

    sf::Time                maximumDeltaTime;
    bool                    disableSfmlLogs;

    float                   globalVolume;

    EngineConfig();
};

inline const EngineConfig   gConfig;