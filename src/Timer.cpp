#include "Timer.h"

Timer::Timer()
    : m_beg(),
      m_isActive(),
      m_elapsedtime(0.0f)
{
}

void Timer::start()
{
    if (!m_isActive) {
        m_beg = Clock::now();
        m_isActive = true;
    }
}

void Timer::update()
{
    m_elapsedtime = float(std::chrono::duration_cast<Second>(Clock::now() - m_beg).count());
}

void Timer::reset()
{
    if (m_isActive) {
        m_elapsedtime = 0.0f;
        m_beg = Clock::now();
        // m_isActive = false;
    }
}