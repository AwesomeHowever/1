// 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <fstream>
#include "HFile.h"

//дружественный структуре метод вывода на экран



int main()
{
    restart:
    setlocale(0, "");
    std::ifstream matr("matr.txt");
    int rows, columns, i, j;
    double** A;
    char move;


    // тест 1 нулевая матрица 1x1
    std::cout << "\nтест 1 нулевая матрица 1x1\n";
    matrix M1;
    print(M1);


    // тест 2 нулевая матрица 2х3
    std::cout << "\nтест 2 нулевая матрица 2х3\n";
    matrix M2(NULL, 2, 3);
    print(M2);

    /* 
    * чтобы сделать ненулевую, необходимо
    * задать двумерный массив
    * вводится массив из файла
    */

    if (!matr)
    {
        
        std::cerr << "matr.txt could not be opened for reading!" << std::endl;
        exit(1);
    }

    matr >> rows;
    matr >> columns;

    A = new double* [rows];
    for (i = 0; i < rows; i++)
    {
        A[i] = new double[columns];
    }

    // считывание элементов
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            matr >> A[i][j];
        }
    }
    std::cout << "\n";
    // создание объекта
    std::cout << "\nтест 3 чтение из файла матрицы 3х5\n";
    matrix M3(A, rows, columns);
    print(M3);

    //освобождение памяти
    for (i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;


    // тест 4 сумма матриц
    std::cout << "\nтест 4 оператор присваивания и сумма матриц 3х5\n";
    matrix B(NULL, 1, 1, "B");
    B = M3; //тест operator=
    print(B);
    std::cout << "A + B = C\n";

    matrix C(NULL, 1, 1, "C");
    C = M3 + B; //тест operator= и operator+
    print(C);

    //тест operator* на число
    std::cout << "\nтест 5 оператор произведения на число 3 матрицы 3х5\n";
    C = M3 * 3.0;
    print(C);
    std::cout << "успех\n";

    //тест 6 смена строк местами
    // с присваиванием
    std::cout << "\nтест 6 смена строк 1 и 2 местами матрицы 3х5\n";
    C = swapRowsAssig(M3, 0, 1);
    print(C);
    std::cout << "успех\n";


    //тест 7 смена строк местами
    // с изменением объека
    std::cout << "\nтест 7 смена строк 1 и 2 местами матрицы 3х5\n";
    swapRows(M3, 0, 1);
    print(M3);
    std::cout << "успех\n";


    //тест 8 оператор произведения матриц
    std::cout << "\nтест 8 оператор произведения матриц 3х3\nAxA=C";

    //чтение дополнительной матрицы из файла
    matr >> rows;
    matr >> columns;

    A = new double* [rows];
    for (i = 0; i < rows; i++)
    {
        A[i] = new double[columns];
    }

    // считывание элементов
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            matr >> A[i][j];
        }
    }

    std::cout << "\n";

    // создание объекта
    matrix A1(A, rows, columns);
    print(A1);
    std::cout << "\n";
    matrix B1(A, rows, columns);
    matrix C1(NULL, rows, columns, "C");

    C1 = A1 * B1;
    print(C1);
    std::cout << "успех\n";

    //освобождение памяти
    for (i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;


    std::cout << "Hello World!\n";
    move = getchar();
    if (move == 'r') { goto restart; }
    move = getchar();
    if (move == 'r') { goto restart; }
    move = getchar();
    if (move == 'r') { goto restart; }
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
