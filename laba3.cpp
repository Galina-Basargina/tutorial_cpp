#include <iostream>
#include <cstdlib>
#include <string>
#include <array>
// using namespace std;

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

int main() 
{
    srand(time(0));
    int numb = rand() % 100 + 1;
    
    int n = 5;
    int m = 4;

    int **matrix1 = new int *[m];
    for (int i = 0; i < m; i++)
        matrix1[i] = new int[n];
    // int matrix1[m][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            matrix1[i][j] = rand() % 11;
            // matrix1[i][j] = 0;
            // std::cout << "matrix1: " <<  matrix1[i][j] << '\n';
        }
    
    int ans1[m];
    for (int i = 0; i < m; i++)
        ans1[i] = 0;
    int min = n;
    int i_min = -1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix1[i][j] % 2 == 0)
                ans1[i]++;
            // std::cout << "i: " << i << "\tans1[i]: " << ans1[i] << "\tmatr[i][j]: " << matrix1[i][j];
            // std::cout <<"\tчет/нечет: " << !(matrix1[i][j] % 2) << '\n';
        }
        if (ans1[i] < min)
            {
                i_min = i;
                min = ans1[i];
            }
        // std::cout << "ans1[i]: " << ans1[i] << '\n';    
    }
    std::cout << "ans[" << i_min << "] = " << min << '\n';
    print_matrix(matrix1, m, n);


    bool is_null = true;
    long unsigned int ans2 = 1;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            if (matrix1[i][j] != 0)
            {
                ans2 *= matrix1[i][j];
                is_null = false;
            }
        }
    if (is_null)
        std::cout << "Матрица вся в 0\n";
    else
        std::cout << "ans2: " << ans2 << '\n';
    print_matrix(matrix1, m, n);

    float ans3 = 0.0;
    n = 10;

    int **matrix2 = new int *[n];
    for (int i = 0; i < n; i++)
        matrix2[i] = new int[n];
    // int matrix2[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            matrix2[i][j] = rand() % (j+1) + j;
            if (i == j)
            {
                ans3 += matrix2[i][j];
                // std::cout << "\t\tmatrix2: " << matrix2[i][j] << '\n'; 
            }
            // std::cout << "\t\tmatrix2: " << matrix2[i][j] << '\n';
        }
    // ans3 /= n;
    std::cout <<"Cреднее ариф. главной диагонали: " << ans3 / n << '\n';
    print_matrix(matrix2, n, n);

    bool is_increasing = false;
    std::string str = "";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-1; j++)
        {
            if (matrix2[i][j] <= matrix2[i][j+1])
            {
                // std::cout << matrix2[i][j] << "\t" << matrix2[i][j+1] << '\n';
                is_increasing = true;
            }
            else    
            {
                is_increasing = false;
                break;
            }
        }
        if (is_increasing)
            str = str + std::to_string(i) + " ";
    }
    if (str == "")
        std::cout << "Все строки не возрастают" << '\n';
    else
        std::cout << "Строки, значения которых возрастают: " << str << '\n';
    print_matrix(matrix2, n, n);


    std::cout << "Введите целое число больше 0: ";
    std::cin >> n;
    if (n <= 0)
    {
        std::cout << "Ошибка в данных" << '\n';
        return 0;
    }

    unsigned int ans5 = 1;
    int **matrix3 = new int *[n];
    for (int i = 0; i < n; i++)
        matrix3[i] = new int[n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix3[i][j] = rand() % 25;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
        {
            if (matrix3[i][j] % 2 == 0)
                ans5 *= matrix3[i][j];
        }
    if (ans5 == 1)
        std::cout << "Над главной диагональю четных нет\n";
    else
        std::cout << "Произведение четных значений над главной диалогалью: " << ans5 << '\n';
    print_matrix(matrix3, n, n);

    return 0;
}

