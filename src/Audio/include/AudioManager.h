#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

inline static constexpr const char* AUDIO_MAINMENU_PATH  = "/home/prime/Desktop/SpaceShooter/res/audio/BravePilots.ogg";
inline static constexpr const char* AUDIO_EXPLOSION_PATH = "/home/prime/Desktop/SpaceShooter/res/audio/explosion.wav";
inline static constexpr const char* AUDIO_GAMEPLAY_PATH  = "/home/prime/Desktop/SpaceShooter/res/audio/through_space.ogg";

class AudioManager
{
public:
    static const sf::SoundBuffer& get_mainmenu_buffer();
    static const sf::SoundBuffer& get_explosion_buffer();
    static const sf::SoundBuffer& get_gameplay_buffer();

private:
    static sf::SoundBuffer mainMenuBuffer;
    static sf::SoundBuffer explosionBuffer;
    static sf::SoundBuffer gameplayBuffer;
};