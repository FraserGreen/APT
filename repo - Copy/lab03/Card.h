#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <string>

#define RED 0
#define ORANGE 1
#define YELLOW 2
#define GREEN 3
#define BLUE 4
#define INDIGO 5
#define VIOLET 6

class Card
{
public:
   Card(int colour, int number);
   
   int getNumber();
   int getColourAsInt();
   std::string getColourAsString();
   std::string getRule();
   std::string toString();

private:
   int number;
   int colour;
   std::string rule;
};

#endif