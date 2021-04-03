#include <iostream>
#include <string>

using std::cout;
using std::endl;

int stringLength(char* string);

int main(void){
    char string[] = "hello";
    cout << string << endl;
    cout << "Length of string: " << stringLength(string) << endl;
}

int stringLength(char* string){
    int i=0;
    while (string[i] != '\0'){
        ++i;
    }
    return i;
}