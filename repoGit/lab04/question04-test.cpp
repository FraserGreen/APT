#include <iostream>

int stringLength(char* string);
void copyString(char* src, char* dest);

int main(void) {

    std::cout << "Testing stringLength" << std::endl;
    char* nullStr = nullptr;
    char empty[] = "";
    char hello[] = "Hello World";
    std::cout << "Should be 0 but is: " << stringLength(nullStr) << std::endl;
    std::cout << "Should be 0 but is: " << stringLength(empty) << std::endl;
    std::cout << "Should be 11 but is: " << stringLength(hello) << std::endl;

    // Uncomment these when you have tested stringLength
    char from[] = "this should be copied";
    char to[INT16_MAX] = "";
    std::cout << "Before: from: " << from << ", to:  " << to << std::endl;
    copyString(from, to);
    std::cout << "After: from: " << from << ", to:  " << to << std::endl;

    return EXIT_SUCCESS;
}


int stringLength(char* string){
    
    int i=0;
    while (string != nullptr && string[i] != '\0'){
        ++i;
    }
    return i;
}

void copyString(char* src, char* dest){
    //assuming dest is large enough to store src every time
    int i=0;
    while (src != nullptr && dest!= nullptr && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
}

