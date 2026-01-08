#include "Managers/RandomManager.h"

RandomManager::RandomManager   ():
    generator_{device_()}
{}

auto RandomManager::Int(int min, int max)->int               
{
    return std::uniform_int_distribution(min,max)(generator_);
}  

auto RandomManager::Float(float min, float max)->float           
{
    return std::uniform_real_distribution(min,max)(generator_);
}

auto RandomManager::Bool(float probability)->bool            
{
    return std::bernoulli_distribution(probability)(generator_);
}

auto RandomManager::Position(sf::Vector2f min, sf::Vector2f max)->sf::Vector2f      
{
    return sf::Vector2f(Float(min.x,max.x), Float(min.y, max.y));
}  

auto RandomManager::Angle(sf::Angle min, sf::Angle max)      ->sf::Angle       
{
    return sf::degrees(Float(min.asDegrees(), max.asDegrees()));
}

auto RandomManager::Color(sf::Color min, sf::Color max)      ->sf::Color       
{
    return {(uint8_t)Int(min.r,max.r), // R
            (uint8_t)Int(min.g,max.g), // G
            (uint8_t)Int(min.b,min.b)};// B
}

