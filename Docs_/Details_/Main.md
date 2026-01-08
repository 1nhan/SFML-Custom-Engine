
# Main
Engine 클래스의 인스턴스를 생성합니다.

while (engine.IsRunning()) 루프 안에서 ProcessEvents -> Update -> Render 순서로 호출하여 게임을 실행합니다.

## GPU Optimization
노트북 성능 이슈 해결: 내장 그래픽 대신 외장 그래픽(Nvidia/AMD)을 강제로 사용하게 설정합니다.

방법: **SFML_DEFINE_DISCRETE_GPU_PREFERENCE** 매크로를 사용합니다.