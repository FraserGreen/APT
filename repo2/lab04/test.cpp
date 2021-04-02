#include <iostream>
using namespace std;

class Test;


int main(void)
{
    Test *test = new Test();
    test->printHello();
}

class Test
{
public:
    Test();
    void printHello();
};

Test::Test()
{
    cout << "Object created." << endl;
}

void Test::printHello()
{
    cout << "Hello" << endl;
}