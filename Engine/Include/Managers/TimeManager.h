#pragma once

#include<SFML/SysteM/Time.hpp>
#include<SFML/SysteM/Clock.hpp>

/**
 * @brief class TimeManager
 * - 
 * - friend를 class Engine이 private되어있는 Update()에 대한 접근권한을 얻습니다.  
 * - 
 */
class TimeManager
{
private:
    sf::Clock   clock_;
    sf::Time    deltaTime_;
    sf::Time    previousTime;

public:
    auto GetDeltaTime() const   ->float;
    auto GetElapsTime() const   ->float;

private:
    friend class Engine;
    auto Update()               -> void;

};