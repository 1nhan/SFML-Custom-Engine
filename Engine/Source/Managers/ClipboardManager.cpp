#include <Managers/ClipboardManager.h>
#include <SFML/Window/Clipboard.hpp>

auto ClipboardManager::SetString(const sf::String& text) -> void
{
    sf::Clipboard::setString(text);
}
auto ClipboardManager::GetString() const -> sf::String     
{
    return sf::Clipboard::getString();
}