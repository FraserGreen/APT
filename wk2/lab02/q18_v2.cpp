#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Pencil
{
public:
    Pencil(bool eraser);
    void hasEraser();

private:
    bool eraser;
};


int main(void)
{
    Pencil pencil(true);
    pencil.hasEraser();
}

Pencil::Pencil(bool eraser){
    this->eraser = eraser;
}

void Pencil::hasEraser()
{
    cout << "This pencil does" << (eraser? "" : " not") << " have an eraser."<<  endl;
}
