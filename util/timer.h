#pragma once

#include <chrono>


namespace NMatrixUtil {

class TTimer {
using clock = std::chrono::high_resolution_clock;

public:
    TTimer();

    size_t Start();
    size_t Stop();

    size_t Duration() const;
    size_t DurationMs() const;
    size_t DurationMks() const;

    void Reset();

private:
    size_t Current() const;

private:
    size_t left_;
    size_t right_;

};

}
