# pool
线程池
###### 如果需要执行的工作耗时少请不要使用线程池，开辟线程是需要资源的，但开辟好之后将始终基于开辟好的线程执行任务

### 单例线程池
```c++
    pool &bb::pool::obj(const unsigned short &max=3);
        参数: max 表示要开辟的线程数量(只需第一次调用时传递需要开辟的线程数，之后传递的数量会被忽略)
        返回: 指向线程池自身，用于后面push任务到线程池
    pool_wait &bb::pool::objWait(const unsigned short &max=3);
        区别: 
            bb::pool::obj 只会依次分配任务(效率较高)
            bb::pool::objWait 当一个线程处于闲置状态时 会将排在其它繁忙线程后面的任务，拿出来交给它执行。这样可以避免某一个线程在执行到阻塞任务的时候，排在该线程后面的任务也会被阻塞的问题
```
### 往线程池push任务
```c++
    template<class F>
    void push(F f)
        参数: f 要放入线程池等待执行的lambda方法
        示例:
            bb::pool::obj(100).push([](){
                //耗时任务
            });
            bb::pool::objWait().push([](){
                //耗时且可能存在阻塞的任务
            });
```