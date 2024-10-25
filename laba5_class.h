#pragma once
#define NAMELEN 80
// 3. КАДРЫ 
// имя – char* номер цеха – int разряд – int 

class worker
{
    private:
     char name[NAMELEN];
     int number_shop;
     int category;

    public:
    worker();
    worker(const char*, int, int);
    ~worker();
    void set(const char*, int, int);
    void get ();
};


