#include <iostream>
#include <math.h>

using std::cin;
using std::cout;
using std::endl;

bool getCharacter(char *c);

int main(void)
{
    
    char characters[101];
    int length = 0;
    cout << "input string" << endl;
    for (int i = 0; i < 101 && !cin.eof(); i++)
    {
        cin >> characters[i];
        if (cin.eof() || i==100)
        {
            characters[i] = '\0';
            length = i;
        }
    }

    cout << "the characters in forward order: " << characters << endl;


    int j = length;
    j--; //to exclude exit character (\0)

    for (int i = 0; i < floor(length/2); i++, j--)
    {
        char temp = characters[i];
        characters[i] = characters[j];
        characters[j] = temp;
    }
    cout << "the characters in reverse order: " << characters << endl;
}