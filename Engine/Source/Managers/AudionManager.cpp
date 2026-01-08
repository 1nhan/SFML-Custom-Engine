#include "Managers/AudioManager.h"
#include <SFML/Audio/Listener.hpp>


auto AudioManager:: SetGlobalVolume        (float volume)              -> void          
{
    sf::Listener::setGlobalVolume(volume);
} 
auto AudioManager:: GetGlobalVolume        () const                    -> float         
{
    return sf::Listener::getGlobalVolume();
}
auto AudioManager:: SetListenerDirection   (sf::Vector3f direction)    -> void          
{
    sf::Listener::setDirection(direction);
}
auto AudioManager:: GetListenerDirection   ()                          -> sf::Vector3f  
{
    return sf::Listener::getDirection();
}
auto AudioManager:: SetListenerPosition    (sf::Vector3f position)     -> void          
{
    sf::Listener::setPosition(position);
}
auto AudioManager:: GetListenerPosition    ()                          -> sf::Vector3f  
{
    return sf::Listener::getPosition();
}