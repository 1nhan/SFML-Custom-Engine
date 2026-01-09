# Input Bindings & Gamepad Mapping
- Purpose
   - 입력 추상화: 하드웨어에 종속적인 입력을 논리적인 '액션' 바인딩으로 분리하여 유연성 확보.

   - 크로스 플랫폼 대응: 서로 다른 게임패드 레이아웃(Xbox, PlayStation)을 하나의 논리적 버튼 체계로 통합.

   - 유연한 타입 관리: 키보드, 마우스, 게임패드 버튼 및 축 입력을 단일 인터페이스로 관리.

## Head Requirement 

**sfml/Window.hpp** : 키보드, 마우스, 조이스틱 등 모든 SFML 입력 타입 접근.

"<variant>" : 상속 구조 없이 여러 입력 타입을 하나로 묶는 'std::variant<Keyboard, Mouse, Gamepad, Axis>' 구현.

<optional>: 특정 장치에 존재하지 않는 버튼 처리를 위해 사용.

- Implementation Details (구현 세부 사항)
GamePadButton Enum: West, South, East, North 등 중립적인 명칭으로 컨트롤러 버튼 정의.

Input Structs:

Keyboard: 레이아웃 독립적인 ScanCode 사용.

Axis: 아날로그 입력의 민감도를 조절하는 threshold 값 포함 (0.0~1.0).

Binding Alias: std::variant를 사용하여 서로 다른 구조체들을 Binding이라는 하나의 타입으로 취급.

Mapping Logic:

Vendor Detection: Microsoft 벤더 ID를 기준으로 Xbox와 그 외(PlayStation 등) 매핑 분기 처리.

Array Mapping: 논리적 열거형 순서와 하드웨어 인덱스를 매칭하는 고정 배열 사용.

- Integration (통합)
Utils/InputBindings: 모든 입력 정의와 매핑 로직을 별도 유틸리티 파일로 격리하여 유지보수성 향상.

Logical ↔ Hardware Conversion: 엔진 내부 로직은 '논리 버튼'만 알면 되고, 실제 입력을 받을 때만 하드웨어 인덱스로 변환하여 SFML과 통신.

- Key Note (핵심 참고 사항)
ScanCode 사용 이유: 일반 Key 대신 ScanCode를 사용하여 프랑스(Azerty)나 한국 등 키보드 배열이 달라도 물리적으로 같은 위치의 키가 동일하게 작동하도록 보장함.

Analog Triggers: Xbox 등 일부 기기에서 트리거(L2, R2)는 디지털 버튼이 아닌 'Axis(축)'로 취급되므로, 매핑 배열에서 -1로 표시하고 optional로 처리하는 예외 로직이 중요함.

Hexadecimal (16진수): 벤더 ID(예: 0x045E)와 같이 하드웨어 식별 번호는 관습적으로 16진수를 사용하여 가독성을 높임.