
# ResourceManager

목적 : 게임 내에서 사용되는 외부 자산(Texture, Sound, Font, Music)을 중앙에서 통합 관리하여 코드 중복을 방지하고, 리소스의 중복 로딩을 막아 효율성을 높이는 시스템을 구축합니다.

## Header Requirements

- SFML Headers: 
    - **sf::Texture** , 
    - **sf::SoundBuffer** , 
    - **sf::Font** , 
    - **sf::Music**  등 리소스 타입 정의를 위해 필요.

- Standard Headers:
    - **<unordered_map>** : 리소스 캐싱(저장)용 컨테이너.
    - **<string$>$** : 파일 경로를 key로 사용.
    - **<optional$>$** : 음악 로드 실패 시 빈 값을 안전하게 반환하기 위해 사용.

## Storage Strategy (Caching)

- Container: 

  - **std::unordered_map** ,
  **std::string** , 
  **ResourceType** (sf::Texture, sf::SoundBuffer, sf::Font)을 사용.

- Key: **파일 이름(경로)** 을 문자열로 사용.

- Logic: 리소스 요청 시 맵을 확인하여 이미 로드된 리소스가 있다면 그것을 반환(재사용)하고, 없다면 새로 로드하여 맵에 저장합니다.

## Implementation Details

- The 'Fetch' Logic: Get과 Load를 합친 개념. 맵을 확인하여 존재하면 반환하고, 없으면 새로 로드한 후 저장.

- Bracket Operator[ ]: **map[filename].loadFromFile(...) 형태** 로 리소스의 생성과 로딩을 간결하게 처리합니다.

- Memory Management:

  - Texture, Sound, Font: **unordered_map에 저장하고 포인터(Pointer)** 로 반환하여 재사용.

  - Music: 용량이 크기 때문에 메모리에 저장하지 않고 스트리밍 방식으로 처리. **std::optional을 통해 값(Value)** 으로 반환.


- Integration: 완성된 매니저를 **Core/EngineContext.h** 에 등록하여 게임 전체에서 접근 가능하도록 설정합니다.


## Key Notes

- Directory Structure: content/fonts, content/musics, content/sounds 등으로 **폴더를 구분하여 관리** 합니다.

- String Selection: unordered_map과의 호환성 문제로 std::string_view 대신 **const std::string&를 매개변수** 로 사용.

- 폰트 로드 시 openFromFile 함수를 사용함.