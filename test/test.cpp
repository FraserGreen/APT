#include "test.h"
#include <iostream>

Test::Test(int x, int y)
:_x(x),_y(y)
{

}

int main(int argc, char const *argv[])
{
    Test n;

    std::cout << n._y << std::endl;
    
    n._y = 1;
    
    std::cout << n._y << std::endl;

    return 0;
}
