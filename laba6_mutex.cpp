#include <thread>
#include <mutex>
#include <iostream>


using namespace std::chrono_literals;

std::mutex g_synchronizator;

void f1(volatile int * score, volatile int * bonus, volatile int * credit)
{
    for (int i = 0; i < 1000; ++i)
    {
        bool upgrade = false;
        int temp;

        g_synchronizator.lock();
        // ...число увеличивается на 1 каждую секунду и выводится на экран...
        // ...величина увеличения числа в секунду увеличивается на 1...
        *score = *score + *credit;
        temp = *score;
        // ...при достижении выводимым числом...
        // выводимое - это то, которое есть, а не то, которое увеличилось на два. То есть, 99 + 2 + 1 = 102
        if (*score == 100 || *score == 200 || *score == 500)
        {
            upgrade = true;
            *bonus = *score;
        }
        g_synchronizator.unlock();

        std::cout << temp << std::endl;
        if (upgrade)
        {
            std::cout << "upgrade" << std::endl;
        }

        std::this_thread::sleep_for(1000ms);
    }
}

int main()
{
    volatile int score = 0;
    volatile int bonus = 0;
    volatile int credit = 1;

    std::thread t1(f1, &score, &bonus, &credit);

    std::string answer;
    while(1)
    {
        // ...при нажатии на клавишу на клавиатуре (любую по вашему выбору)...
        // Выбрала клавишу Enter
        std::cin >> answer;

        g_synchronizator.lock();
        score = score + 2;
        if (bonus >= 100 && (answer == "yes" || answer == "y"))
        {
            score = score - bonus;
            bonus = 0;
            credit = credit + 1;
        }
        g_synchronizator.unlock();
    }

    t1.join();
    return 0;
}
