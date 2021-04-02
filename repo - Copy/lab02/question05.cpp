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
   // TODO: Constructor
   Card(int colour, int number)
   {
      this->colour = colour;
      this->number = number;
      if (colour == RED)
         rule = "Highest card wins";
      else if (colour == ORANGE)
         rule = "Most of one number wins";
      else if (colour == YELLOW)
         rule = "Most of one colour wins";
      else if (colour == GREEN)
         rule = "Most even cards wins";
      else if (colour == BLUE)
         rule = "Most different colours wins";
      else if (colour == INDIGO)
         rule = "Most cards in a row wins";
      else if (colour == VIOLET)
         rule = "Most cards below 4 wins";
      else {
         rule = "***Error: no rule. Check Card constructor.***";
      }
   }

   // 4 methods to implement
   int getNumber()
   {
      return number;
   }
   int getColourAsInt()
   {
      return colour;
   }
   std::string getColourAsString()
   {
      if (colour == RED)
         return "Red";
      else if (colour == ORANGE)
         return "Orange";
      else if (colour == YELLOW)
         return "Yellow";
      else if (colour == GREEN)
         return "Green";
      else if (colour == BLUE)
         return "Blue";
      else if (colour == INDIGO)
         return "Indigo";
      else if (colour == VIOLET)
         return "Violet";

      return "***Error: No colour found. Check getColourAsString.***";
   }

   std::string getRule()
   {
      return rule;
   }

private:
   int number;
   int colour;
   std::string rule;
   // TODO: Fields to store information
};

int main(void)
{
   Card card(8, 8);
   std::cout << card.getColourAsString() << "(" << card.getColourAsInt()<< ") " << card.getNumber() << ". Rule: " << card.getRule() << std::endl;
   // TODO: Implement making a card.
   //

   return EXIT_SUCCESS;
}