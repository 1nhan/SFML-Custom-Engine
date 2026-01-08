#include "Managers/ResourceManager.h"
#include "Utils/Log.h"

sf::Texture*                   ResourceManager::FetchTexture    (std::string & filename)
{
    if(!texture_.contains(filename))
    {
        if(!texture_[filename].loadFromFile("Content/Textures/"+filename))
        {
            LOG_INFO("Failed to load Texture : {}", filename);
            return nullptr;
        }
    }
    return &texture_.at(filename);
}

sf::SoundBuffer*               ResourceManager::FetchSound      (std::string & filename)
{
    if(!sound_.contains(filename))
    {
        if(!texture_[filename].loadFromFile("Content/Sounds/"+filename))
        {
            LOG_INFO("Failed to load Sound : {}", filename);
            return nullptr;
        }
    }
    return &sound_.at(filename);
    
}
sf::Font*                      ResourceManager::FetchFont       (std::string & filename)
{
    if(!font_.contains(filename))
    {
        if(!font_[filename].openFromFile("Content/Fonts/"+filename))
        {
            LOG_INFO("Failed to load Fond : {}", filename);
            return nullptr;
        }
    }    
    return &font_.at(filename);
}

std::optional<sf::Music>       ResourceManager::FetchMusic      (std::string & filename)
{
    sf::Music music;
    
    if(!music.openFromFile("Content/Musics/"+filename))
    {
        LOG_INFO("Failed to load Music : {}", music);
        return std::nullopt;
    }
    return music;
}

