#include <iostream>
#include <string>
#include <vector>

void foo(); // функция из vector.cpp
void bar(); // функция из thread.cpp

int main()
{
    std::cout << "Hello World!" << std::endl;

    std::string text = "Hello, World!)";
    std::cout << text << std::endl;

    text += " bye bye";
    std::cout << text << std::endl;

    for (int i = 0; i < text.length(); ++i)
        std::cout << text[i];
    std::cout << "\n";

    for (auto symbol : text)
        std::cout << symbol;
    std::cout << "\n";

    for (const auto & symbol : text)
        std::cout << symbol;
    std::cout << "\n";

    std::vector<int> v{10, 2};
    for (const auto & item : v)
        std::cout << item << " ";
    std::cout << "\n";

    v = {4, 5, 6, 7, -8, 9};
    for (int i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << "\n";

    /*std::vector<int>::iterator itr = v.begin();
    const std::vector<int>::const_iterator end = v.cend();
    for (; itr != end; ++itr)
        std::cout << *itr << " ";
    std::cout << "\n";

    typedef std::vector<int> vector_t;
    vector_t v3{ 1, 2, 3, 4};
    for (vector_t::iterator itr = v3.begin(), end = v3.end(); itr != end; ++itr)
        std::cout << *itr << " ";
    std::cout << "\n";*/

    std::vector<std::pair<int, int>> v2(10, {5, 2});
    for (const auto & item : v2)
        std::cout << item.first << "," << item.second << " ";
    std::cout << "\n";

    foo();
    bar();
    return 0;
}
