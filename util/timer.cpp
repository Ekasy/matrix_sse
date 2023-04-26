#include "timer.h"


namespace NMatrixUtil {

TTimer::TTimer() {
    left_ = Start();
}


size_t TTimer::Start() {
    return left_ = Current();
}


size_t TTimer::Stop() {
    right_ = Current();
    return Duration();
}


size_t TTimer::Duration() const {
    return right_ - left_;
}


size_t TTimer::DurationMs() const {
    const std::chrono::duration<int64_t, std::ratio<1, clock::period::den>> chrono_duration(Duration());
	return std::chrono::duration_cast<std::chrono::milliseconds>(chrono_duration).count();
}


size_t TTimer::DurationMks() const {
    const std::chrono::duration<int64_t, std::ratio<1, clock::period::den>> chrono_duration(Duration());
	return std::chrono::duration_cast<std::chrono::microseconds>(chrono_duration).count();
}


void TTimer::Reset() {
    left_ = 0;
    right_ = 0;
}


size_t TTimer::Current() const {
    return clock::now().time_since_epoch().count();
}

}
