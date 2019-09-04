/**
 * @file depeye.h
 * @author lzxZz (616281384@qq.com)
 * @brief 一个简单的线程池库, 线程库内部使用mutex的线程安全任务队列
 *          使用方式参照example
 * @version 0.1
 * @date 2019-09-04
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#pragma once

#include "depeye/src/pool.h"
#include "depeye/src/task.h"
#include "depeye/src/queue.h"

#include <memory>

namespace kiisala::depeye{

    using TaskPointer = std::unique_ptr<Task>;

}