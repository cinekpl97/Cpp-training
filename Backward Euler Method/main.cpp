#include <iostream>

using namespace std;

double dyDivideDx(double x) {
    return 2 * x;
}

void backwardEulerMethod(double y[], double step, int N) {
    for (int i = 0; i < N * step; i++) {
        y[i + 1] = y[i] + step * dyDivideDx(i+1);
    }
    for (int i = 0; i < N * step; i++) {
        cout << "x" << i << " = " << y[i] << endl;
    }
}

int main() {
    int N = 5;
    double step = 1;
    int amountOfCounts = N * step;
    auto *y = new double[amountOfCounts];
    y[0] = 0;
    backwardEulerMethod(y, step, N);
    return 0;
}