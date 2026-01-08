#include "Managers/TimeManager.h"
#include "Core/EngineConfig.h"

/**
 * @brief Update()
 * -
 * -
 * -
 * -
 */
auto TimeManager::Update()               -> void
{
    const sf::Time currentTime = clock_.getElapsedTime();
    deltaTime_ = deltaTime_ - previousTime;

    if(deltaTime_ > gConfig.maximumDeltaTime)
        deltaTime_ = gConfig.maximumDeltaTime;

    previousTime = currentTime;
}

auto TimeManager::GetDeltaTime() const   ->float
{
    return deltaTime_.asSeconds();
}

auto TimeManager::GetElapsTime() const   ->float
{
    return clock_.getElapsedTime().asSeconds();
}