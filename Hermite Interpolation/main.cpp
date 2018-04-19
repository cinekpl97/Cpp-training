#include <iostream>

using namespace std;

void HermiteInterpolation() {
    cout << "How many nodes?" << endl;
    int amountOfNodes = 0;
    cin >> amountOfNodes;
    auto *x = new double[amountOfNodes];
    auto *fx = new double[amountOfNodes];
    auto *fpochx = new double[amountOfNodes];

    for (int i = 0; i < amountOfNodes; i++) fpochx[i] = 0;

    for (int i = 0; i < amountOfNodes; i++) {
        cout << "x" << i << " = ";
        cin >> x[i];
        cout << "fx" << i << " = ";
        cin >> fx[i];
        cout << endl;
    }

    for (int i = 1; i < amountOfNodes; i++) {
        if (x[i] == x[i - 1]) {
            fpochx[i] = fpochx[i - 1] + 1;      //stopien pochodnej
        } else fpochx[i] = 0;
    }

    for (int i = 1; i < amountOfNodes; i++) {
        for (int j = amountOfNodes - 1; j >= i; j--) {
            if (fpochx[j] == 0) {
                fx[j] = (fx[j] - fx[((int) (j - 1 - fpochx[j - 1]))]) / (x[j] - x[j - i]);
            } else {
                fx[j] /= (double) i;
                fpochx[j]--;
            }
        }
    }

    cout << endl << "F(x) po interpolacji Hermite'a" << endl;
    for (int i = 0; i < amountOfNodes; i++) {
        cout << "f(x)" << i + 1 << fx[i] << endl;
    }
    for (int j = amountOfNodes - 1; j >= 0; j--)
        for (int i = j; i < amountOfNodes - 1; i++)
            fx[i] = fx[i] - fx[i + 1] * x[j];

    cout << endl << "f(x) wielomian normalny" << endl;
    for (int i = 0; i < amountOfNodes; i++) {
        cout << "f" << i + 1 << " = " << fx[i] << endl;
    }
    cout << "W(x) = ";
    for (int i = amountOfNodes - 1; i >= 0; i--) {
        if (i == 0) {
            cout << fx[i];
        } else if (i == 1) {
            cout << fx[i] << "x";
        } else cout << fx[i] << "x" << i;
        if ((i - 1) != amountOfNodes - 1) cout << " + ";
    }


}


int main() {
    HermiteInterpolation();
    system("pause");
    return 0;
}