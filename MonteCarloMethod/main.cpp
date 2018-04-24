#include <iostream>
#include <cmath>
#include <ctime>
#include <random>

using namespace std;

double function(double x) {
    return (x * x);
}



double randomNumber(double xbeg, double xend) {
    return (xbeg + (double) rand() / (double) (RAND_MAX) * (xend - xbeg));
}

double MonteCarloMethod(double xbeg, double xend, int n) {
    double integral=0;
    for (int i = 0; i < n; i++) {
        double x = randomNumber(xend, xbeg);
        integral = integral + function(x);
    }
    return (integral*(xend-xbeg))/n;
}

int main() {
    srand(time(nullptr));
    cout << MonteCarloMethod(2, 10, 10)<<endl;
    cout << MonteCarloMethod(2, 10, 100)<<endl;
    cout << MonteCarloMethod(2, 10, 1000)<<endl;
    cout << MonteCarloMethod(2, 10, 10000)<<endl;
    cout << MonteCarloMethod(2, 10, 100000)<<endl;

    return 0;
}


