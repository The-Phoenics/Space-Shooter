#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

inline static constexpr const char* AUDIO_MAINMENU_PATH  = "../res/audio/BravePilots.ogg";
inline static constexpr const char* AUDIO_EXPLOSION_PATH = "../res/audio/explosion.wav";
inline static constexpr const char* AUDIO_GAMEPLAY_PATH  = "../res/audio/through_space.ogg";

class AudioManager
{
public:
    static void instantiate_audio();
    
    static const sf::SoundBuffer& get_mainmenu_buffer()  { return mainMenuBuffer;  }
    static const sf::SoundBuffer& get_explosion_buffer() { return explosionBuffer; }
    static const sf::SoundBuffer& get_gameplay_buffer()  { return gameplayBuffer;  }

private:
    static sf::SoundBuffer mainMenuBuffer;
    static sf::SoundBuffer explosionBuffer;
    static sf::SoundBuffer gameplayBuffer;
};