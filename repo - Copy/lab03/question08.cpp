#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool getCharacter(char *c);

int main(void)
{

    char* characters = new char[101];
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

    char reverseCharacters[101];

    int j = length;
    j--; //to exclude exit character (\0)

    for (int i = 0; i < length; i++)
    {
        reverseCharacters[i] = characters[j];
        j--;
    }
    reverseCharacters[length] = '\0';
    cout << "the characters in reverse order: " << reverseCharacters << endl;
}

bool getCharacter(char *c)
{
    cout << "Input character." << endl;
    cin >> *c;
    return !cin.eof();
}
