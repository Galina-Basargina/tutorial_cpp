#include <map>
#include <string>
#include <iostream>


template<class T>
class my_map_t
{
public:
    T container;
};

template<class T>
class my_map_ex_t
{
private:
    T container;
public:
    void clear()
    {
        this->container.clear();
    }
    void add(typename T::key_type key, typename T::mapped_type value)
    {
        this->container.insert(typename T::value_type(key, value));
    }
    const T & get() const
    {
        // this->container.clear();
        return this->container;
    }
};

template<>
class my_map_ex_t<int>
{
private:
    int container;
public:
    void clear()
    {
        this->container = 0 ;
    }
    void add(int key, int value)
    {
        this->container = key * 100 + value;
    }
    const int & get() const
    {
        return this->container;
    }
};

template<>
class my_map_ex_t<std::string>
{
private:
    std::string container;
public:
    void clear()
    {
        this->container.clear();
    }
    void add(std::string key, std::string value)
    {
        this->container = key + "." + value;
    }
    const std::string & get() const
    {
        return this->container;
    }
};


int main()
{
    std::map<int, std::string> numbers;
    std::map<std::string, int> lines;

    std::map<int, std::string>::key_type h = 4;
    std::map<std::string, int>::key_type l = "4";

    std::map<int, std::string>::value_type nv1 = std::map<int, std::string>::value_type(2, "2");
    std::map<int, std::string>::value_type nv2 = std::pair<int, std::string>(3, "3");
    std::map<int, std::string>::value_type nv3(1, "1");
    std::map<int, std::string>::value_type nv4(nv1);

    using numbers_t = std::map<int, std::string>;

    numbers_t nums;
    numbers_t::value_type n1(7, "7");

    using lines_t = std::map<std::string, int>;

    lines_t lins;
    lines_t::value_type l1("8", 8);


    my_map_t<numbers_t> my_nums;
    my_nums.container.clear();
    my_nums.container.insert(numbers_t::value_type(1, "1"));

    my_map_t<lines_t> my_lins;
    my_lins.container.clear();
    my_lins.container.insert(lines_t::value_type("0", 0));

    my_map_ex_t<numbers_t> my_ex_nums;
    my_ex_nums.clear();
    my_ex_nums.add(4, "6");
    // my_ex_nums.get().clear();
    my_ex_nums.get();

    my_map_ex_t<lines_t> my_ex_lines;
    my_ex_lines.clear();
    my_ex_lines.add("4", 6);

    my_map_ex_t<int> test;
    test.clear();
    test.add(2, 1);

    my_map_ex_t<std::string> test2;
    test2.clear();
    test2.add("Hello", "World!");

    std::cout << test2.get() << std::endl;

    // numbers.insert()

    return 0;
}
