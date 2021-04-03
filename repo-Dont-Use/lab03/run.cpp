#include <iostream>
#include "Card.h"

using std::cout;
using std::endl;

#define HAND_MAX 5

int main(void)
{

    srand(time(NULL)); //seeds rand()

    Card *hand[HAND_MAX];
    for (int i = 0; i < HAND_MAX; i++)
    {
        hand[i] = new Card(rand() % 7, rand() % 7 + 1);
        cout << "You recieved: " << hand[i]->toString() << endl;
    }
    // cout << card->getColourAsString() << ": " << card->getRule() << endl; 
}