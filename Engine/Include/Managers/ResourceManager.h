#pragma once

#include <SFML/Graphics/Text.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>

#include <string>
#include <unordered_map>
#include <optional>

class ResourceManager
{
private:
    std::unordered_map<std::string, sf::Texture>        texture_;
    std::unordered_map<std::string, sf::SoundBuffer>    sound_;
    std::unordered_map<std::string, sf::Font>           font_;

    
public:
    sf::SoundBuffer*                FetchSound      (std::string & filename);
    std::optional<sf::Music>        FetchMusic      (std::string & filename);
    sf::Font*                       FetchFont       (std::string & filename);
    sf::Texture*                    FetchTexture    (std::string & filename);

};
