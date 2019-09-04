#include "depeye/src/depeye.h"

using namespace kiisala::depeye;

#include <thread>

class T : public Task{
    void Execute() override{
        std::cout << "new basic task executed" << std::endl;
    }
};


class NewT : public Task{
    void Execute() override{
        std::cout << "233333333333333" << std::endl;
    }
};


class ArgT : public Task{
public:
    ArgT(int i) : index_(i){}
    void Work(){
        std::cout << "ArgTask : " << index_ << std::endl;
    }
    
    void Execute() override{
        Work();
    }
private:
    int index_;
};

void Add(ThreadPool &pool){
    for (auto i = 0; i < 10000; i++){
        pool.PushTask(TaskPointer(new T{}));
        pool.PushTask(TaskPointer(new NewT{}));
        pool.PushTask(TaskPointer(new ArgT{i}));
    }
}

int main(){
    ThreadPool pool{4};
    // 线程默认会拷贝参数, 使用引用参数则需要使用std::ref包裹
    std::thread th{Add, std::ref(pool)}; 
    th.join();

    

    pool.Shutdown();
}