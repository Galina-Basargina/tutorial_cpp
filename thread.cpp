#include <thread>
#include <mutex>
#include <iostream>

void run()
{
    std::cout << "Run" << std::endl;
}

using namespace std::chrono_literals;

void concurency_bad(int t, int * numb)
{
    std::cout << " in " << t;
    int temp = *numb;
    std::cout << " temp " << t << ":" << temp;
    std::this_thread::sleep_for(100ms);
    std::cout << " numb " << t << ":" << temp;
    *numb = temp + 10;
    std::cout << " out " << t << ":" << *numb;
}

std::mutex g_synchronizator;

void concurency_good(int t, int * numb)
{
    g_synchronizator.lock();
    std::cout << " in " << t;
    int temp = *numb;
    std::cout << " temp " << t << ":" << temp;
    std::this_thread::sleep_for(100ms);
    std::cout << " numb " << t << ":" << temp;
    *numb = temp + 10;
    std::cout << " out " << t << ":" << *numb;
    g_synchronizator.unlock();
}

void concurency_well(int t, int * numb)
{
    std::cout << " in " << t;
    g_synchronizator.lock();
    int temp = *numb;
    std::cout << " temp " << t << ":" << temp;
    std::this_thread::sleep_for(100ms);
    std::cout << " numb " << t << ":" << temp;
    *numb = temp + 10;
    g_synchronizator.unlock();
    std::this_thread::sleep_for(200ms);
    std::cout << " out " << t << ":" << *numb;
}

void concurency_ok(int t, int * numb)
{
    int temp;
    std::string s;
    std::cout << " in " << t;

    g_synchronizator.lock();
    temp = *numb;
    s = " temp " + std::to_string(t) + ":" + std::to_string(temp);
    std::this_thread::sleep_for(100ms);
    s += " numb " + std::to_string(t) + ":" + std::to_string(temp);
    temp += 10;
    *numb = temp;
    g_synchronizator.unlock();

    std::this_thread::sleep_for(200ms);
    std::cout << s << " out " << t << ":" << temp;
}

void bar()
{
    std::thread runner(run);
    runner.join();

    {
        int numb = 0;
        std::thread th1(concurency_bad, 1,  &numb);
        std::thread th2(concurency_bad, 2, &numb);
        //  in 2 temp 2:0 in 1 temp 1:0 numb 2:0 out 2:10 numb 1:0 out 1:10
        //  in 1 temp 1:0 in 2 temp 2:0 numb 1:0 out 1:10 numb 2:0 out 2:10
        th1.join();
        th2.join();
        std::cout << std::endl << numb << std::endl;
    }

    {
        int numb = 0;
        std::thread th1(concurency_good, 1,  &numb);
        std::thread th2(concurency_good, 2, &numb);
        //  in 1 temp 1:0 numb 1:0 out 1:10 in 2 temp 2:10 numb 2:10 out 2:20
        th1.join();
        th2.join();
        std::cout << std::endl << numb << std::endl;
    }

    {
        int numb = 0;
        std::thread th1(concurency_well, 1,  &numb);
        std::thread th2(concurency_well, 2, &numb);
        //  in 1 temp 1:0 in 2 numb 1:0 temp 2:10 numb 2:10 out 1:20 out 2:20
        th1.join();
        th2.join();
        std::cout << std::endl << numb << std::endl;
    }

    {
        int numb = 0;
        std::thread th1(concurency_ok, 1,  &numb);
        std::thread th2(concurency_ok, 2, &numb);
        // in 2 temp 2:0 in 1 numb 2:0 temp 1:10 numb 1:10 out 2:10 out 1:20
        th1.join();
        th2.join();
        std::cout << std::endl << numb << std::endl;
    }
}
