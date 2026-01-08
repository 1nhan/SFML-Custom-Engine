#include "Core/Engine.h"
#include "Core/EngineConfig.h"
#include "Utils/Log.h"

/**
 * @brief Engine()
 * - constructor 간단한 생성자
 * @note 
 * - 윈도우에 창을 생성, 커스터마이징하는 곳
 */
Engine::Engine():
    window_{sf::VideoMode(sf::Vector2u(gConfig.WINDOWSIZE)),gConfig.WINDOWTITLE}
{
    window_.setIcon(sf::Image("Content/Textures/Icon.png"));
    window_.setMinimumSize(window_.getSize() / 2u);
 
    //로그인 비활성화시 오류 스트림을 아무데도 리디렉션하지 않는다.
    if(gConfig.disableSfmlLogs)
    {
        sf::err().rdbuf(nullptr);
    }

    context_.audio.SetGlobalVolume(gConfig.globalVolume);

    LOG_INFO("Window created");

}

/**
 * @brief IsRunning()
 * -
 * @note
 * -
 */
auto Engine::IsRunning() const  ->bool
{
    return window_.isOpen();
}

/**
 * @brief ProcessEvents()
 * -
 * @note 
 * - 이벤트 처리를 전용 기능으로 이동시키면서 루프를 최소화하는 시스템이 목적
 * -
 */
auto Engine::ProcessEvents  ()  ->void
{
    while(const std::optional<sf::Event> event = window_.pollEvent())
    {
        // event->visit([this](const auto& type){EngineVisitor{*this}.HandleEvent(type);});
        // EngineVisitor의 operator() 정의한 후
        event->visit(EngineVisitor{*this});
    }
}

/**
 * @brief Update() 
 * - 각 프레임을 업데이트해야 하는 엔진의 모든 항목을 업데이트할 곳
 * - EngineContext의 객체 context_를 통해 TimeManager에서 구현했던 Update함수를 실행시켜 계산된 deltaTime_ 접근할 수 있게합니다. 
 * -
 * -
*/
auto Engine::Update         ()  ->void
{
    context_.time.Update();
}

/**
 * @brief Render()
 * Render 창을 초기화(clear)하고 최종적으로 화면에 출력(display)한다.
 * @note 
 * - Render창의 clear()와 display()를 간단히 호출
 * - 이 후 이 두 줄사이의 모든 Entities를 그릴 것.
*/
auto Engine::Render         ()  ->void
{
    window_.clear();

    window_.display();
}


auto Engine::EventWindowClose()->void
{
    window_.close();

    LOG_INFO("Window closed");
}  

auto Engine::EventWindowResized(sf::Vector2u size)->void
{
    LOG_INFO("Window resized to: {}x{}", size.x, size.y);
}


auto Engine::EventWindowFocusLost()->void
{
    LOG_INFO("Window FocusLost");
}
auto Engine::EventWindowFocusGained()->void
{
    LOG_INFO("Window FocusGained");
}