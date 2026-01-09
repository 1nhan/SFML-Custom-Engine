
# TimeManager

목적: 프레임 레이트(FPS)와 상관없이 게임 내의 움직임이 두 개의 다른 컴퓨터에서 동일한 속도로 발생하도록 보장하고 싶을 때 필수적

## What is Delta Time?

정의: 이전 프레임과 현재 프레임 사이의 시간 간격 (1프레임이 걸린 시간).

이동 공식: 이동거리 = 속력 * 델타타임

이렇게 하면 Update 호출 횟수가 달라도 1초 동안 이동한 총 거리는 같아집니다.

## [The Lag Spike Problem](EngineConfig.md/#the-lag-spike-problem)

상황: 사용자가 윈도우 창을 드래그하거나 컴퓨터가 순간적으로 멈추면?

결과: 캐릭터가 벽을 뚫고 나가거나(Tunneling), 맵 밖으로 순간이동합니다.

해결책 (**Clamping**): "아무리 렉이 걸려도, 논리적으로는 최대 0.05초(예시)만 지났다고 치자."라고 상한선을 둡니다.


## Implementation Details

**sf::Clock** & **sf::Time**: SFML이 제공하는 고정밀 타이머 클래스를 사용합니다.

std::min: 델타 타임과 최대값 중 더 작은 것을 선택하여 상한선을 적용합니다.

Friend Class :

Update() 함수를 private으로 숨깁니다.

**friend class Engine;** 선언을 통해 오직 엔진만 시간을 흐르게 할 수 있도록 권한을 줍니다. (일반 게임 로직이 실수로 시간을 조작하는 것 방지)