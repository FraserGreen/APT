#include <iostream>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

#define MAX_CHARS_PER_LINE 1000
void performOperation(char *operation, std::ifstream &input);
int countCharacters(std::ifstream &input);
int countWords(std::ifstream &input);
int countLines(std::ifstream &input);
void printLineByLine(std::ifstream &input);
void printUsage();

int main(int argc, char *argv[])
{
    if (argc != 3)
    { //two args + program name
        cout << "Too " << (argc < 3 ? "few" : "many") << "arguments" << endl;
        printUsage();
    }

    // access .txt file
    std::ifstream input;

    input.open(argv[2]);
    if (input.is_open())
    {
        performOperation(argv[1], input);
    }
    else
    {
        cout << "Error reading file." << endl;
        printUsage();
    }

    // printLineByLine(argv[2]);
}

void performOperation(char *operation, std::ifstream &input)
{
    if (operation == string("-c"))
    {
        cout << "Characters: " << countCharacters(input) << endl;
    }
    else if (operation == string("-l"))
    {
        cout << "Lines: " << countLines(input) << endl;
    }
    else if (operation == string("-w"))
    {
        cout << "Words: " << countWords(input) << endl;
    }
    else
    {
        cout << "Invalid type." << endl;
        printUsage();
    }
}

int countCharacters(std::ifstream &input)
{

    int numCharacters = 0;
    while (input.get() != -1)
    {
        numCharacters++;
    }
    return numCharacters;
}

int countWords(std::ifstream &input)
{
    int numWords = 0;
    string wordBin; //each word gets put in the bin. variable needed or 'input >>' would not work
    while (input >> wordBin)
    {
        numWords++;
    }
    return numWords;
}


int countLines(std::ifstream &input)
{
    int numLines = 0;
    while (!input.eof())
    {
        if (static_cast<char>(input.get()) == '\n')
            numLines++;
    }
    return numLines;
}

void printLineByLine(std::ifstream &input)
{
    // read file line by line, printing each one
    while (!input.eof())
    {
        char line[MAX_CHARS_PER_LINE];
        input.getline(line, MAX_CHARS_PER_LINE, '\n');
        cout << line << endl;
    }

    // close the file
    input.close();
}

void printUsage()
{
    cout << "Usage: ./myWC <type> <filename>" << endl;
    cout << "<type>:" << endl;
    cout << "-c for number of characters" << endl;
    cout << "-w for number of words" << endl;
    cout << "-l for number of lines\n"
         << endl;

    cout << "<filename>:" << endl;
    cout << "absolute path or path relative to the dir this program runs from." << endl;
    cout << "e.g. /home/fraser/apt/repo2/lab05/snowyRiver.txt" << endl;
    cout << "e.g. myCountry.txt" << endl;
}