#include "AudioManager.h"

sf::SoundBuffer AudioManager::mainMenuBuffer;
sf::SoundBuffer AudioManager::explosionBuffer;
sf::SoundBuffer AudioManager::gameplayBuffer;

const sf::SoundBuffer& AudioManager::get_mainmenu_buffer()
{
    if (!mainMenuBuffer.loadFromFile(AUDIO_MAINMENU_PATH)) {
        std::cout << "Audio file could not be loaded\n";
    }
    return mainMenuBuffer;
}

const sf::SoundBuffer& AudioManager::get_explosion_buffer()
{
    if (!explosionBuffer.loadFromFile(AUDIO_EXPLOSION_PATH)) {
        std::cout << "Explosion audio file could not be loaded\n";
    }
    return explosionBuffer;
}

const sf::SoundBuffer& AudioManager::get_gameplay_buffer()
{
    if (!gameplayBuffer.loadFromFile(AUDIO_GAMEPLAY_PATH)) {
        std::cout << "Explosion audio file could not be loaded\n";
    }
    return gameplayBuffer;
}