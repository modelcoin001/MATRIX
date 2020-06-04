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

    double getMij(int, int);//�������� ������� �� �������
    void setMij(int, int, double);//��������� �������� �������� � ��������
    int getSizeX();//���������� ������ �� �
    int getSizeY();//���������� ������ �� �
    void print();//������� ������� �� �����

    friend Matrix operator+(const Matrix& left, const Matrix& right);//��������
    friend Matrix operator-(const Matrix& left, const Matrix& right);//���������
    friend Matrix operator*(const Matrix& left, const double right);//������������ �� �����
    friend Matrix operator*(const Matrix& left, const Matrix& right);//������������ ���������
    friend Matrix operator!(const Matrix& M);//����������������
    Matrix& operator=(const Matrix& right);//�������� ������������ ������������
};
