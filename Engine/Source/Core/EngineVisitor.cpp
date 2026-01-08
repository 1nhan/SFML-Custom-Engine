#include "Core/EngineVisitor.h"
#include "Core/Engine.h"

auto EngineVisitor::operator()(const sf::Event::Closed&)      ->void
{
    engine_.EventWindowClose();
}

auto EngineVisitor::operator()(const sf::Event::Resized&resized)->void
{
    engine_.EventWindowResized(resized.size);
}

auto EngineVisitor::operator()(const sf::Event::FocusLost&)    ->void
{
    engine_.EventWindowFocusLost();
}
auto EngineVisitor::operator()(const sf::Event::FocusGained&)  ->void
{
    engine_.EventWindowFocusGained();
}