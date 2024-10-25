#include <iostream>
#include <random>
#include <cstring>
#include <string>


int main()
{
    srand(time(0));
    const char *human[] {
        " ________________________\n",
        " |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n |\n_|_______________________\n",
        " _|_____________\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n _|_______________________\n",
        " _|_____________\n  |          |\n  |          |\n  |         _|_\n  |	   |   |\n  |	    ---\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n  |\n _|_______________________\n",
        " _|_____________\n  |          |\n  |          |\n  |         _|_\n  |	   |   |\n  |	    ---\n  |          |\n  |	 ---------\n  |          |  \n  |          |  \n  |          |  \n  |       -------\n  |\n  |\n  |\n  |\n  |\n _|_______________________  \n",
        " _|_____________\n  |          |\n  |          |\n  |         _|_\n  |	   |   |\n  |	    ---\n  |          |\n  |	 ---------\n  |	 |   |\n  |	 |   |\n  |          |\n  |	  -------\n  |\n  |\n  |\n  |\n  |\n _|_______________________    \n",
        " _|_____________\n  |          |\n  |          |\n  |  	    _|_\n  |	   |   |\n  |         ---\n  |          |\n  |	 ---------\n  |	 |   |	 |\n  |	 |   |	 |\n  |          |\n  |       -------\n  |\n  |\n  |\n  |\n  |\n _|_______________________  \n",
        " _|_____________\n  |          |\n  |          |\n  |  	    _|_\n  |	   |   |\n  |         ---\n  |          |\n  |	 ---------\n  |      |   |	 |\n  |      |   |	 |\n  |          |\n  |       -------\n  |       |\n  |       |\n  |       |\n  |      --\n  |\n _|_______________________  \n",
        " _|_____________\n  |          |\n  |          |\n  |  	    _|_\n  |	   |   |\n  |         ---\n  |          |\n  |	 ---------\n  |      |   |	 |\n  |      |   |	 |\n  |          |\n  |       -------\n  |       |     |\n  |       |     |\n  |       |     |\n  |      --     --\n  |\n _|_______________________  \n"
    };

//    for (int i = 0; i < 9; i++)
//        std::cout << human[i] << std::endl << std::endl;

    const char *words[] {"dog", "cat", "bird", "fish", "insect", "mouse", "giraffe", "elephant", "panda", "human" };
    int mistake = -1;
    int index = rand() % 10;
    std::string word = words[index];
    std::string answer(strlen(words[index]), '_');
    std::cout << word << std::endl;

    std::string letter;
    while (1)
    {
        std::cout << answer << std::endl;

        std::cout << "Введите букву: ";
        std::cin >> letter;
        std::size_t found = word.find(letter);
        if (found != std::string::npos)
        {
            while (1)
            {
                answer[found] = word[found];
                found = word.find(letter, found+1);
                if (found >= strlen(words[index]))
                    break;
            }
//            std::cout << found;
            if (answer == word)
            {
                std::cout << "Вы выиграли" << std::endl;
                return 0;
            }
        }
        else
        {
            std::cout << human[++mistake] << std::endl;
            if (mistake == 8)
            {
                std::cout << "Вы проиграли" << std::endl;
                std::cout << "Ответ: " << word << std::endl;
                return 0;
            }
        }
        //    std::cout << std::endl;
    }
    return 0;
}
