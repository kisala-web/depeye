/**
 * @file pool.h
 * @author lzxZz (616281384@qq.com)
 * @brief 线程池
 * @version 0.1
 * @date 2019-09-02
 * 
 * @copyright Copyright (c) 2019
 * 
 */


#pragma once

#include <thread>
#include <vector>

#include "task.h"
#include "queue.h"


namespace kiisala::depeye{

/**
 * @brief  线程池
 * 
 */
class ThreadPool{

public:
    ThreadPool(int thread_number);
        
    // 将任务加入线程池
    void PushTask(std::unique_ptr<Task> task);
    
    /**
     * @brief 线程池停止操作, 停止接受任务, 
     * 所有的PushTask加入的任务都会忽略
     * 阻塞函数, 一直到任务队列中所有任务都执行完成之后返回.
     * !!! 不可逆 !!!
     */
    void Shutdown();
    
    

private:
    // 任务队列, 使用unique指针管理内存
    ThreadSafeQueue<std::unique_ptr<Task>> tasks_;
    // 线程数
    int thread_number_;
    
    // // 线程管理对象
    // std::vector<std::thread> threads_;  // 暂时发现无用

    bool is_shuwdown_ = false;

}; //class ThreadPool

} //namespace kiisala::depeye
