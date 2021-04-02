
#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>


   enum Colour{RED, ORANGE, YELLOW, GREEN, BLUE, INDIGO, VIOLET};

class Card {
public:
   Card();
   Card(int colour, int number);
   Card(Card& other);
   // ~Card();

   Colour getColour();
   int getNumber();
   std::string getColourAsString();
   std::string getRule();
   std::string toString();

private:
   Colour colour;
   int number;
   std::string rule;
};


#endif // CARD_H
