#include "nturt_realtime_utils/scheduling.hpp"

void set_thread_scheduling(std::thread::native_handle_type thread, int policy, int priority) {
    struct sched_param param;
    param.sched_priority = priority;
    if(pthread_setschedparam(thread, policy, &param) != 0 ) {
        throw std::runtime_error("Failed to set scheduling priority and policy. Error code: " + std::string(strerror(errno)));
    }
}
