#include <iostream>

using std::cout;
using std::endl;

int main(void)
{

    typedef int Integer;
    typedef char Character;
    typedef std::string String;
    typedef double DoubleArray;
    typedef float *floatPtrArray;

    Integer *a = new Integer(1);
    Character *b = new Character('b');
    String *c = new String("cee");
    DoubleArray *d = new DoubleArray[1];
    d[0] = 4.4;
    d[1] = 4.8;
    float flt = 5.5;
    floatPtrArray *fpa = new floatPtrArray{&flt};

    cout << "*a: " << *a << endl;
    cout << "*b: " << *b << endl;
    cout << "*c: " << *c << endl;
    cout << "d[0]: " << d[0] << endl;
    cout << "d[1]: " << d[1] << endl;
    cout << "fpa[0]: " << fpa[0] << endl;
    cout << "*fpa[0]: " << *fpa[0] << endl;
    
}