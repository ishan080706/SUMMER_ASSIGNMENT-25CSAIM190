#include <stdio.h>
#include <string.h>
#include <ctype.h>

void removeSpaces(char *source, char *destination) {
    int j = 0;
    
    for (int i = 0; source[i] != '\0'; i++) {
        if (source[i] != ' ' && source[i] != '\n' && source[i] != '\t') {
            destination[j++] = source[i];
        }
    }
    destination[j] = '\0';
}

int main() {
    char originalString[1000];
    char stringWithoutSpaces[1000];
    
    printf("Enter a string: ");
    fgets(originalString, sizeof(originalString), stdin);
    
    removeSpaces(originalString, stringWithoutSpaces);
    
    printf("Original string: %s", originalString);
    printf("String without spaces: %s\n", stringWithoutSpaces);
    
    return 0;
}
