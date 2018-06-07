
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

void gaussSeidel(int iterations, int numberOfEquations) {
    cout.precision(4);
    cout.setf(ios::fixed);
    int i, j, k, flag = 0, count = 0;
    double a[numberOfEquations][
            numberOfEquations + 1];            //declare a 2d array for storing the elements of the augmented matrix
    double x[numberOfEquations];                //declare an array to store the values of variables
    double eps, y;
    cout << "\nEnter equation values (by rows)\n";
    for (i = 0; i < numberOfEquations; i++)
        for (j = 0; j <= numberOfEquations; j++)
            cin >> a[i][j];
    cout << "\nEnter beginning x values:\n";
    for (i = 0; i < numberOfEquations; i++)
        cin >> x[i];
    cout << "\nEnter the accuracy up to which you want the solution:\n";
    cin >> eps;
    for (i = 0; i <
                numberOfEquations; i++)                    //Pivotisation(partial) to make the equations diagonally dominant
        for (k = i + 1; k < numberOfEquations; k++)
            if (abs(a[i][i]) < abs(a[k][i]))
                for (j = 0; j <= numberOfEquations; j++) {
                    double temp = a[i][j];
                    a[i][j] = a[k][j];
                    a[k][j] = temp;
                }
    cout << endl;
    for (i = 0; i < numberOfEquations; i++)
        cout << "x" << i << " ";
    do                            //Perform iterations to calculate x1,x2,...xn
    {
        cout << "\n" << count + 1 << "." << setw(16);
        for (i = 0; i < numberOfEquations; i++)                //Loop that calculates x1,x2,...xn
        {
            y = x[i];
            x[i] = a[i][numberOfEquations];
            for (j = 0; j < numberOfEquations; j++) {
                if (j != i)
                    x[i] = x[i] - a[i][j] * x[j];
            }
            x[i] = x[i] / a[i][i];
            if (abs(x[i] - y) <= eps)            //Compare the ne value with the last value
                flag++;
            cout << x[i] << setw(18);
        }
        cout << "\n";
        count++;
    } while (flag <
             numberOfEquations);                        //If the values of all the variables don't differ from their previious values with error more than eps then flag must be numberOfEquations and hence stop the loop

    cout << "\n The solution is as follows:\n";
    for (i = 0; i < numberOfEquations; i++)
        cout << "x" << i << " = " << x[i] << endl;        //Print the contents of x[]+
}

int main() {
    gaussSeidel(5, 3);
}