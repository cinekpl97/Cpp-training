#include <iostream>

using namespace std;

double function(double x) {
    return (x * x);
}

double TrapesoidalMethod(double xbeg, double xend, int enquatity) {

    double sum, dx;

    sum = 0;
    dx = (xend - xbeg) / enquatity;

    for (int i = 1; i < enquatity; ++i) {
        sum += function(xbeg + i * dx);
    }
    sum = (sum + (function(xbeg) + function(xend) / 2)) * dx;
    return sum;
}

int main() {
    cout << TrapesoidalMethod(2, 10, 10000);


    return 0;
}