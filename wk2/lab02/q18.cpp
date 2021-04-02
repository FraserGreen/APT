#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Pencil
{
public:
    void draw();

private:
    bool eraser = false;
};

void Pencil::draw()
{
    cout << "doodle" << endl;
}

int main(void)
{
    Pencil pencil;
    pencil.draw();
}
