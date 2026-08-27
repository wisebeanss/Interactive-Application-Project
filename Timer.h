#pragma once
#include <chrono>

class Timer
{
private:
    int timeLeft; // seconds
    std::chrono::steady_clock::time_point lastTime;

public:
    Timer();

    void update();
    void decreaseTime(int seconds);

    int getMinutes() const;
    int getSeconds() const;
    void resetTimer();
    bool isTimeUp() const;
    void debugTime();
};