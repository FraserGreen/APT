#include "Example.h"
#include <iostream>

Example::Example(double value) {
   this->ptrValue = new double(value);
}

Example::~Example(){
   delete ptrValue;
}

void Example::setValue(double value) {
   *ptrValue = value;
}

double Example::getValue() {
   return *ptrValue;
}