
# Log

목표: 빠르고 포맷팅이 쉬운 외부 로깅 라이브러리 도입.
폴더 구조: Utils/Log.h 파일을 생성하여 로깅 관련 기능을 모아둡니다.

## 1. Integrating spdlog

설정: CMakeLists.txt에 FetchContent를 사용하여 다운로드 및 링크.
특징: C++20의 std::format 스타일({})을 지원

## 2. Utility Folder & Custom Macros
- 매크로 사용 이유
  - 타이핑 절약 EX. LOG-INFO("...")
  - 의존성 분리       
  - 제어
  
## 3. [**Disabling SFML Default Logs**](Engine.md/#disabling-sfml-default-logs)

이유: SFML이 띄우는 내부 경고 메시지가 우리가 만든 로그와 섞이는 것을 방지.

방법: Config.json에 설정값을 추가하고, 비활성화 시 sf::err().rdbuf(NULL)을 호출하여 에러 출력을 차단합니다.

## 4. [**Testing with Events**](EngineVisitor.md/#testing-with-events)

이벤트 시스템(Visitor)이 잘 작동하는지 로깅으로 확인합니다.
