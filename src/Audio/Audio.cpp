#include "Audio.h"

Audio::Audio(const sf::SoundBuffer& soundBuffer, float volume)
    : m_offset(sf::Time::Zero)
{
    m_sound.setBuffer(soundBuffer);
    m_sound.setVolume(volume);
}

void Audio::play()
{
    m_offset = sf::Time::Zero;
    if (!isPlaying()) {
        m_sound.play();
    }
}

void Audio::pause()
{
    m_offset = m_sound.getPlayingOffset();
    m_sound.stop();
}

void Audio::stop()
{
    m_sound.stop();
    m_offset = sf::Time::Zero;
}

void Audio::resume()
{
    if (m_offset != sf::Time::Zero) {
        m_sound.setPlayingOffset(m_offset);
        m_sound.play();
    } else {
        play();
    }
}

void Audio::restart()
{
    m_sound.stop();
    m_sound.play();
}

