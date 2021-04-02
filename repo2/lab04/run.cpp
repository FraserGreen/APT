#include <iostream>
#include "Card.h"
#include "Hand.h"

using std::cout;
using std::endl;

int main(void)
{

    srand(time(NULL)); //seeds rand()

    Hand *hand = new Hand(); //creates empty hand

    //fills hand with random cards (duplicates allowed), and prints out each card.
    for (int i = 0; i < MAX_CARDS; i++)
    {
        hand->addCard(new Card(rand() % 7, rand() % 7 + 1));
        cout << "You recieved: " << hand->getCard(i)->toString() << endl;
    }

    // cout << hand->getNumCards() << endl;

    //create a copy of hand
    Hand *copyHand = new Hand(*hand);
    cout << "hand's first card: " << hand->getCard(0)->toString() << ", with address:     "<< hand->getCard(0) << endl;
    cout << "copyHand's first card: " << copyHand->getCard(0)->toString() << ", with address: "<< copyHand->getCard(0) << endl;
    delete hand;
}
