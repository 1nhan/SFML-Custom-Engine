
# SaveManager

목적 : JSON파일을 사용하여 데이터를 쉽게 저장하고 불러올 수 있고 점수, 잠금 해제된 레벨, 플레이어 설정등과 같은 값들을 저장하고 불러오는 간단한 방법을 제공하게 될 것

## 1. RAII Pattern in Save System

개념: **RAII (Resource Acquisition Is Initialization) 패턴**의 변형입니다.

Constructor (생성자): 게임 시작 시 save.json 파일을 읽어서 메모리(nlohmann::json values)에 로드합니다.

Destructor (소멸자): 게임이 종료될 때(객체 파괴 시) 메모리에 있던 데이터를 save.json 파일에 자동으로 덮어씁니다.

장점: 게임 종료 시점에 깜빡하고 Save() 함수를 호출하지 않아 데이터가 날아가는 실수를 방지합니다.

## 2. Generic Methods with Templates

문제: int, float, string 등 저장할 데이터 타입마다 SetInt, SetFloat 함수를 따로 만드는 것은 비효율적입니다.

구현: 헤더 파일에 직접 정의하며, **auto 키워드**를 활용해 유연하게 값을 받습니다.

## 3. Optimization: std::string_view

기존: std::string을 함수 인자로 받으면, "Score" 같은 문자열 리터럴을 넘길 때 불필요한 메모리 복사/할당이 일어날 수 있습니다.

개선: C++17에서 도입된 **std::string_view**를 사용합니다.

문자열을 복사하지 않고 **"원본 문자열의 주소와 길이"**만 가볍게 들고 있습니다.

주의사항: string_view는 데이터를 **소유(Own)**하지 않으므로, 함수 인자로만 쓰고 멤버 변수로는 저장하면 안 됩니다. (원본이 사라지면 댕글링 포인터 발생)

## 4. Implementation Checklist (구현 체크리스트)

파일 경로: "content/save.json" (없으면 자동 생성)

JSON 포맷팅: file << values.dump(4); (4칸 들여쓰기로 사람이 읽기 편하게 저장)

EngineContext: SaveManager 인스턴스를 추가하여 게임 어디서든 접근 가능하게 설정.