
# AudioManager

Purpose : 

**중앙 집중식 오디오 제어** : 엔진의 마스터 볼륨을 한 곳에서 관리하여 모든 사운드/음악에 일괄 적용.

**공간 오디오(Spatial Audio) 지원** : 2D 게임 환경에서도 3D 좌표계를 활용하여 소리의 입체감(거리, 방향) 구현.

**SFML 리스너 추상화** : sf::Listener의 정적 함수들을 엔진 시스템 내에서 관리하기 편하도록 래핑(Wrapper).

## Head Requirement
**SFML/System/Vector3.hpp** : 리스너의 위치와 방향을 3D 좌표로 처리하기 위해 필수.

**SFML/Audio/Listener.hpp** : (구현부) 전역 오디오 속성을 제어하는 sf::Listener 클래스 사용.

## Implementation Details
GlobalVolume: 0~100 사이의 실수를 사용하여 엔진 전체 사운드 크기 조절.

Listener System (귀 역할):

Position: 리스너의 공간상 위치 설정 (2D 환경에서는 보통 Z=0 사용).

Direction: 플레이어가 바라보는 방향을 설정하여 앞/뒤/좌/우 소리의 차이 시뮬레이션.

Static Wrapper: 별도의 멤버 변수 없이 sf::Listener의 정적 메서드들을 중계하는 인터페이스 역할 수행.

## Integration
EngineContext 등록: 오디오 매니저를 EngineContext 멤버로 포함시켜 게임 어디서든 사운드 환경을 수정할 수 있도록 함.

외부 설정 연동: Config.json -> EngineConfig -> AudioManager 순으로 데이터가 흐르도록 하여, 코드 수정 없이 초기 볼륨을 조절할 수 있게 설계.

## Key Note
2D 게임의 3D 오디오: SFML은 3D 오디오 엔진을 기반으로 하므로, 2D 좌표(X, Y)를 3D 좌표(Vector3f)로 매핑하여 처리함.