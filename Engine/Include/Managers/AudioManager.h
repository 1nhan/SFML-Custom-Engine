#pragma once
#include <SFML/System/Vector3.hpp>
class AudioManager
{
public:
    auto SetGlobalVolume     (float volume)              -> void ;
    auto GetGlobalVolume     () const                    -> float;

    auto SetListenerDirection(sf::Vector3f direction)    -> void ;
    auto GetListenerDirection()                          -> sf::Vector3f;

    auto SetListenerPosition (sf::Vector3f position)     -> void ;
    auto GetListenerPosition ()                          -> sf::Vector3f;
};