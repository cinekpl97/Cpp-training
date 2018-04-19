#include <iostream>

using namespace std;

struct Arg {
    double x, y;
};

double newtonInterpolation(Arg f[], int numberOfPoints, double x) {
    double tempSize = numberOfPoints;
    double final = 0;
    auto *sums = new double[numberOfPoints - 1];
    auto *coefficient = new double[numberOfPoints];
    int helper = 1;

    coefficient[0] = f[0].y;

    for (int i = 0; i < tempSize - 1; i++) {
        sums[i] = f[i + 1].y - f[i].y;
    }
    for (int j = 0; j < tempSize - 1; j++) {
        sums[j] /= (f[j + 1].x - f[j].x);
    }
    coefficient[helper] = sums[0];
    tempSize--;
    int rzad = 1;

    while (tempSize > 1) {
        rzad++;
        for (int i = 0; i < tempSize - 1; i++) {
            sums[i] = sums[i + 1] - sums[i];
        }

        for (int i = 0; i < tempSize - 1; i++) {
            sums[i] /= (f[i + rzad].x - f[i].x);
        }

        helper++;
        coefficient[helper] = sums[0];
        tempSize--;
        auto *multiArray = new double[numberOfPoints];

        for (int i = 1; i < numberOfPoints; i++) {
            multiArray[i] = 1;
        }

        for (int i = 1; i < numberOfPoints; i++) {
            for (int j = 0; j < i; j++) {
                multiArray[i] *= x - f[j].x;
            }

            coefficient[i] *= multiArray[i];
        }

        for (int i = 0; i < numberOfPoints; i++) {
            final += coefficient[i];
        }

    }

    return final;

}


int main() {
    Arg f[] = {
            {0, 0},
            {2, 8},
            {3, 27},
            {5, 125},
            {6, 216}
    };
    cout << newtonInterpolation(f, 5, 4);

    return 0;
}