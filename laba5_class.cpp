#include <iostream>
#include <string.h>
#include "laba5_class.h"

// 3. КАДРЫ 
// имя – char* номер цеха – int разряд – int 


worker::worker()
{
    strcpy(this->name, "no name");
    this->number_shop = 0;
    this->category = 0;
   
}
worker::worker(const char *name, int number_shop, int category)
{
    set(name, number_shop, category);
}
worker::~worker()
{
    std::cout << "Worker " << name << " deleted" << std::endl;
}
    
void worker::set(const char *name, int number_shop, int category)
{
    strcpy(this->name, name);
    this->number_shop = number_shop;
    this->category = category;
}

void worker::get ()
{
    std::cout << "name: " << name << " number_shop: " << number_shop << " category: " << category << std::endl;
}