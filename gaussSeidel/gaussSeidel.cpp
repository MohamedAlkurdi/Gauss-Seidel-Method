#include <iostream>
using namespace std;

const double arr[][4] = {
    {10, 2, 1, 7},
    {1, 5, 1, -8},
    {2, 3, 10, 6}
};

const double epsilon = 0.001;

bool error_1 = false;
bool error_2 = false;
bool error_3 = false;

double x1_value = 0;
double x2_value = 0;
double x3_value = 0;

bool hasError() {
    return !(error_1 && error_2 && error_3);
}

void calc_x1() {
    const double result = arr[0][3];
    double operation = (result - (arr[0][1] * x2_value) - (arr[0][2] * x3_value)) / arr[0][0];
    if (abs(operation - x1_value) < epsilon) {
        error_1 = true;
    }
    x1_value = operation;
    cout << "current x1:" << x1_value << endl;
}

void calc_x2() {
    const double result = arr[1][3];
    double operation = (result - (arr[1][0] * x1_value) - (arr[1][2] * x3_value)) / arr[1][1];
    if (abs(operation - x2_value) < epsilon) {
        error_2 = true;
    }
    x2_value = operation;
    cout << "current x2:" << x2_value << endl;
}

void calc_x3() {
    const double result = arr[2][3];
    double operation = (result - (arr[2][0] * x1_value) - (arr[2][1] * x2_value)) / arr[2][2];
    if (abs(operation - x3_value) < epsilon) {
        error_3 = true;
    }
    x3_value = operation;
    cout << "current x3:" << x3_value << endl;
}

int main() {
    do {
        calc_x1();
        calc_x2();
        calc_x3();
        cout << "=========================" << endl;
    } while (hasError());
}