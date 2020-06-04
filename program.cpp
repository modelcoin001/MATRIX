#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int x = 2;
    int y = 3;
    Matrix M(x, y);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            M.setMij(i, j, double(i) + double(j));
        }
    }

    Matrix N(x, y);
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            N.setMij(i, j, 2*(double(i) + double(j)));
        }
    }

 
    Matrix R(y, x);
    R = M + N;
    cout << "Матрица M" <<endl ;
    M.print();
    cout << endl;

    cout << "Матрица N" << endl;
    N.print();
    cout << endl;

    cout << "Матрица R = M + N" << endl;
    R.print();
    cout << endl;

    R = M - N;
    cout << "Матрица R = M - N" << endl;
    R.print();
    cout << endl;

    R = M * 2;
    cout << "Матрица R = M * 2" << endl;
    R.print();
    cout << endl;

    R = !N;
    cout << "Транспонированная матрица N" << endl;
    R.print();
    cout << endl;

    Matrix A(x, y);
    A = !N;
    R = M * A;
    cout << "Произведение матрицы M и транспонированной матрицы N" << endl;
    R.print();
}