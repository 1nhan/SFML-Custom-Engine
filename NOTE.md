# Syntax Note for projects

## 📖 소개
projects에서 사용되었던 C++ 문법 요소를 정리하고 공부할 목적으로 작성되었습니다.

---
## **sfd::erase_if**
- C++20에서 추가된 함수로, 컨테이너 안의 요소 중 특정 조건(Predicate)을 만족하는 모든 요소를 한 번에 제거합니다.
- 기존에는 std::remove_if + erase 조합을 써야 했는데, 이제는 한 줄로 처리할 수 있어 코드가 훨씬 깔끔해졌습니다.
- 반환값은 제거된 요소의 개수입니다.

#### 지원되는 컨테이너
- 순차 컨테이너: vector, deque, list, forward_list, string
- 연관 컨테이너: map, multimap, set, multiset, unordered_map, unordered_set 등

#### 동작 원리

1. 순차 컨테이너
- vector / deque / string
  - 내부적으로 remove_if처럼 조건을 만족하지 않는 요소들을 앞으로 압축(compaction)합니다.
  - 조건을 만족하는 요소들은 뒤쪽에 몰리게 되고, 마지막에 erase로 한 번에 잘라냅니다.
  - 시간 복잡도: O(n) (전체 순회 필요)
  - 주의: vector나 string은 요소 이동 때문에 모든 iterator, 참조가 무효화됩니다.
- list / forward_list
  - 노드 기반이라 조건을 만족하는 노드를 순회하면서 바로 erase합니다.
  - 다른 노드의 iterator는 그대로 유효합니다.
  - 시간 복잡도: O(n)

2. 연관 컨테이너 (map, set 등)
- 트리 기반 컨테이너는 노드를 순회하면서 조건을 만족하면 erase(it++)로 제거합니다.
- 각 삭제는 내부적으로 트리 재균형이 일어나지만, 전체적으로는 O(n)에 가까운 성능을 가집니다.
- iterator 무효화: 삭제된 요소만 무효화되고, 나머지는 그대로 유효합니다.
- 해시 기반 컨테이너(unordered_map, unordered_set)도 비슷하게 버킷을 순회하며 조건을 만족하는 노드를 제거합니다.

---

## **std::size_t**
- C++ 표준 라이브러리에서 제공하는 부호 없는 정수 타입
- 헤더: <cstddef>에 정의되어 있음
- 실제 타입: 플랫폼에 따라 unsigned int, unsigned long, unsigned long long 중 하나로 매핑됨
- 의미: 크기(size), 갯수(count), 인덱스(index)를 표현하기 위한 전용 타입

#### 주요 특징
- 항상 0 이상: 음수를 표현할 수 없음 → 크기/인덱스에 적합
- 플랫폼 의존적 크기: 32비트 시스템에서는 32비트, 64비트 시스템에서는 64비트로 정의됨
- 표준 일관성:
- sizeof 연산 결과 → size_t
- STL 컨테이너의 .size(), .capacity() 반환 타입 → size_t

#### 주의할 점
- int와 혼용 시 주의: 음수가 size_t로 변환되면 매우 큰 값으로 바뀜
- 일반적인 수학 연산에는 int, 인덱스/갯수에는 size_t를 쓰는 습관이 안전합니다.

---

## std::ofstream
- 정의: C++ 표준 라이브러리에서 제공하는 출력 파일 스트림 클래스
- 역할: 텍스트나 데이터를 파일에 쓰기(write) 위해 사용
- 헤더: <fstream>에 정의되어 있음
- 상속: std::ofstream은 std::ostream을 상속받아 파일에 출력하는 기능을 가짐

#### 주요 함수 및 모드
```
- file.open("File") //파일 열기
- file.close() //파일 닫기
- file << data //파일에 데이터 쓰기
- std::ios::app // 기존 파일에 추가 (Append)
- std::ios::trunc // 기존 내용을 지우고 새로 쓰기
- std::ios::binary // 바이너리 모드로 열기
```

