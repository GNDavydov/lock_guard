// Copyright 2021 GNDavydov

#ifndef INCLUDE_LOCK_GUARD_HPP_
#define INCLUDE_LOCK_GUARD_HPP_

#include <mutex>

namespace my_lock_guard {
    template<class Mutex>
    class lock_guard {
    private:
        Mutex &mutex_;

    public:
        explicit lock_guard(Mutex &mutex) : mutex_(mutex) {
            mutex_.lock();
        }

        lock_guard(const lock_guard &) = delete;

        lock_guard &operator=(const lock_guard &) = delete;

        ~lock_guard() noexcept {
            mutex_.unlock();
        }
    };
}

#endif //INCLUDE_LOCK_GUARD_HPP_
