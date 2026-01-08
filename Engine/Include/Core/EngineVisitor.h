#pragma once

#include <SFML/Window/Event.hpp>

struct EngineVisitor
{
    class Engine& engine_   ;   // forward declaration    

    auto operator()(const sf::Event::Closed&)       ->void  ;
    auto operator()(const sf::Event::Resized&)      ->void  ;
    auto operator()(const sf::Event::FocusLost&)    ->void  ;
    auto operator()(const sf::Event::FocusGained&)  ->void  ;
    
    // 명시적으로 처리되지 않는 모든 이벤트를 안전하게 무시하려는 목적 
    auto operator()(const auto&)                   ->void{};
};
