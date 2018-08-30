/* Copyright (c) 2018 - present, VE Software Inc. All rights reserved
 *
 * This source code is licensed under Apache 2.0 License
 *  (found in the LICENSE.Apache file in the root directory)
 */
#include "concurrent/sync/Barrier.h"


namespace vesoft {
namespace concurrent {

Barrier::Barrier(size_t counter, std::function<void()> completion) {
    if (counter == 0) {
        throw std::invalid_argument("Zero barrier counter");
    }
    completion_ = std::move(completion);
    counter_ = counter;
    ages_ = counter_;
}

void Barrier::wait() {
    std::unique_lock<std::mutex> unique(lock_);
    if (--ages_ == 0) {
        ages_ = counter_;
        ++generation_;
        if (completion_ != nullptr) {
            completion_();
        }
        cond_.notify_all();
    } else {
        auto current = generation_;
        cond_.wait(unique, [=] () { return current != generation_; });
    }
}

}   // namespace concurrent
}   // namespace vesoft