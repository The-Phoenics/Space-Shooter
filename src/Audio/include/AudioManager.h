#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

inline constexpr const char* AUDIO_MAINMENU_PATH  = "../res/audio/BravePilots.ogg";
inline constexpr const char* AUDIO_EXPLOSION_PATH = "../res/audio/explosion.wav";
inline constexpr const char* AUDIO_GAMEPLAY_PATH  = "../res/audio/through_space.ogg";

class AudioManager
{
public:
    static AudioManager& getInstance()
    {
        static AudioManager audioManager;
        return audioManager;
    }

    void instantiate_audio();

    const sf::SoundBuffer& get_mainmenu_buffer()  { return mainMenuBuffer;  }
    const sf::SoundBuffer& get_explosion_buffer() { return explosionBuffer; }
    const sf::SoundBuffer& get_gameplay_buffer()  { return gameplayBuffer;  }

private:
    AudioManager() {}
    ~AudioManager() {}
    AudioManager(const AudioManager&) = delete;

    sf::SoundBuffer mainMenuBuffer;
    sf::SoundBuffer explosionBuffer;
    sf::SoundBuffer gameplayBuffer;
};