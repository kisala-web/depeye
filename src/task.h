/**
 * @file task.h
 * @author lzxZz (616281384@qq.com)
 * @brief 线程池中的任务, 也是所有任务的基类
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */
# pragma once

#include <iostream>

namespace kiisala::depeye
{   
    /**
     * @brief 线程池中执行任务的基类
     * 
     */
    class Task{
    public:
        Task() {}
        Task(const Task &&task) noexcept {

        }
        Task &operator=(const Task &&task) noexcept{
            *this = std::move(task);
            return *this;
        }

        /**
         * @brief 虚函数, 重载以执行指定的任务
         * 
         */
        virtual void Execute(){
            std::cout << "basic task executed" << std::endl;
        }


        // 禁止拷贝操作
        Task(const Task&) = delete;
        Task &operator=(const Task&) = delete;
        virtual ~Task() {}
    };

} // namespace kiisala::depeye
