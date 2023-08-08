#include "AudioManager.h"

sf::SoundBuffer AudioManager::mainMenuBuffer;
sf::SoundBuffer AudioManager::explosionBuffer;
sf::SoundBuffer AudioManager::gameplayBuffer;

void AudioManager::instantiate_audio()
{
    if (!mainMenuBuffer.loadFromFile(AUDIO_MAINMENU_PATH)) {
        std::cout << "Main Menu audio file could not be loaded\n";
    }
    if (!explosionBuffer.loadFromFile(AUDIO_EXPLOSION_PATH)) {
        std::cout << "Explosion audio file could not be loaded\n";
    }
    if (!gameplayBuffer.loadFromFile(AUDIO_GAMEPLAY_PATH)) {
        std::cout << "Gameplay audio file could not be loaded\n";
    }
}