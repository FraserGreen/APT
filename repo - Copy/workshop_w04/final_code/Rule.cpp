#include "Rule.h"


//Contructor & destructor
Rule::Rule(){
    rule = new Card(RED, 7);
}


// //Shallo copy
// Rule::Rule(Rule& other):
//             rule(other.rule)
// {

// }

//Deep copy
Rule::Rule(Rule& other)
{
    this->rule = new Card(*other.rule);
}

Rule::~Rule(){
    delete rule;
}

//getter
Colour Rule::getRule(){
    return rule->getColour();
}

//setter
void Rule::setRule(Card* newRule){
    delete rule;
    rule = newRule;
}