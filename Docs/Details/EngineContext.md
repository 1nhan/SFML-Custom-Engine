
# EngineContext

목적 : 엔진 아키텍처에서 가장 중요한 '허브' 역할, 엔진의 모든 주요 기능(Manager)들을 담아두는 '도구 상자' 또는 **'컨테이너'**입니다.

## Why use Context?

### Modularity
: Engine 클래스가 수십 개의 매니저 변수로 지저분해지는 것을 막습니다.

### Accessibility
: 나중에 Player나 Scene 같은 게임 로직이 엔진 기능이 필요할 때, 매니저들을 일일이 넘겨주는 대신 context 하나만 툭 던겨주면 그 안에서 필요한 걸 다 꺼내 쓸 수 있습니다. (매우 효율적!)

## Implementation Steps

- File Creation: Core/EngineContext.h 파일 생성.

- Struct Definition: 내부는 비어있는 struct EngineContext {}; 정의.

- Integration:
  - Engine.h에 #include "EngineContext.h" 추가.
  - Engine 클래스 안에 EngineContext context; 멤버 변수 선언.