#include <iostream>
#include <cstdlib>
// using namespace std;

void magic_cub();
void hot_cold();

int main() 
{
    std::cout << "В какую игру вы хотите сыграть? 0 - шас судьбы, 1 - горячо/холодно: ";

    int ans;
    std::cin >> ans;

    if (ans)
    {
        std::cout << "\n Запустилась игра горячо/холодно\n";
        hot_cold();
    }        
    else
    {
        std::cout << "\n Запустилась игра шар судьбы\n";
        magic_cub();
    }
    
    return 0;
}

void magic_cub()
{
    std::string text = "";
    const std::string answer[] = {"Бесспорно", "Предрешено", "Определенно да", "Можешь быть уверен в этом", "Мне кажется - да", "Вероятнее всего", "Хорошие перспективы", "Знаки говорят - да", "Да", "Пока неясно, попробуй снова", "Спроси позже", "Лучше не рассказывать", "Сейчас нельзя предсказать", "Сконцентрируйся и спроси опять", "Даже не думай", "Мой ответ - нет", "По моим данным - нет", "Перспективы не очень хорошие", "Весьма сомнительно"};

    std::cout << "чтобы выйти напиши 'пока'\n";
    while (text != "пока")
    {
        std::cout << "\nКакой вопрос ты хочешь задать Магическому Шару Судьбы, о смертный?!\n";
        std::cout << "\t";
        std::getline(std::cin, text);
        std::cout << answer[rand()%19] << std::endl;
    }
}

void hot_cold()
{
    srand(time(0));
    int numb = rand() % 100 + 1;
 
    while(true)
    {
        int answer;
        std::cin >> answer;

        int accurate = answer - numb;
        accurate = (accurate >= 0) ? accurate : accurate * -1;

        if (accurate == 0)
        {
            std::cout << "Вы отгадали! Поздравляем\n";
            break;
        }   
        else if (accurate <= 5)
            std::cout << "Очень горячо!\n";
        else if (accurate <= 10)
            std::cout << "Горячо\n";
        else if (accurate <= 15)
            std::cout << "Тепло\n";
        else if (accurate <= 20)
            std::cout << "Холодно\n";
        else if (accurate > 20)
            std::cout << "Очень холодно\n";    
    }
}