---

## sf::FloatRect

- 부동소수점 좌표 기반 직사각형을 표현하는 SFML 구조체

---

## std::clamp

- C++17부터 표준 라이브러리에 추가된 함수 템플릿으로, 값이 특정 범위 안에 들어오도록 제한(clamp)하는 기능을 합니다.
- C++17 이상에서만 사용 가능 (<algorithm> 헤더 필요).


#### 기본 정의

```
template< class T >
const T& clamp( const T& v, const T& lo, const T& hi );
```
- v : 제한하려는 값
- lo : 하한값 (최소)
- hi : 상한값 (최대)
- 반환값 : v가 lo보다 작으면 lo, hi보다 크면 hi, 그 외에는 v 그대로 반환
- lo 값은 반드시 hi 값보다 작거나 같아야 합니다. 그렇지 않으면 정의되지 않은 동작(UB)이 발생할 수 있습니다.
- 반환 타입은 const T&이므로, 원본 값이 그대로 반환될 수 있습니다.

---

## std::optional
- 정의 위치: <optional> 헤더에 정의됨.
- 형식: template<class T> class optional;
- 의미: optional<T>는 값을 포함하거나(nullopt) 포함하지 않을 수 있는 객체.
- 주요 사용 사례:
  - 실패할 수 있는 함수의 반환값
  - 값의 존재 여부를 명시적으로 표현해야 할 때
  - std::pair<T,bool> 같은 패턴을 대체

#### 동작 방식
- 값 포함 여부
- optional은 특정 시점에 값을 포함하거나 포함하지 않음 두 가지 상태 중 하나.
- optional<T>가 bool로 변환될 때:
- 값이 있으면 → true
- 값이 없으면 → false
- 값을 포함하는 경우
- T 타입 값으로 초기화/할당
- 다른 optional로부터 초기화/할당
- 값을 포함하지 않는 경우
- 기본 초기화
- std::nullopt로 초기화/할당
- reset() 호출

#### 주요 멤버 함수
- has_value() → 값 존재 여부 확인
- value() → 값 반환 (없으면 예외 발생)
- value_or(default) → 값이 없을 경우 기본값 반환
- reset() → 값을 제거하여 비어있는 상태로 만듦
- emplace(args...) → 내부에 새 값 생성

---

## #include <SFML/GpuPreference.hpp>
**SFML_DEFINE_DISCRETE_GPU_PREFERENCE**
- NVIDIA Optimus 환경 → 외장 GPU(NVIDIA) 사용
- AMD Enduro 환경 → 외장 GPU(AMD) 사용
- 내장 GPU만 있는 경우 → 그냥 내장 GPU 사용 (영향 없음)
- 이유: 듀얼 GPU 환경에서 성능 저하를 막고, 항상 고성능 GPU를 사용하도록 보장하기 위해.
- 효과: 외장 GPU가 자동 선택됨 → 렌더링 성능 향상.
- 영향 없는 경우: 데스크톱 PC(외장 GPU만 있는 경우)나 내장 GPU만 있는 경우에는 그냥 무시됨.
이 매크로는 **“내 프로그램은 그래픽 성능이 중요하니 외장 GPU를 써 달라”**는 신호를 드라이버에 주는 장치입니다.

---

## forward declaration
- Forward declaration(전방 선언)은 C++에서 특정 타입이나 함수가 “존재한다”는 사실만 미리 알려주는 선언 방식으로, 헤더 파일을 포함하지 않고도 이름만 사용할 수 있게 해줍니다. 주로 순환 참조 문제를 피하거나 컴파일 속도를 줄이는 데 활용됩니다.

- **순환 참조 방지**
  - 클래스 A와 B가 서로를 포함할 때, 헤더 파일 간의 무한 포함 문제를 막을 수 있습니다.
- **컴파일 속도 개선**
  - 불필요하게 큰 헤더를 포함하지 않고, 필요한 곳에서만 정의를 가져오므로 빌드 시간이 줄어듭니다.
