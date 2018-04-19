#include <iostream>

using namespace std;

class ArgumentAndValue {
public:
    int x, y;
};

int factorial(int n) {
    if (n == 0) return 1;
    else return n * factorial(n - 1);
}

double lagrangeLapse(ArgumentAndValue x[], double xi, int n) {
    double result = 0.0;
    double Mn = xi / factorial(n + 1);

    for (int i = 0; i < n; i++) {
        result += Mn * (xi - x[i].x);
    }

    return result;
}

double interpolation(ArgumentAndValue f[], int xi, int n) {

    double result = 0;
    for (int i = 0; i < n; i++) {
        double term = f[i].y;
        for (int j = 0; j < n; j++) {
            if (j != i) term = term * (xi - f[j].x) / double(f[i].x - f[j].x);
        }
        result += term;
    }
    return result;
}

int main() {
    ArgumentAndValue f[] = {{-1, -1},
                            {0,  0},
                            {1,  1},
                            {10, 10},
                            {12, 12}};
    cout << interpolation(f, 3, 5) << endl;
    cout << lagrangeLapse(f, 3, 5);
    return 0;
}