
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

**std::unordered_map** ,

**std::string**
, ResourceType을 사용.

- Key: **파일 이름(경로)** 을 문자열로 사용.

- Logic: 리소스 요청 시 맵을 확인하여 이미 로드된 리소스가 있다면 그것을 반환(재사용)하고, 없다면 새로 로드하여 맵에 저장합니다.

