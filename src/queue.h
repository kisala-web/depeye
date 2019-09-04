/**
 * @file queue.h
 * @author lzxZz (616281384@qq.com)
 * @brief 线程安全队列
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once


#include <c++/9.1.0/optional>
#include <mutex>
#include <queue>

#include "task.h"

namespace kiisala::depeye
{
    /**
     * @brief 使用mutex实现的线程安全队列
     * 
     * @tparam T 
     */
    template<typename T>
    class ThreadSafeQueue{
    public:
        ThreadSafeQueue(){}
        
        std::optional<T> Pop(){
            bool lock = mutex_.try_lock();
            while (!lock){
                lock = mutex_.try_lock();
            }
            if (tasks_.size() == 0){
                mutex_.unlock();
                return {};
            }
            else{
                T task = std::move(tasks_.front());
                tasks_.pop();
                mutex_.unlock();
                return task;
            }
            mutex_.unlock();
        }

        void Push(T task){
            bool lock = mutex_.try_lock();
            while (!lock){
                lock = mutex_.try_lock();
            }
            tasks_.push(std::move(task));
            mutex_.unlock();
        };

        std::size_t Size() const{
            return tasks_.size();
        }

        ~ThreadSafeQueue(){

        }
    private:    
        std::queue<T> tasks_;
        std::mutex mutex_;
    };

} // namespace kiisala::depeye
