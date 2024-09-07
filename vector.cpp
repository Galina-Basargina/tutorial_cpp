#include <iostream>
#include <vector>
#include <utility>

void print(std::vector<std::string> val)
{
    for (const auto & v : val)
        std::cout << v << ", ";
    std::cout << std::endl;
}

void rev_print(const std::vector<std::string> & val)
{
    std::vector<std::string>::const_reverse_iterator itr = val.crbegin();
    for ( ; itr != val.crend(); ++itr)
        std::cout << *itr << ", ";
    std::cout << std::endl;
}

void foo()
{
    std::vector<std::string> texts;
    print(texts);

    texts.push_back("push_back");
    print(texts);

    texts.push_back("new_push_back");
    print(texts);

    texts.insert(texts.begin(), "insert_begin");
    print(texts);

    texts.insert(texts.end(), "insert_end");
    print(texts);

    texts.insert(texts.end()-1, "insert_end-1");
    print(texts);

    //int c_style_array[5];
    //int * begin = &c_style_array[0];
    //int * end = &c_style_array[(sizeof(c_style_array)/sizeof(c_style_array[0]))-1];

    texts.insert(texts.begin()+3, "three");
    print(texts);
    rev_print(texts);
}
