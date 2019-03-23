//
// Created by anastasiia on 21.03.19.
//

#ifndef CHEKER_TIME_MEASURE_H
#define CHEKER_TIME_MEASURE_H

#include <chrono>
#include <atomic>


// Get current time using atomic thread to protect from command rearrangements by CPU.
inline std::chrono::high_resolution_clock::time_point get_current_time_fenced()
{
    std::atomic_thread_fence(std::memory_order_seq_cst);
    auto res_time = std::chrono::high_resolution_clock::now();
    std::atomic_thread_fence(std::memory_order_seq_cst);
    return res_time;
}


// To cast the time from time_point to microseconds.
template<class D>
inline long long to_mcs(const D& d)
{ return std::chrono::duration_cast<std::chrono::microseconds>(d).count(); }


// To cast the time from time_point to milliseconds.
template<class D>
inline long long to_mls(const D& d) { return std::chrono::duration_cast<std::chrono::milliseconds>(d).count(); }


#endif //CHEKER_TIME_MEASURE_H
