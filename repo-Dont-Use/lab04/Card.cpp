#include "Card.h"
#include <iostream>
#include <string>

Card::Card()
{
    Card(RED, 7);
    std::cout << "Default card created." << std::endl;
}

Card::Card(int colour, int number)
{
    this->number = number;
    if (colour == RED)
    {
        rule = "Highest card wins";
        this->colour = RED;
    }
    else if (colour == ORANGE)
    {
        rule = "Most of one number wins";
        this->colour = ORANGE;
    }
    else if (colour == YELLOW)
    {
        rule = "Most of one colour wins";
        this->colour = YELLOW;
    }
    else if (colour == GREEN)
    {
        rule = "Most even cards wins";
        this->colour = GREEN;
    }
    else if (colour == BLUE)
    {
        rule = "Most different colours wins";
        this->colour = BLUE;
    }
    else if (colour == INDIGO)
    {
        rule = "Most cards in a row wins";
        this->colour = INDIGO;
    }
    else if (colour == VIOLET)
    {
        rule = "Most cards below 4 wins";
        this->colour = VIOLET;
    }
    else
        rule = "***Error: no rule. Check Card constructor.***";
}

int Card::getNumber()
{
    return number;
}

Colour Card::getColour()
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

std::string Card::toString()
{
    return getColourAsString().append(" ").append(std::to_string(getNumber()));
}