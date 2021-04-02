#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAX_CHARS_PER_LINE 1000

void printLineByLine(string filename);
int countLines(string filename);
int countCharacters(string filename);

int main(string args[])
{
    if (args->size()!= 2){
        cout << "Usage: ./myWC <type> <filename>" << endl;
    }
    //args[0] -l for number of lines, -c for number of characters



    //args[1] text file to be read

    string filename = "myCountry.txt";
    // printLineByLine(filename);
    cout << "Lines: " << countLines(filename) << endl;
    cout << "Characters: " << countCharacters(filename) << endl;
}

int countCharacters(string filename)
{
    std::ifstream poem;
    poem.open(filename);

    int numCharacters = 0;
    while (poem.get() != -1)
    {
        numCharacters++;
    }
    return numCharacters;
}
int countLines(string filename)
{
    std::ifstream poem;
    poem.open(filename);

    int numLines = 0;
    while (!poem.eof())
    {
        if (static_cast<char>(poem.get()) == '\n')
            numLines++;
    }
    return numLines;
}

void printLineByLine(string filename)
{
    // access .txt file
    std::ifstream poem;
    poem.open(filename);

    // read file line by line, printing each one
    while (!poem.eof())
    {
        char line[MAX_CHARS_PER_LINE];
        poem.getline(line, MAX_CHARS_PER_LINE, '\n');
        cout << line << endl;
    }

    // close the file
    poem.close();
}
