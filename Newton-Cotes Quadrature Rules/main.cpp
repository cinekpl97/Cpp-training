#include <iostream>

using namespace std;

double function(double value) {

}

double newtonCotesQuadrature(double a, double b, double amountOfNodes) {
    double S = 5 * (function(a) + function(b));
    double step = (b - a) / amountOfNodes;
    double x = a + step;
    double i = 1;
    while (i != amountOfNodes) {
        S = S + function(x);
        x = x + step;
        i = i + 1;
    }
    S = S + step;
    return S;
}

int main() {


    return 0;
}