#include <iostream>

using namespace std;

double dyDivideDx(double x) {
    return 2*x;
}

void crankNicholsonMethod(double y[], double step, int N) {
    for (int i = 0; i < N / step - 1; i++) {
        y[i + 1] = y[i] + step * 0.5 * (dyDivideDx(i+1) + dyDivideDx(i));
    }
    for(int i = 0; i< N/step; i++){
        cout<<"x"<<i<<" = "<< y[i]<<endl;
    }
}

int main() {
    int N = 5;
    double step = 1;
    double amountOfCounts = N / step;
    auto intAmountOfCounts = (int) amountOfCounts;
    auto *y = new double[intAmountOfCounts];
    y[0] = 0;
    crankNicholsonMethod(y, step, N);
    return 0;
}