#include <iostream>
#include <ctime>
#include <array>
#include <thread>
#include <chrono>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <numeric>

#include <unistd.h>
#include <sys/poll.h>
#include <fcntl.h>

using namespace std::chrono_literals;

int main()
{
    // clock()  - функция вредная, она не считает прошедшее время, она считает тики потраченные процессором на выполнение программы
    //            таким образом получается, что если запустить 3 одинаковых программы, то в них время будет идти в три раза медленее
    //            (если считать разницу между now и start)

    struct pollfd fdset[1];
    fdset[0].fd = STDIN_FILENO;
    fdset[0].events = POLLIN;
    char buf[100];

    // дальше понадобится сделать read не блокируемым
    int flags = fcntl(fdset[0].fd, F_GETFL, 0);
    fcntl(fdset[0].fd, F_SETFL, flags | O_NONBLOCK);

    // ждём когда будет нажат Enter
    int score = 0;
    int credit = 1;
    while (1)
    {
        // здесь спим
        std::this_thread::sleep_for(1000ms);

        // предыдущее значение
        int prev = score;

        // а тут проверяем нажатие на клавиатуре
        fdset[0].revents = 0;
        int nready = poll(&fdset[0], 1, 0);
        // если нажатие было, то прибавляем 2 и вычитываем буфер до конца
        if (nready == 1 && fdset[0].revents & POLLIN)
        {
            // долго мучалась с блокировкой read-а (выше read сделан не блокируемым)
            while (1) 
            {
                int c = read(fdset[0].fd, buf, sizeof(buf));
                if (c <= 0) break;
                if (score >= 100)
                    for (int i = 0; i < c; i++)
                        if (buf[i] == 'y')
                        {
                            if (score >= 500)
                                score -= 500;
                            else if (score >= 200)
                                score -= 200;
                            else
                                score -= 100;
                            credit++;
                            break;
                        }
            }
            score += 2;
        }
        else
        {
            score += credit;
        }
        std::cout << (int)score << std::endl;

        // провурка перехода через 100, 200, 500
        if (prev < 100 && score >= 100 ||
            prev < 200 && score >= 200 ||
            prev < 500 && score >= 500)
        {
            std::cout << "upgrade" << std::endl;
        }
    }

    // https://en.cppreference.com/w/cpp/chrono/high_resolution_clock/now
    /*auto now = std::chrono::high_resolution_clock::now();
    const std::chrono::duration<double> diff = now - start;
    std::cout
        << "You win! your score is " << score
        << ". Your time: " << std::fixed << std::setprecision(3) << diff << std::endl;*/

    return 0;
}
