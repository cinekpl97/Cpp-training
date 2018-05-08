#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return 2 * (x * x * x * x);
}

double firstRow(double a, double b) {
    double h = fabs(b - a);
    double sum = h / 2 * (function(a) + function(b));
    return sum;
}

double fourthRow(double a, double b, double c, double d, double e) {
    double h = fabs(b - a);

    double sum =
            (2 * h / 45) * (7 * function(a) + 32 * function(b) + 12 * function(c) + 32 * function(d) + 7 * function(e));

    return sum;
}

double firstRowIntegral(double a, double b, int n) {
    double step = fabs(b - a) / n;

    double integral = 0;

    for (int i = 0; i < n; i++) {
        integral += firstRow(a + i * step, a + step + i * step);
    }

    return integral;
}

double fourthRowIntegral(double a, double b, int n) {
    double step = fabs(b - a) / n;
    double integral = 0;
    for (int i = 0; i < n; i++) {
        double x0 = a + i * step;
        double x4 = a + step + i * step;
        double x2 = (x0 + x4) / 2;
        double x3 = (x2 + x4) / 2;
        double x1 = (x0 + x2) / 2;


        integral += fourthRow(x0, x1, x2, x3, x4);
    }
    return integral;

}

int main() {
    cout << "1 rzad: " << endl;
    cout << firstRowIntegral(3, 10, 1) << endl;
    cout << firstRowIntegral(3, 10, 2) << endl;
    cout << firstRowIntegral(3, 10, 4) << endl;
    cout << firstRowIntegral(3, 10, 8) << endl;
    cout << firstRowIntegral(3, 10, 16) << endl;
    cout << endl;
    cout << "2 rzad: " << endl;
    cout << fourthRowIntegral(3, 10, 1) << endl;
    cout << fourthRowIntegral(3, 10, 2) << endl;
    cout << fourthRowIntegral(3, 10, 4) << endl;
    cout << fourthRowIntegral(3, 10, 8) << endl;
    cout << fourthRowIntegral(3, 10, 16) << endl;
    cout << fourthRowIntegral(3, 10, 32) << endl;
    cout << fourthRowIntegral(3, 10, 64) << endl;


    return 0;
}