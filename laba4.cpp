#include <iostream>


void print_matrix(int **matr, int row, int col)
{
    std::cout << "------------------------------------" << '\n';
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << "|" << matr[i][j] << '\t';
        }
        std::cout << "|" << '\n';     
    }
    std::cout << "-----------------------------------" << '\n';
}

void val2matr(int **matr, int row, int col)
{
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            matr[i][j] = 10 + rand() % 41;
}

void print_arr(double *matr, int len)
{
    std::cout << "------------------------------------" << '\n';
    for (int i = 0; i < len; i++)
    {
        std::cout << "|" << matr[i] << '\t';
    }
    std::cout << "\n-----------------------------------" << '\n';
}

double* create_arr(int len)
{
    return new double[len];
}

void val2arr(double *arr, int len)
{
    for (int i = 0; i < len; i++)
        arr[i] = rand() / 1100000.0;
}

    

void delete_arr(double *arr)
{
    delete []arr;
}

int main()
{
    srand(time(0));
    
    int m = 0;
    int ans;
    while (true)
    {
        std::cout << "Вы хотите начать работу с массивами? (да => 1, нет => 0) ";
        std::cin >> ans;
        if (ans == 0)
            break;
        else if (ans != 1)
        {
            std::cout << "\nВы ввели неверное число\n";
            continue;
        }

        std::cout << "Введите длину массива: ";
        std::cin >> m;
        if (m == 0)
        {
            std::cout << "\n\tВведены неверные данные\n";
            return 0;
        }
        
        double *arr = create_arr(m);
        val2arr(arr, m);
        print_arr(arr, m);
        delete_arr(arr);

        std::cout << "\nРабота завершена\n\n";
    }

    int arr2[12] {1,2,3,4,5,6,7,8,9,10,11,12};
    int *p = arr2;
    for (int i = 0; i < 12/2; ++i, p++)
    {
        int temp = *p++;
        *--p = *p;
        *++p = temp;
    }
    for (int i = 0; i < 12; ++i)
        std::cout << arr2[i] <<  " ";


    m = 0;
    int n = 0;

    while (true)
    {
        std::cout << "\nВведите колличество строк: ";
        std::cin >> m;
        std::cout << "Введите колличество столбцов: ";
        std::cin >> n;
        if (m == 0 || n == 0)
        {
            std::cout << "\n\tВведены неверные данные\n";
            return 0;
        }
        break;
    }


    int **matrix1 = new int *[m];
    for (int i = 0; i < m; i++)
        matrix1[i] = new int[n];
    val2matr(matrix1, m, n);
    print_matrix(matrix1, m, n);
    return 0;
}


