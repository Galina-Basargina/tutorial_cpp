#include <iostream>
#include <fstream>


int main()
{
    setlocale(LC_ALL,"rus");
    char buff[50];
    std::string text = "";
    std::ifstream fin("../cppstdio.txt");
    const char *question[] {"\n1. Вы проснулись. Встать с кровати или спать дальше?\nспать/встать",
                            "\n2. Поехать на такси или метро?\nтакси/метро",
                            "\n3. Хоть вы и приехали вовремя, вас все равно вызывает начальник\nидти/сбежать",
                            "\n3. Вы пришли на работу и спокойно работаете. Но вот вы нашли ошибку\nпромолчать/рассказать",
                            "\n4. Вас попросили исправить эту ошибку\ncделать самому/передать задание другому"
                           };
    const char *answers[] {"Вы уснули и все проспали",
                           "Вы встали и собрались на работу",
                           "Вас повысили за хорошую работу",
                           "Вы сбежали с работы и позже получили выговор",
                           "Вы проработали день и уехали домой",
                           "Вы решили рассказать начальнику об ошибке",
                           "День закончился, для вас ничего не изменится",
                           "Вас повысили за хорошую работу",
                           "Вы ввели неверные данные. День закончен"
                          };
    const char *result[] {"спать", "встать", "такси", "идти",
                          "сбежать", "метро", "промолчать", "рассказать",
                          "cделать самому", "передать задание другому"
                         };
    std::ofstream fout;
    fout.open("../cppstdio.txt");

    if (!fin.is_open())
        std::cout << "Файл не может быть открыт" << std::endl;
    else
    {
        std::cout << question[0] << std::endl;
        fout << question[0] << std::endl;
        std::getline(std::cin, text);
        if (text == result[0])
        {
            std::cout << answers[0] << std::endl;
            fout << answers[0] << std::endl;
            return 0;
        }
        else if (text == result[1])
        {
            std::cout << answers[1] << std::endl;
            fout << answers[1] << std::endl;
        }
        else
        {
            std::cout << answers[8] << std::endl;
            fout << answers[8] << std::endl;
            return 0;
        }

        std::cout << question[1] << std::endl;
        fout << question[1] << std::endl;
        std::getline(std::cin, text);
        if (text == result[2])
        {
            std::cout << question[2] << std::endl;
            fout << question[2] << std::endl;
            std::getline(std::cin, text);
            if (text == result[3])
            {
                std::cout << answers[2] << std::endl;
                fout << answers[2] << std::endl;
                return 0;
            }
            else if (text == result[4])
            {
                std::cout << answers[3] << std::endl;
                fout << answers[3] << std::endl;
                return 0;
            }
            else
            {
                std::cout << answers[8] << std::endl;
                fout << answers[8] << std::endl;
                return 0;
            }
        }
        else if (text == result[5])
        {
            std::cout << question[3] << std::endl;
            fout << question[3] << std::endl;
            std::getline(std::cin, text);
            if (text == result[6])
            {

                std::cout << answers[4] << std::endl;
                fout << answers[4] << std::endl;
                return 0;
            }
            else if (text == result[7])
            {
                std::cout << answers[5] << std::endl;
                fout << answers[5] << std::endl;
                std::cout << question[4] << std::endl;
                fout << question[4] << std::endl;
                std::getline(std::cin, text);
                if (text == result[8])
                {

                    std::cout << answers[6] << std::endl;
                    fout << answers[6] << std::endl;
                    return 0;
                }
                else if (text == result[9])
                {
                    std::cout << answers[7] << std::endl;
                    fout << answers[7] << std::endl;
                }
                else
                {
                    std::cout << answers[8] << std::endl;
                    fout << answers[8] << std::endl;
                    return 0;
                }
            }
        }
        else
        {
            std::cout << answers[8] << std::endl;
            fout << answers[8] << std::endl;
            return 0;
        }

        fin.close();
    }

    fout.close();
    return 0;
}













