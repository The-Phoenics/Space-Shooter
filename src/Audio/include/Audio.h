#pragma once

#include <memory>
#include <SFML/Audio.hpp>

class Audio
{
public:
    Audio(const sf::SoundBuffer& soundBuffer, float volume = 100.f);
    ~Audio() { }

    void play();
    void pause();
    void stop();
    void resume();
    void restart();

    inline bool isPlaying() { return m_sound.getStatus() == sf::Sound::Playing; }

private:
    sf::Sound m_sound;
    sf::Time  m_offset;
};