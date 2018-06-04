#include <iostream>

using namespace std;

void Jacobi_Method(){
    const int matrixSize = 4;
    const int iterations = 1;
    double A[][matrixSize] = {{4,   -1, 0.2, 2},
                              {-1,  5,  0,   -3},
                              {0.2, 1,  10,  -1},
                              {0,   -2, -1,  4}
    };
    double b[] = {30, 0, -10, 5};
    double N[matrixSize];
    double M[matrixSize][matrixSize];
    double x1[matrixSize], x2[matrixSize];

// Calculate N = D^-1
    for (int i = 0; i < matrixSize; i++) {
        N[i] = 1 / A[i][i];
    }

// Calculate M = -D^-1 (L + U)
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++)
            if (i == j) {
                M[i][j] = 0;
            } else {
                M[i][j] = -(A[i][j] * N[i]);
            }
    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize; j++) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < matrixSize; ++i) {
        cout << N[i] << ' ';
    }
    cout << endl;

//Initialize x
    for (int i = 0; i < matrixSize; i++) {
        x1[i] = 0;
    }

    for (int k = 0; k < iterations; k++) {
        for (int i = 0; i < matrixSize; i++) {
            x2[i] = N[i] * b[i];
            for (int j = 0; j < matrixSize; j++) {
                x2[i] += M[i][j] * x1[j];
            }
        }
        for (int i = 0; i < matrixSize; i++) {
            x1[i] = x2[i];
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        cout << "x" << i + 1 << " = " << x1[i] << endl;
    }
}

int main() {


    return 0;

}