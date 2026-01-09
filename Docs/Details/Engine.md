
# Engine

## Implementing the Engine Class (Engine.h & Engine.cpp)

**sf::RenderWindow window** : 게임 화면을 담당합니다.

### Constructor:

**sf::VideoMode(800, 800)** 으로 해상도를 설정합니다.

**window.setIcon(...)** : sf::Image를 이용해 아이콘을 로드하고 설정합니다. (텍스처 폴더 활용)

**window.setMinimumSize(...)** : 창이 너무 작아져서(0이 되어) 에러가 나는 것을 방지하기 위해 최소 크기를 설정합니다.

### [Engine Loop](Main.md)

**IsRunning()** : 

윈도우가 열려있는지(isOpen()) 확인하여 루프 지속 여부를 결정합니다.

**ProcessEvents()**: 

pollEvent를 사용해 윈도우 닫기 버튼 등 사용자 입력을 처리합니다. (지금은 닫기 기능만 구현)

**Update()**: 

게임 로직을 갱신하는 곳입니다. (현재는 비어있음, 추후 매니저들 업데이트 예정)

**Render()**:

window.clear(): 이전 프레임 지우기

(그리기 작업 들어갈 자리)

window.display(): 화면에 송출

-----

## [**The Visitor Pattern Architecture**](/EngineVisitor.md) :

이 구조의 핵심은 EngineVisitor라는 중개자를 두는 것입니다.

더 이상 sf::Event를 직접 해석하지 않습니다.

EventWindowClose() 같은 구체적인 행동 함수만 가집니다.

**friend struct EngineVisitor**: 비지터가 자신의 private 함수를 부를 수 있게 허락해 줍니다.



---

## [**Disabling SFML Default Logs**](/Log.md)
이유: SFML이 띄우는 내부 경고 메시지가 우리가 만든 로그와 섞이는 것을 방지.

방법: Config.json에 설정값을 추가하고, 비활성화 시 sf::err().rdbuf(NULL)을 호출하여 에러 출력을 차단합니다.