#include <iostream>
#include <cmath>

using namespace std;

double function(double x) {
    return sin(x);
}

double trapezoidalRule(double a, double b, int n) {
    double h = (double) (b - a) / n;
    double sum = 0;

    for (int i = 1; i < n; ++i) {
        sum += function(a + (i * h));
    }
    return (h / 2) * (function(a) + function(b) + 2 * sum);
}

double parabolaRule(int a, int b, int n) {
    double h = (double) (b - a) / n;
    double sum1 = 0;
    double sum2 = 0;

    for (int i = 1; i < n; ++i) {
        sum1 += function(a + (i * h));
    }

    for (int i = 0; i < n; ++i) {
        sum2 += function(a + (i * h) + (h / 2));
    }

    return (h / 6) * (function(a) + function(b) + 2 * sum1 + 4 * sum2);
}

int main() {
    cout << parabolaRule(0, 1, 1000) << endl;
    return 0;
}