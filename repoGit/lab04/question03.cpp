#include <iostream>
#include <string>

using std::cout;
using std::endl;

int stringLength(char* string);
void copyString(char* src, char* dest);

int main(void){
    char string[] = "hello";
    cout << string << endl;
    cout << "Length of string: " << stringLength(string) << endl;

    char copiedString[INT16_MAX] = "";
    copyString(string, copiedString);
    cout << "Copied string: " << copiedString << endl;
}


// void copyString(char* src, char* dest){
//     //assuming dest is large enough to store src every time
//     int i=0;
//     while (src[i] != '\0'){
//         dest[i] = src[i];
//         ++i;
//     }
// }

void copyString(char* src, char* dest){
    //assuming dest is large enough to store src every time
    int i=0;
    while (src != nullptr && dest!= nullptr && src[i] != '\0'){
        dest[i] = src[i];
        ++i;
    }
}


int stringLength(char* string){
    int i=0;
    while (string[i] != '\0'){
        ++i;
    }
    return i;
}