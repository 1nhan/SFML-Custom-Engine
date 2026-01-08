# Engine Architecture

목표: 매번 코드를 새로 짜지 않고, 16개 이상의 게임을 찍어낼 수 있는 **'재사용 가능한 모듈식 엔진'** 을 만듭니다.

구조: 모든 기능(렌더링, 입력, 리소스 등)을 **Manager**로 만들고, 이들을 **EngineContext**라는 하나의 도구상자에 담아 관리합니다.

효과: 게임 로직(Scene)은 엔진 내부를 몰라도 Context만 통해 필요한 기능을 가져다 쓸 수 있어 개발 생산성이 극대화됩니다.

### \Core

### [\Engine](Documents/Engine.md)

역할: main 함수에서 생성되며, 게임 루프(이벤트 처리 → 업데이트 → 렌더링)를 돌립니다.

특징: 엔진 자체는 게임(테트리스, 바운스 등)에 대해 아무것도 모릅니다. 단지 등록된 게임을 실행시켜 줄 뿐입니다.

### [\EngineContext](Documents/)

역할: 모든 **Manager**들의 인스턴스를 담고 있는 컨테이너입니다.

개발 포인트: 일종의 서비스 로케이터(Service Locator) 패턴입니다. 클래스끼리 수많은 포인터를 주고받는 대신, 이 Context 하나만 있으면 어디서든 렌더러나 리소스 매니저에 접근할 수 있습니다. 전역 변수의 단점을 해결하는 핵심 구조입니다.

### [\EngineConfig](Documents/EngineConfig.md)

역할: 해상도, 타이틀, 볼륨 같은 고정 설정값을 한곳에 모아둔 구조체입니다. 하드코딩을 방지합니다.

## \Managers

모든 매니저는 EngineContext 안에 저장됩니다.

### [\Verify]()

: assert와 비슷합니다. 포인터가 null인지 확인하는 등 치명적인 오류를 잡아내 프로그램을 안전하게 멈춥니다.

### [\RandomManager.h](Documents/RandomManager.md)
: 난수(랜덤) 생성기입니다. 위치, 색상 등을 랜덤하게 뿌릴 때 씁니다.

### [\TimeManager](Documents/TimeManager.md)
: DeltaTime을 계산합니다. 프레임이 튀어도 게임 속도를 일정하게 유지해 줍니다.

### [\SaveManager](Documents/SaveManager.md) 
(with nlohmann/json): 게임 데이터를 JSON 파일로 저장하고 불러옵니다.

### [\ResourceManager](Documents/ResourceManager.md)
: 텍스처, 사운드, 폰트를 로딩합니다. 중요: 같은 파일을 두 번 로딩하지 않도록 메모리를 관리(캐싱)합니다.

### [\AudioManager](Documents/)
: 전체 볼륨 조절 및 사운드 재생을 담당합니다.

### [\InputManager](Documents/) & [\InputBindings](Documents/)
: 키보드/마우스 입력을 추상화합니다. "Space 키"가 아니라 "Jump 동작"으로 연결해 줍니다.

### [\RenderManager](Documents/)
: 화면에 그림을 그리는 화가입니다. 배경, 캐릭터, 이펙트 등을 순서대로 그립니다.

### [\GuiManager ](Documents/)
(with TGUI/Ptgui)
: 버튼, 메뉴 같은 UI를 그립니다.

### [\ScreenshotManager](Documents/)
: 게임 화면을 캡처해서 이미지로 저장합니다.

### [\ClipboardManager](Documents/ClipboardManager.md)
: 복사/붙여넣기 기능을 지원합니다.

## Game Logic
Scene (Base Class)

역할: 모든 게임(레벨)의 부모 클래스입니다. Start, Update, Render 같은 생명주기 함수를 가집니다.

개발 포인트: 새로운 게임을 만들 때는 이 Scene을 상속받기만 하면 됩니다.

### [\SceneManager](Documents/)
: 씬을 교체(전환)하는 역할을 합니다. (메뉴 → 인게임 → 게임오버)

### [\SceneFactory](Documents/)
: 게임의 이름(문자열)을 주면 해당 씬을 생성해 주는 공장입니다.

### [\Overlay](Documents/)
: 게임 위에 겹쳐서 뜨는 '일시정지 메뉴' 같은 것입니다. 현재 씬을 방해하지 않고 작동합니다.

## Utilities & Effects

### [\Log](Documents/Log.md)
(with spdlog): std::cout은 느려서 안 씁니다. 전문 로깅 라이브러리를 써서 오류나 정보를 콘솔에 예쁘고 빠르게 출력합니다.

### [\Effects](Documents/)
: 화면 전체에 적용되는 후처리 효과(필터, 블룸 등)입니다.

### [\Cooldown](Documents/)
: "공격 후 3초 대기" 같은 타이머 기능을 쉽게 구현하게 해주는 유틸리티입니다.

### [\SceneUtils](Documents/)
: 충돌 체크, 거리 계산 등 자주 쓰이는 수학 함수들을 모아둔 것입니다.
