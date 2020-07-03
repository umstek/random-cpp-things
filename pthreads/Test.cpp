#include <pthread.h>
#include <iostream>

class Test
{
private:
    pthread_mutex_t mutex;

public:
    Test();
    ~Test();
    void createThread();
    void doWork(std::string name);
    static void *start(void *);
};

Test::Test()
{
    int t = pthread_mutex_init(&mutex, NULL);
}

Test::~Test()
{
}

void Test::createThread()
{
    pthread_t thread;
    std::cout << "create thread" << std::endl;
    unsigned long id = pthread_create(&thread, NULL, &start /* has to be a static function */, this);
}

void Test::doWork(std::string name)
{
    while (true)
    {
        pthread_mutex_lock(&mutex);
        std::cout << name << std::endl;
        pthread_mutex_unlock(&mutex);
    }
}

void *Test::start(void *args)
{
    std::cout << "start thread" << std::endl;
    ((Test *)args)->doWork("child");
}

int main(int argc, char const *argv[])
{
    std::cout << "start program" << std::endl;

    Test *a = new Test();
    a->createThread();
    a->doWork("main");

    return 0;
}