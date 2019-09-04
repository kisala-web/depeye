#include "depeye/src/pool.h"

#include <thread>
#include <vector>

using std::thread;
using std::vector;

namespace kiisala::depeye{

namespace{

void TaskExecutor(ThreadSafeQueue<std::unique_ptr<Task>> &queue){
    using namespace std::chrono_literals;
    using option = std::optional<std::unique_ptr<Task>>;
    while (true){
        option task_ooption = std::move(queue.Pop());

        if (task_ooption.has_value()){
            std::unique_ptr<Task>  task = std::move(task_ooption.value());
            
            task->Execute();

        }else{
            std::this_thread::sleep_for(100ms);
            std::this_thread::yield();
        }
    }
    
}

}


void ThreadPool::PushTask(std::unique_ptr<Task> task){
    if (!is_shuwdown_){
        tasks_.Push(std::move(task));
    }
}

void ThreadPool::Shutdown(){
    using namespace std::chrono_literals;

    is_shuwdown_ = true;
    while(tasks_.Size() > 0){
        std::this_thread::sleep_for(100ms);
    }
}

ThreadPool::ThreadPool(int thread_number)
    : thread_number_(thread_number) {
    
    for (auto i = 0; i < thread_number; i++){
        thread worker{TaskExecutor, std::ref(tasks_)};
        worker.detach();
    }

}

}