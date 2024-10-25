#include <thread>
#include <iostream>


using namespace std::chrono_literals;

void f1(volatile int * score, volatile int * bonus, volatile int * credit)
{
    for (int i = 0; i < 1000; ++i)
    {
        // ...число увеличивается на 1 каждую секунду и выводится на экран...
        // ...величина увеличения числа в секунду увеличивается на 1...
        *score = *score + *credit;
        std::cout << *score << std::endl;
        // ...при достижении выводимым числом...
        // выводимое - это то, которое есть, а не то, которое увеличилось на два. То есть, 99 + 2 + 1 = 102
        if (*score == 100 || *score == 200 || *score == 500)
        {
            std::cout << "upgrate" << std::endl;
            *bonus = *score;
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
        score = score + 2;
        if (bonus >= 100 && answer == "yes")
        {
            score = score - bonus;
            bonus = 0;
            credit = credit + 1;
        }
    }

    t1.join();
    return 0;
}
