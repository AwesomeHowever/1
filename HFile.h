#pragma once
#include <iostream>
#include <cstring>

struct matrix
{
    int rows;
    int columns;
    double** A;
    std::string name;


    /*          ����������� ������
    * �� ���� ������������ ��������� �����������
    * ��������� �� ��������� ������, ����� �����,
    * ����� ��������. � ������, ����� ���������
    * �� ������, �� ��������� �������� �������
    * 1�1 � ����. ���� ����� ����� � ��������
    * ������, � ��������� �� ������ ���, �����
    * �������� ����������� ������ ������� ���-
    * ���� rows x columns.
    */
    matrix(double** IN = NULL, int _rows = 1, int _columns = 1, std::string _name = "A")
    {
        int i, j;
        rows = _rows;
        columns = _columns;
        A = new double* [rows];
        for (i = 0; i < rows; i++)
        {
            *(A + i) = new double[columns];
            // *(A + i) ����������� A[i]
        }
        if (IN != NULL) {
            for (i = 0; i < rows; ++i)
                for (j = 0; j < columns; ++j)
                {
                    *(*(A + i) + j) = *(*(IN + i) + j);
                }
        }
        else
        {
            for (i = 0; i < rows; ++i)
                for (j = 0; j < columns; ++j)
                {
                    *(*(A + i) + j) = 0.;
                    // *(*(A + i) + j) ����������� A[i][j]
                }
        }
        name = _name;
    }

    //���������� �������, ������������ ���
    void setItem(double val, int r, int c);
    void operator= (matrix B);
    matrix operator+(matrix B);
    matrix operator*(double a);
    matrix operator*(matrix B);
};

void print(matrix );
matrix swapRowsAssig(matrix, int, int);
void swapRows(matrix& , int , int );

