#include "HFile.h"

void print(matrix M)
{
    int rows = M.rows;
    int columns = M.columns;
    std::cout << M.name << " =\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            std::cout << M.A[i][j] << "\t";
        }
        std::cout << "\n";
    }
}

void matrix::operator= (matrix B) // A = B;
{
    int i;
    //�������� ������� ������� A
    for (i = 0; i < rows; i++)
    {
        delete[] A[i];
    }
    delete[] A;

    //����� ����� ����� � ��������
    rows = B.rows;
    columns = B.columns;

    //�������� ������ �������
    A = new double* [rows];
    for (i = 0; i < rows; ++i)
    {
        A[i] = new double[columns];
    }


    // ���������� ������ �������
    for (i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; j++)
        {
            *(*(A + i) + j) = B.A[i][j];
        }
    }
}

matrix matrix::operator+(matrix B)
{
    //������� ����� ������
    double** sum;
    sum = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        sum[i] = new double[columns];
    }
    //���������� ������� �����
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; j++)
        {
                    sum[i][j] = A[i][j] + B.A[i][j];
        }
    }


    // �������� ������� - ����������
    matrix summ(sum, rows, columns);

    return summ;
}

//��������� ������� �� �����
matrix matrix::operator*(double a)
{
    double** result = new double* [rows];
    

    for (int i = 0; i < rows; i++)
    {
        result[i] = new double[columns];
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            *(*(result + i) + j) = a * A[i][j];
        }
    }

    matrix mult_on_number(result, rows, columns, name);

    return mult_on_number;
}

// ���������� �������� �������
void matrix::setItem(double val, int r, int c)
{
    A[r][c] = val;
}

//����������� ������
matrix matrix::operator*(matrix B)
{
    if (columns == B.rows)
    {
        matrix C(NULL, rows, B.columns);
        double item;
        item = 0.;

        for (int i = 0; i < rows; i++)
            for (int j = 0; j < B.columns; j++)
            {
                for (int k = 0; k < columns; k++)
                {
                    item += A[i][k] * B.A[k][j];
                    C.A[i][j] = item;
                }
                item = 0.;
            }
        return C;
    }
}


// ����� ������� �����, ��� ��������� �������
// � �������������
matrix swapRowsAssig(matrix B, int one, int two)
{
    matrix res;
    res = B;
    double swap;
    for (int i = 0; i < B.columns; i++)
    {
        swap = res.A[two][i];
        res.A[two][i] = res.A[one][i];
        res.A[one][i] = swap;
    }
    return res;
}

// �������� ����� �������
// � ���������� ������ ����������
void swapRows(matrix& B, int one, int two)
{
    double swap;
    for (int i = 0; i < B.columns; i++)
    {
        swap = B.A[two][i];
        B.A[two][i] = B.A[one][i];
        B.A[one][i] = swap;
    }
}

