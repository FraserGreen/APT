#include <iostream>
#include <string>

#define RED 0
#define ORANGE 1
#define YELLOW 2
#define GREEN 3
#define BLUE 4
#define INDIGO 5
#define VIOLET 6

using std::cin;
using std::cout;
using std::endl;

int main(void)
{

    int NUM_CARDS = 5;
    int number = 6;
    int colour = VIOLET;

    cout << "Red 7 card" << endl;
    cout << "\tnumber: " << number << endl;
    cout << "\tcolour: " << colour << endl;

    for (int i = 0; i<NUM_CARDS; i++){
        cin >> number;
        cin >> colour;

        cout << "Red 7 card" << endl;
        cout << "\tnumber: " << number << endl;
        cout << "\tcolour: " << colour << endl;
    }


    return EXIT_SUCCESS;
}

// g++ -Wall -Werror -std=c++14 -O -o red7 red7.cpp