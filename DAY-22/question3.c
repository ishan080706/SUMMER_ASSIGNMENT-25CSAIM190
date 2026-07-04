#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char sentence[1000];
    int frequency[256] = {0};  // Array to store frequency of all ASCII characters
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Count frequency of each character
    for (int i = 0; sentence[i] != '\0'; i++) {
        frequency[(unsigned char)sentence[i]]++;
    }
    
    printf("\nCharacter Frequency:\n");
    printf("--------------------\n");
    
    // Display frequency of characters (excluding newline and spaces if desired)
    for (int i = 0; i < 256; i++) {
        if (frequency[i] > 0 && !isspace(i)) {
            printf("'%c' : %d\n", (char)i, frequency[i]);
        }
    }
    
    return 0;
}