- **의존성 최소화**
  - 클래스 내부에서 포인터나 참조만 사용한다면 정의가 필요 없으므로, 전방 선언으로 의존성을 줄일 수 있습니다.
#### 주의할 점

- 포인터/참조만 가능: 전방 선언된 타입의 크기나 내부 멤버를 알 수 없으므로, 객체 자체를 멤버 변수로 선언하거나 메서드를 직접 호출할 수는 없습니다.
- 정의 필요: 실제로 객체를 생성하거나 메서드를 호출하려면 반드시 해당 타입의 정의가 포함된 헤더를 가져와야 합니다.
- inline 함수, 템플릿에서는 전방 선언만으로는 부족합니다. 정의가 반드시 필요합니다.

---

## nlohmann_json

- 하드코딩 대신 외부 JSON 라이브러리(nlohmann/json) 를 사용한다.
- JSON(JavaScript Object Notation)은 키-값 쌍으로 구성된 텍스트 기반 설정 포맷으로 업계에서 널리 사용된다.
- CMakeLists.txt에 라이브러리 추가 후 빌드하면 자동으로 다운로드 및 프로젝트에 통합된다.
- 이후 Config.json 파일을 content 폴더에 생성한다.

```CMakeLists.txt
set(SPDLOG_USE_STD_FORMAT ON)
FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_MakeAvailable(json)
target_link_libraries(nlohmann_json::nlohmann_json)
```

---

## assert

- <cassert>는 C++ 표준 라이브러리 헤더로, 프로그램 실행 중 특정 조건을 검사하는 assert 매크로를 제공합니다. 조건이 거짓이면 프로그램을 즉시 종료하여 디버깅에 활용할 수 있습니다.
  - 헤더 위치: <cassert> (C++), <assert.h> (C)
  - 주요 매크로: assert(expression)
  - expression이 false일 경우, 프로그램은 오류 메시지를 출력하고 종료.
  - true일 경우 아무 일도 일어나지 않음.
  - Runtime 검사

---

## spdlog

- 로깅은 단순히 프로그램이 실행되는 동안 무엇을 하고 있는지 추적할 수 있도록 터미널이나 파일에 메시지를 쓰는 행위입니다.
- 디버깅, 성능 모니터링, 이벤트 흐름 이해에 매우 유용합니다.
- 빠르고 가벼우며 통합하기 쉬운 spdlog라는 매우 인기 있는 라이브러리를 사용합니다.

```CMakeLists.txt
FetchContent_Declare(logs URL https://github.com/gabime/spdlog/archive/refs/tags/v1.16.0.tar.gz)
FetchContent_MakeAvailable(logs)
target_link_libraries(spdlogs::spdlogs)
```

---

## std::format
- C++20에서 도입된 문자열 포매팅 함수로, Python의 str.format처럼 {} 플레이스홀더를 사용해 값을 삽입할 수 있습니다. 
- 기존의 printf나 ostringstream보다 안전하고 직관적이며, 강력한 포맷 지정자를 제공합니다.
  - 헤더: <format>
  - 함수: std::format(format_string, args...)
  - 반환값: 포맷팅된 std::string
  - 플레이스홀더: {} → 인자 순서대로 치환
  - 포맷 지정자: {:specifier} → 출력 형식 제어


---

## std::variant

- std::optional<T>: $T$ 이거나, 아무것도 없거나 (2가지 상태)
- std::variant<A, B, C>: $A$ 이거나, $B$ 이거나, $C$ 이거나... (여러 상태 중 하나)
- C++17에서 도입된 아주 강력한 기능으로, **"무엇이든 변신할 수 있는 변수"**입니다.

✅ 모던 방식 (std::variant)
variant는 "지금 내가 뭘 들고 있는지" 기억합니다. 그래서 안전합니다. 이를 Type-Safe Union이라고 부릅니다.