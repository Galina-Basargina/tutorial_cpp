#include <iostream>
#include "laba5_class.h"


void (worker::*pf)();

int main()
{
    std::cout << "Использование различных конструкторов:  без параметров, с параметрами, копирования" << std::endl;
    worker person0;
    person0.get();

    worker person1;
    person1.set("Bob", 5, 4);
    person1.get();

    worker person2 = person1;
    person2.get();

    std::cout << "Используем указатель на экземпляр класса" << std::endl;
    worker *p = &person1;
    p->get();

    std::cout << "Используем указатель на компоненту-функцию" << std::endl;
    pf = &worker::get;
    (person0.*pf)();
    std::cout << "Вывовы деконструкторов: " << std::endl;
    return 0;
}
