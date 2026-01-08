

# EngineVisitor

**The Visitor Pattern Architecture**:
이 구조의 핵심은 EngineVisitor라는 중개자를 두는 것입니다.

**struct EngineVisitor**:

SFML의 sf::Event를 받아 타입을 확인합니다.

Engine의 private 메서드를 호출하여 실제 작업을 수행합니다.

## Implementation Details

**Forward Declaration** (전방 선언):

EngineVisitor.h에서 #include "Engine.h"를 하는 대신 **class Engine;**이라고만 적습니다.

이유: 서로가 서로를 포함(Include)하는 순환 의존성 오류를 막기 위함입니다. 

**operator()** Overloading:

함수 이름을 HandleEvent 대신 operator()로 지으면, C++ 표준 라이브러리의 std::visit 기능을 사용하여 코드를 극도로 단축할 수 있습니다.

결과: 이벤트 루프가 단 한 줄로 줄어듭니다. -> **std::visit(EngineVisitor{*this}, event);**

---

## [**Testing with Events**]()

이벤트 시스템(Visitor)이 잘 작동하는지 로깅으로 확인합니다.

Resize Event: 창 크기를 조절할 때마다 LOG_INFO("Resized: {}, {}", w, h) 출력.

Focus Event: 창을 클릭하거나 다른 창으로 넘어갈 때 Focus Gained/Lost 출력.