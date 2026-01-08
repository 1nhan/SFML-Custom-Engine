#pragma once

#include <SFML/System/Vector2.hpp>
#include <SFML/System/Angle.hpp>
#include <SFML/Graphics/Color.hpp>

#include <random>
/**
 * @brief class RandomManager
 * -
 * - 
 */
class RandomManager
{
public:
    RandomManager   ();

    auto Int        (int min, int max)                  ->int   ;
    auto Float      (float min, float max)              ->float ;
    auto Bool       (float probability = 0.5f)          ->bool  ;
    auto Position   (sf::Vector2f min, sf::Vector2f max)->sf::Vector2f;
    auto Angle      (sf::Angle min, sf::Angle max)      ->sf::Angle;
    auto Color      (sf::Color min, sf::Color max)      ->sf::Color;

private:
    std::random_device  device_                 ;
    std::mt19937        generator_              ;  // direct member initialization.
};