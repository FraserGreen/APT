#include <iostream>

using std::cout;
using std::endl;

int main(void)
{

    typedef int Integer;
    typedef char Character;
    typedef std::string String;
    typedef double DoubleArray[];
    typedef float *floatPtrArray[];

    Integer a = 1;
    Character b = 'b';
    String c = "cee";
    DoubleArray d{1.2, 3.4};

    float flt = 5.5;
    floatPtrArray fpa{&flt};

    cout << "a: " << a << ", b: " << b <<
     ", c: " << c << ", d[0]: " << d[0] <<
      ", d[1]: " << d[1] << ", fpa[0]: " <<
       fpa[0] << ", *fpa[0]: " << *fpa[0] << endl;
}