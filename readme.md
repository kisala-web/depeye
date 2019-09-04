# depeye
> deep eye white dragon
![pic]()

核心线程库. 作为web server高并发的基础设施存在.

核心内容为:
1. 线程池
    基于mutex实现的线程安全队列

# 特性
1. 使用Task基类来执行任务, 通过继承Task并重载`Execute()`来自定义任务.

