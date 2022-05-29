#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

const int N = 4;

double f(double x) {
    return N * pow(x, max(20 - N, N)) + (N + 2) * pow(x, max(20 - N, N) - 1) + (N - 3) * pow(x, max(20 - N, N) - 2);
}
void points() {
    double points[14] = {};
    double function_value[14] = {};

    points[0] = 0;
    for (int k = 1; k < 14; k++) {
        points[k] = points[k - 1] + (14 - 0) / 14;
    }

    for (int k = 0; k < 14; k++) {
        function_value[k] = f(points[k]);
    }
    cout << "x_k: ";
    for (int i = 1; i <= 14; i++)
    {
        cout << points[i - 1] << "  ";
    }
    cout << endl;
    cout << "f[x_k]: ";
    for (int i = 1; i <= 14; i++)
    {
        cout << function_value[i - 1] << "   ";
    }
}

void solve() {
    int numberOfDots = max(20 - N, N) - ((int)N % 3) - 1;
    for (int i = 0; i < numberOfDots; i++) {

        double denom = 1;
        for (int j = 0; j < numberOfDots; j++) {
            if (i != j) {
                denom *= i - j;
            }
        }
        cout << (f(i) / denom);
        for (int j = 0; j < numberOfDots; j++) {
            if (i != j) {
                cout << " * (x - " << j << ")";
            }
        }
        if (i < numberOfDots - 1) {
            cout << "\n + ";
        }
    }
}

int main() {
    cout << "test\n";
    points();
    cout << endl << endl << endl;
    solve();
    return 0;
}