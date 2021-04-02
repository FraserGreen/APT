#include <iostream>

using std::cout;
using std::endl;

void incrementPtr(double* dub);

void decrementRef(double& dub);

int main(void ){
int integer = 6;
cout << integer << endl;

int* integerPtr = &integer;
cout << integerPtr <<endl;

integer = 7 ;
cout << integer << endl;

*integerPtr = 8;
cout << integer << endl;

double dub = 20.5;
cout << dub << endl;

incrementPtr(&dub);
cout << dub << endl;

decrementRef(dub);
cout << dub << endl;


}

void incrementPtr(double* dub){
    *dub +=1;
}

void decrementRef(double &dub){
    dub--;
}