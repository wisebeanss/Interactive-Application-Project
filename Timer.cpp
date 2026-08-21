#include "Timer.h"

Timer::Timer()
{
    timeLeft = 45 * 60; // 45 minutes
    lastTime = std::chrono::steady_clock::now();
}

void Timer::update()
{
    auto currentTime = std::chrono::steady_clock::now();

    int elapsed = std::chrono::duration_cast<std::chrono::seconds>(
        currentTime - lastTime
    ).count();

    if (elapsed > 0)
    {
        timeLeft -= elapsed;
        lastTime = currentTime;

        if (timeLeft < 0)
            timeLeft = 0;
    }
}

void Timer::decreaseTime(int seconds)
{
    timeLeft -= seconds;

    if (timeLeft < 0)
        timeLeft = 0;

    // Reset the reference point so the penalty doesn't get counted again
    lastTime = std::chrono::steady_clock::now();
}

int Timer::getMinutes() const
{
    return timeLeft / 60;
}

int Timer::getSeconds() const
{
    return timeLeft % 60;
}

bool Timer::isTimeUp() const
{
    return timeLeft <= 0;
}