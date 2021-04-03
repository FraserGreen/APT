#include <iostream>

using std::cout;
using std::endl;

void doubleArray(int* values, int length);

int main(void)
{

    int length = 10;

    int array[length] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    doubleArray(array, length);
    for (int i = 0; i < length; i++)
        cout << array[i] << endl;
}

void doubleArray(int* values, int length)
{
    for (int i = 0; i < length; i++)
    {
        values[i] *= 2;
    }
}