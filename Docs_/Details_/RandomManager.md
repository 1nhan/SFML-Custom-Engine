
# RandomManager

목표: 전역 변수 대신 RandomManager 클래스를 통해 난수를 관리.

멤버 변수:
std::random_device: 시드(Seed) 값을 만드는 하드웨어 장치.

std::mt19937: 메르센 트위스터(Mersenne Twister) 알고리즘을 사용하는 고품질 난수 생성기.

## Implementation

### 기본형

Int(min, max): **uniform_int_distribution** 사용 (모든 숫자가 나올 확률이 같음).

Float(min, max): **uniform_real_distribution** 사용.

Bool(chance): **bernoulli_distribution** 사용 (동전 던지기, 확률 조작 가능).

### SFML 타입형

Position(min, max): X, Y 각각 랜덤 Float 호출.

Angle(min, max): 랜덤 Float 호출 후 sf::degrees()로 변환.

Color(min, max): R, G, B 각각 랜덤 Int 호출.

sf::Color는 0~255 범위의 Uint8_t 타입.