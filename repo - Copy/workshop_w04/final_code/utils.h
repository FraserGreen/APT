#ifndef UTILS_H
#define UTILS_H

#include "Card.h"

//void printCard(int colour, int number);
void printCards(Card** cards, int numPrint);
void printColourAsString(Colour colour);
void printRule(Colour colour);
void printCard(Card* card);

#endif //UTILS_H