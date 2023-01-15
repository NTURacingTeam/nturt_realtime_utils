#include "nturt_realtime_utils/memory_lock.hpp"

void lock_memory() {
    // lock all current and future pages
    if(mlockall(MCL_CURRENT | MCL_FUTURE) != 0) {
        throw std::runtime_error("Failed to mlockall. Error code: " + std::string(strerror(errno)));
    }

    // turn off malloc trimming
    if(mallopt(M_TRIM_THRESHOLD, -1) == 0) {
        throw std::runtime_error("Failed to mallopt for trim threshold. Error code: " + std::string(strerror(errno)));
    }

    // turn off mmap usage
    if(mallopt(M_MMAP_MAX, 0) == 0) {
        mallopt(M_TRIM_THRESHOLD, 128 * 1024);
        munlockall();
        throw std::runtime_error("Failed to mallopt for mmap. Error code: " + std::string(strerror(errno)));
    }
}

void preallocate_memory(size_t memory_size) {
    void * buf = nullptr;
    const size_t pg_sz = sysconf(_SC_PAGESIZE);
    if(posix_memalign(&buf, static_cast<size_t>(pg_sz), memory_size) != 0) {
        throw std::runtime_error("Failed to reserve memory. Error code: " + std::string(strerror(errno)));
    }
    free(buf);
}

void set_default_thread_stacksize(size_t stacksize) {
    pthread_attr_t attr;
    if(pthread_getattr_default_np(&attr) != 0) {
        throw std::runtime_error("Failed to call pthread_getattr_default_np. Error code: " + std::string(strerror(errno)));
        return;
    }

    if(pthread_attr_setstacksize(&attr, stacksize) != 0) {
        throw std::runtime_error("Failed to call pthread_attr_setstacksize. Error code: " + std::string(strerror(errno)));
        return;
    }

    if(pthread_setattr_default_np(&attr) != 0) {
        throw std::runtime_error("Failed to call pthread_setattr_default_np. Error code: " + std::string(strerror(errno)));
        return;
    }
}
