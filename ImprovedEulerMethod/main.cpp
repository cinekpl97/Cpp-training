#include <iostream>

using namespace std;

double dyDivideDx(double x, double y) {       //Function
    return y;
}


void improvedEulerMethod(double y[], double step, int N) {
    int amountOfCounts = N / step;
    for (int n = 0; n < N / step - 1; n++) {
        y[n + 1] = y[n] + (step / 2) * (dyDivideDx(n, y[n]) + dyDivideDx(n + 1, (y[n] + step * dyDivideDx(n, y[n]))));
    }
    for (int n = 0; n < N / step - 1; n++) {
        cout<<"x"<<n<<" = "<< y[n]<<endl;
    }
}

int main() {
    int N = 5;
    double step = 0.2;
    double amountOfCounts = N / step;
    auto intAmountOfCounts = (int) amountOfCounts;
    auto *y = new double[intAmountOfCounts];
    auto *yBack = new double[intAmountOfCounts];
    auto *yForward = new double[intAmountOfCounts];
    y[0] = 1;

    improvedEulerMethod(y, step, N);
    return 0;
}