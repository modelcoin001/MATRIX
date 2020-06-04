
#include "matrix.h"
#include <iostream>

Matrix::Matrix() //конструктор по умолчанию. ¬озвращает пустую матрицу
{
    m = 0;
    n = 0;
    a = NULL;
}

Matrix::Matrix(int m1, int n1)//конструктор с двум€ параметрами - шириной и высотой
{
    m = m1;
    n = n1;
    a = new double* [m];
    for (int i = 0; i < m; i++)
        a[i] = new double[n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
}

/*Matrix::~Matrix()//деструктор
 {
     for (int i = 0; i < m; i++)
             delete[] a[i];
         delete[] a;
}*/



double Matrix::getMij(int x, int y)
{
    return a[x][y];
}

void Matrix::setMij(int i1, int j1, double x)//записать в элемент матрицы с координатами [i1] [j1] значение x
{
    a[i1][j1] = x;
}

void Matrix::print()//вывод матрицы на экран
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << a[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int Matrix::getSizeX()//число строк
{
    return m;
}

int Matrix::getSizeY()//число столбцов
{
    return n;
}

Matrix operator+(const Matrix& left, const Matrix& right)
{

    if (left.m == right.m && right.n == left.n)
    {
        Matrix result(left.m, left.n);
        for (int i = 0; i < result.m; i++)
            for (int j = 0; j < result.n; j++)
                result.a[i][j] = left.a[i][j] + right.a[i][j];
        return result;
    }
    else
    {
        std::cout << "ћатрицы разного размера";
        exit(1);
    }
}

Matrix operator-(const Matrix& left, const Matrix& right)
{

    if (left.m == right.m && right.n == left.n)
    {
        Matrix result(left.m, left.n);
        for (int i = 0; i < result.m; i++)
            for (int j = 0; j < result.n; j++)
                result.a[i][j] = left.a[i][j] - right.a[i][j];
        return result;
    }
    else
    {
        std::cout << "ћатрицы разного размера";
        exit(1);
    }
}

Matrix operator*(const Matrix& left, const double right)
{
    Matrix result(left.m, left.n);
    for (int i = 0; i < left.m; i++)
        for (int j = 0; j < left.n; j++)
            result.a[i][j] = left.a[i][j] * right;
    return result;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
    if (left.n == right.m)
    {
        Matrix result(left.m, right.n);
        for (int i = 0; i < left.m; i++)
            for (int j = 0; j < right.n; j++)
                for (int k = 0; k < right.n; k++)
                    result.a[i][j] += (left.a[i][k] * right.a[k][j]);
        return result;
    }
    else

        std::cout << "ћатрицы таких размеров перемножать нельз€";
}

Matrix operator!(const Matrix& M)
{
    Matrix result(M.n, M.m);
    for (int i = 0; i < M.m; i++)
        for (int j = 0; j < M.n; j++)
            result.a[j][i] = M.a[i][j];
    return result;
}

Matrix& Matrix::operator=(const Matrix& right)
{
    if (n != right.n || m != right.m)
    {
        for (int i = 0; i < m; i++)
            delete[] a[i];
        delete[] a;
        n = right.n;
        m = right.m;
        a = new double* [m];
        for (int i = 0; i < m; i++)
            a[i] = new double[n];
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = right.a[i][j];
    return *this;
}

void print(Matrix M)
{
    for (int i = 0; i < M.getSizeX(); i++)
    {
        for (int j = 0; j < M.getSizeY(); j++)
        {
            std::cout << M.getMij(i, j) << "\t";
        }
        std::cout << std::endl;
    }
}