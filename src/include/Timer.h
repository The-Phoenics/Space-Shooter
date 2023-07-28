#pragma once
#include <chrono>

class Timer
{
public:
    Timer();
    ~Timer() { }

    void start();
    void update();
    void reset();
    
    inline float getElapsedTime() const { return m_elapsedtime; }

private:
    using Clock = std::chrono::steady_clock;
	using Second = std::chrono::duration<double, std::ratio<1> >;

    std::chrono::time_point<Clock> m_beg;
    float m_elapsedtime;
    bool  m_isActive;
};