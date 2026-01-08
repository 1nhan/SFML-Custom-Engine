
# EngineConfig

목표: 게임의 설정값(제목, 해상도 등)을 관리하는 중앙 시스템 구축.

## EngineConfig.h / EngineConfig.cpp

**Variable**:

String windowTitle

Vector2f windowSize (Vector2f - 위치 계산의 편의를 위해 float 사용)

전역 접근: inline const EngineConfig gConfig;를 통해 어디서든 접근 가능하게 설정.

## Settings

### 1. Integrating **nlohmann/json**

이유: 하드코딩을 피하고 설정을 유연하게 바꾸기 위함.

방법: CMakeLists.txt에 FetchContent를 사용하여 라이브러리를 자동으로 다운로드하고 링크함.

특징: C++에서 JSON을 마치 Map이나 배열처럼 직관적으로 다룰 수 있게 해줌.

### 2. Creating the JSON File

**Content/Config.json** 파일을 생성하여 데이터를 저장합니다.

형식: Key-Value 쌍

### 3. Reading JSON in C++

- 파일 읽기
  - **std::ifstream**으로 파일을 엽니다.
  
- 안전 장치
  - **assert(file.is_open())**을 사용하여 파일이 없으면 프로그램을 강제 종료(Crash)시켜 개발자가 바로 알 수 있게 합니다.

- 파싱
  - **nlohmann::json json = nlohmann::json::parse(file)**을 통해 텍스트를 코드에서 쓸 수 있는 객체로 변환합니다.

- 값 할당
```
windowDefaultSize   = {json["windowDefaultSize"][0],json["windowDefaultSize"][1]};
windowMinimumSize   = {json["windowMinimumSize"][0],json["windowMinimumSize"][1]};
windowTitle         = json["windowTitle"];
disableSfmlLogs     = json["disableSfmlLogs"];
```

---

## [The Lag Spike Problem](TimeManager.md/#the-lag-spike-problem)

해결책 (Clamping): "아무리 렉이 걸려도, 논리적으로는 최대 0.05초(예시)만 지났다고 치자."라고 상한선을 둡니다.

```Config.json
"maximumDeltaTime"  :   0.03
```