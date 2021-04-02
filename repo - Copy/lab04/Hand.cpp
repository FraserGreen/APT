#include "Hand.h"
#include <iostream>

using std::cout;
using std::endl;

Hand::Hand()
{
    cout << "Hand object created." << endl;
    numStored = 0;
}

Hand::Hand(Hand &other)
{
    cout << "copy constructor called" << endl;
    numStored = 0;

    //DEEP::::::::::::::::::::
    for (int i = 0; i < other.numStored; i++)
    {
        addCard(new Card(other.getCard(i)->getColour(), other.getCard(i)->getNumber()));
        cout << cards[i]->toString() << endl;
    }
}

Hand::~Hand()
{
    for (int i = 0; i < numStored; i++)
    {
        delete cards[i];
    }
}

void Hand::addCard(Card *card)
{
    cards[numStored] = card;
    numStored++;
}

int Hand::getNumCards()
{
    return numStored;
}

Card *Hand::getCard(int index)
{
    return cards[index];
}
