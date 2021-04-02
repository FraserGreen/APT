#include <iostream>
#include <string>

#include "Card.h"
#include "utils.h"
#include "Rule.h"

#define NUMBER_CARDS_TO_READ 5

bool readOneCard(Colour* colour, int* number);
void playTheGame(Card** cards, int NumCards);
void deepCopyCards(Card** source, Card** copy, int NumCards);


int main(void) {
   // TODO: Convert to use a Class
   Colour colour = RED;
   int number = 0;

   Card* cards[NUMBER_CARDS_TO_READ];
   for(int i=0; i<NUMBER_CARDS_TO_READ; ++i){
      cards[i] = nullptr;
   }

   // Read a set number of cards from the user or until EOF
   int numRead = 0;
   while(!std::cin.eof() && numRead < NUMBER_CARDS_TO_READ) {
      bool readSuccess = false;
      readSuccess = readOneCard(&colour, &number);

      if (!std::cin.eof() && readSuccess) {
         //Create a card and add it to array
         Card* card = new Card(colour, number);
         cards[numRead] = card;
  
         // Increment cards read
         ++numRead;
      }

   }

   // When we had array's before - print out all the cards
   // numRead is garanteed to be no longer than the length of the array
   printCards(cards, numRead);

   playTheGame(cards, numRead);

   Card* cardsCopy[NUMBER_CARDS_TO_READ];
   for(int i=0; i<NUMBER_CARDS_TO_READ; ++i){
      cardsCopy[i] = nullptr;
   }

   deepCopyCards(cards, cardsCopy, numRead);


   //Cleanup
   for(int i=0; i<NUMBER_CARDS_TO_READ; ++i){
      if(cards[i] != nullptr){
         delete cards[i];
      }
   }

   for(int i=0; i<NUMBER_CARDS_TO_READ; ++i){
      if(cardsCopy[i] != nullptr){
         delete cardsCopy[i];
      }
   }

   return EXIT_SUCCESS;
}


void deepCopyCards(Card** source, Card** copy, int NumCards){
   for(int i = 0; i<NumCards; ++i){
      copy[i] = new Card(*source[i]);
   }

}

void playTheGame(Card** cards, int NumCards){

   std::cout << "Plating the Game" << std::endl;

   Rule* rule = new Rule();

   for(int i = 0; i < NumCards; ++i){
      //transfer the ownership to rule
      // rule->setRule(cards[i]);
      // cards[i] = nullptr;

      // Create a copy
      // Transfer the ownership of the copy
      Card* copyCard = new Card(*cards[i]);
      rule->setRule(copyCard);
      copyCard = nullptr;

      std::cout << "Setting the rule as: ";
      printColourAsString(rule->getRule());
      std::cout << std::endl;

   }

   delete rule;
}

bool readOneCard(Colour* colour, int* number) {

   //read colour
   int readColour = 0;
   bool readSuccess = true;
   std::cin >> readColour;

   if(readColour == 0){
      *colour = RED;
   }else if (readColour == 1){
      *colour = ORANGE;
   }else if (readColour == 2){
      *colour = YELLOW;
   }else if (readColour == 3){
      *colour = GREEN;
   }else if (readColour == 4){
      *colour = BLUE;
   }else if (readColour == 5){
      *colour = INDIGO;
   }else if (readColour == 6){
      *colour = VIOLET;
   }else{
      readSuccess = false;
      std::cout << "Incorrect color try again!" << std::endl;
   }

   //read number
   std::cin >> *number;

   return readSuccess;
}


