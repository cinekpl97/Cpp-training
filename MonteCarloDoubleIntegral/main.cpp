#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

double function(double x, double y) {
    return (x * x) + (3 * x * y);
}

double randomNumber(double xbeg, double xend) {
    return (xbeg + (double) rand() / (double) (RAND_MAX) * (xend - xbeg));
}

double monteCarloMethod(double xbeg, double xend, double ybeg, double yend, int n) {
    double integral = 0;
    for (int i = 0; i < n; i++) {
        double x = randomNumber(xend, xbeg);
        double y = randomNumber(yend, ybeg);
        integral = integral + function(x, y);
    }
    double approximateValueOfFunction = (integral * (xend - xbeg) * (yend - ybeg)) / n;
    return approximateValueOfFunction;
}

int main() {
    srand(time(nullptr));
    cout << monteCarloMethod(2, 10, 2, 4, 10) << endl;
    cout << monteCarloMethod(2, 10, 2, 4, 100) << endl;
    cout << monteCarloMethod(2, 10, 2, 4, 1000) << endl;
    cout << monteCarloMethod(2, 10, 2, 4, 10000) << endl;
    cout << monteCarloMethod(2, 10, 2, 4, 100000) << endl;
    cout << monteCarloMethod(2, 10, 2, 4, 1000000) << endl;

    return 0;
}
