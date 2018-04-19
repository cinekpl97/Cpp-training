#include <iostream>
#include <cmath>

using namespace std;

class ArgumentsAndValues {
public:
    double x, y;
};

void leastSquaresFunctionAproximation(ArgumentsAndValues *f, int amountOfElements, int degreeOfPoly) {
    double a[degreeOfPoly + 1];
    auto **systemOfEquation = new double *[degreeOfPoly + 2];
    for (int i = 0; i < degreeOfPoly + 2; i++) {
        systemOfEquation[i] = new double[degreeOfPoly + 2];
        for (int j = 0; j < degreeOfPoly + 2; j++) {
            systemOfEquation[i][j] = 0;
        }
    }

    double sum[degreeOfPoly + 1];

    for (int i = 0; i < degreeOfPoly + 1; i++) {

        for (int j = i;
             j < degreeOfPoly + 1 + i; j++) {
            for (int k = 0; k < amountOfElements; k++) a[i] = a[i] + pow(f[k].x, j);
            systemOfEquation[i][j - i] = a[i];
            a[i] = 0;
        }

    }
    for (int k = 0; k < degreeOfPoly + 1; k++) {
        for (int i = 0; i < amountOfElements; i++) sum[k] = sum[k] + (pow(f[i].x, k) * f[i].y);
    }
    for (int i = 0; i < degreeOfPoly + 1; i++) {
        systemOfEquation[i][degreeOfPoly + 2] = sum[i];
    }

    for (int i = 0; i < degreeOfPoly + 1; i++) {
        for (int j = 0; j < degreeOfPoly + 1; j++) {
            cout << systemOfEquation[i][j] << "*a" << j;
            if (j != degreeOfPoly) cout << " + ";
        }
        cout << " = " << systemOfEquation[i][degreeOfPoly + 2] << endl;
    }



}


int main() {
    ArgumentsAndValues f[] = {
            {-5, -110},
            {-4, -60},
            {-3, -20},
            {-2, -10},
            {-1, -1.5},
            {0,  2},
            {1,  7},
            {2,  18},
            {3,  50},
            {5,  170}
    };
    leastSquaresFunctionAproximation(f, 10, 2);
    return 0;
};
