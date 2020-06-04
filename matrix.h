#pragma once
#include <stdlib.h>

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
    int getSizeX();//возвращает размер по Х
    int getSizeY();//возвращает размер по У
    void print();//выводит матрицу на экран

    friend Matrix operator+(const Matrix& left, const Matrix& right);//сложение
    friend Matrix operator-(const Matrix& left, const Matrix& right);//вычитание
    friend Matrix operator*(const Matrix& left, const double right);//произведение на число
    friend Matrix operator*(const Matrix& left, const Matrix& right);//произведение наматрицу
    friend Matrix operator!(const Matrix& M);//транспонирование
    Matrix& operator=(const Matrix& right);//оператор присваивание копированием
};
