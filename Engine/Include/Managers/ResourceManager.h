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
    auto FetchSound  (const std::string & filename) -> sf::SoundBuffer*;
    auto FetchMusic  (const std::string & filename) -> std::optional<sf::Music>;
    auto FetchFont   (const std::string & filename) -> sf::Font*;
    auto FetchTexture(const std::string & filename) -> sf::Texture*;

};
