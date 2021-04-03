#ifndef RULE_H
#define RULE_H

#include "Card.h"

class Rule{
public:
    //Contructor & destructor
    Rule();
    Rule(Rule& other);

    ~Rule();

    //getter
    Colour getRule();

    //setter
    void setRule(Card* newRule);

private:
    Card* rule;
};


#endif //RULE_H