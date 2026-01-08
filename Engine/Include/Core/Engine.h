#pragma once
#include <SFML/Graphics.hpp>
#include "Core/EngineVisitor.h"
#include "Core/EngineContext.h"

class Engine
{
public:
    Engine();

    auto IsRunning() const  ->bool                          ;

    auto ProcessEvents  ()  ->void                          ;
    auto Render         ()  ->void                          ;
    auto Update         ()  ->void                          ;

private:                    
    sf::RenderWindow    window_                             ;
    EngineContext       context_                            ;
    
    
private:
    friend              EngineVisitor                       ;
    // 이벤트 처리와 실제 동작을 분리
    auto EventWindowClose()                         ->void  ;
    auto EventWindowResized(sf::Vector2u size)      ->void  ;
    auto EventWindowFocusLost()                     ->void  ;
    auto EventWindowFocusGained()                   ->void  ;
};
