#include <iostream>

using namespace std;

double dydividedx(double x, double y) {
    return y - x * x + 1;
}

double rungeKuttyForthRow(double y[], double N, double step) {
    auto k = new double[4];
    double deltaYn = 0;
    for (int x = 0; x < N / step - 1; x++) {
        k[0] = step * dydividedx(x, y[x]);
        k[1] = step * dydividedx(x + step / 2, y[x] + 0.5 * k[0]);
        k[2] = step * dydividedx(x + step / 2, y[x] + 0.5 * k[1]);
        k[3] = step * dydividedx(x + step, y[x] + k[2]);
        deltaYn = (1.0 / 6.0) * (k[0] + 2 * k[1] + 2 * k[2] + k[3]);
        y[x + 1] = y[x] + deltaYn;
    }
    for (int i = 0; i < N / step - 1; i++) {
        cout << "y" << i << " = " << y[i] << endl;
    }

}

int main() {
    int N = 2;
    double step = 0.5;
    double amountOfCounts = N / step;
    auto intAmountOfCounts = (int) amountOfCounts;
    auto *y = new double[intAmountOfCounts];
    y[0] = 0.5;
    rungeKuttyForthRow(y, N, step);
    return 0;
}