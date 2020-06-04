#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
    int m;
    int n;
    double** a;
public:
    Matrix();
    Matrix(int, int);
    //~Matrix();

    double getMij(int, int);//получить элемент по индексу
    void setMij(int, int, double);//присвоить значение элементу с индексом
    int getSizeX();//возвращает размер по ’
    int getSizeY();//возвращает размер по ”
    void print();//выводит матрицу на экран

    friend Matrix operator+(const Matrix& left, const Matrix& right);//сложение
    friend Matrix operator-(const Matrix& left, const Matrix& right);//вычитание
    friend Matrix operator*(const Matrix& left, const double right);//произведение на число
    friend Matrix operator*(const Matrix& left, const Matrix& right);//произведение наматрицу
    friend Matrix operator!(const Matrix& M);//транспонирование
    Matrix& operator=(const Matrix& right);//оператор присваивание копированием

};



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
            cout << a[i][j] << "\t";
        }
        cout << endl;
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
        cout << "ћатрицы разного размера";
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
        cout << "ћатрицы разного размера";
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

        cout << "ћатрицы таких размеров перемножать нельз€";
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
            cout << M.getMij(i, j) << "\t";
        }
        cout << endl;
    }
}