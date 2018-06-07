#include <iostream>

using namespace std;

void Jacobi_Method(int matrixSize) {
    const int iteration = 5;
    double N[matrixSize];
    double M[matrixSize][matrixSize];
    double x[matrixSize], xtemp[matrixSize];
    double A[][matrixSize] = {{5,  -2, 3},
                              {-3, 9,  1},
                              {2,  -1, -7}
    };
    double b[] = {-1, 2, 3};

    for (int i = 0; i < matrixSize; i++) {
        x[i] = 0;
        xtemp[i] = 0;
    }
    for (int i = 0; i < matrixSize; i++) {
        N[i] = 1 / A[i][i];
    }
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++)
            if (i == j) {
                M[i][j] = 0;
            } else {
                M[i][j] = -(A[i][j] * N[i]);
            }
    }
    cout << "M: " << endl;
    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; j++) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << "N: " << endl;
    for (int i = 0; i < matrixSize; ++i) {
        cout << N[i] << endl;
    }
    cout << endl;
    for (int i = 0; i < matrixSize; i++) {
        x[i] = 0;
    }
    for (int i = 0; i < matrixSize; i++) {
        cout << xtemp[i] << endl;
    }

    for (int i = 0; i < matrixSize; i++) {
        xtemp[i] = N[i] * b[i];
    }
    for(int k=0; k<iteration; k++)
    {
        for(int i=0; i<matrixSize; i++)
        {
            xtemp[i] = N[i] * b[i];
            for(int j=0; j<matrixSize; j++)
            {
                xtemp[i] += M[i][j] * x[j] ;
            }
        }
        cout << "Wyniki numer: " << k + 1 << endl;
        for(int i=0; i<matrixSize; i++)
        {
            cout << "x" << i + 1 << " = " << x[i] << endl;
            x[i] = xtemp[i];
        }
        cout << endl;
    }
}


int main() {
    Jacobi_Method(3);

    return 0;

}