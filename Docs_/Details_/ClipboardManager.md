
# ClipboardManager

목적 : 운영체제(Windows/Mac 등)의 클립보드 영역에 텍스트를 보내거나 가져옵니다.

## std::string and sf::String

SFML의 특징: SFML은 내부적으로 유니코드(한글, 이모지 등) 처리를 위해 **sf::String** 이라는 자체 타입을 사용합니다.

자동 변환: 하지만 C++ 표준인 std::string을 넣어도 자동으로 sf::String으로 변환해 줍니다. 따라서 매개변수를 굳이 sf::String으로 안 바꾸고 친숙한 std::string으로 유지해도 됩니다.

## Wrapper for sf::Clipboard

SFML은 이미 sf::Clipboard라는 기능을 제공하지만, 엔진의 통일성을 위해 Manager 클래스로 감싸서(Wrapping) 만듭니다.

구현 메서드:

SetString(str): **sf::Clipboard::setString(str)** 을 호출. 
(복사하기 기능)

GetString(): **sf::Clipboard::getString()** 을 호출. 
(붙여넣기 기능)