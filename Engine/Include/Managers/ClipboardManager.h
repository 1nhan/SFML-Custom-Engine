#pragma once
#include<SFML/System/String.hpp>

class ClipboardManager
{
public:
    auto SetString(const sf::String&) -> void;
    auto GetString() const -> sf::String;
};