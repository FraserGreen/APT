#include "Card.h"
#include <iostream>
#include <string>

#define RED 0
#define ORANGE 1
#define YELLOW 2
#define GREEN 3
#define BLUE 4
#define INDIGO 5
#define VIOLET 6

Card::Card(int colour, int number)
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
    else
        rule = "***Error: no rule. Check Card constructor.***";
}

int Card::getNumber()
{
    return number;
}

int Card::getColourAsInt()
{
    return colour;
}

std::string Card::getColourAsString()
{
    std::string colourAsString = "***Error: No colour found. Check getColourAsString.***";
    if (colour == RED)
        colourAsString = "Red";
    else if (colour == ORANGE)
        colourAsString = "Orange";
    else if (colour == YELLOW)
        colourAsString = "Yellow";
    else if (colour == GREEN)
        colourAsString = "Green";
    else if (colour == BLUE)
        colourAsString = "Blue";
    else if (colour == INDIGO)
        colourAsString = "Indigo";
    else if (colour == VIOLET)
        colourAsString = "Violet";

    return colourAsString;
}

std::string Card::getRule()
{
    return rule;
}

std::string Card::toString(){
    return getColourAsString().append(" ").append(std::to_string(getNumber()));
}