#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void increment(double& value);
int main(void)
{
    double pi = 3.14;
    double& piref = pi;
    increment(piref);
    cout << pi <<endl;
}

void increment(double& value) {
    value++;
}