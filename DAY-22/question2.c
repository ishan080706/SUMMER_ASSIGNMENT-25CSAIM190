#include <stdio.h>
#include <string.h>
#include <ctype.h>

int countWords(char *sentence) {
    int wordCount = 0;
    int inWord = 0;
    
    for (int i = 0; sentence[i] != '\0'; i++) {
        if (isspace(sentence[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            wordCount++;
        }
    }
    
    return wordCount;
}

int main() {
    char sentence[1000];
    
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove newline character if present
    if (sentence[strlen(sentence) - 1] == '\n') {
        sentence[strlen(sentence) - 1] = '\0';
    }
    
    int words = countWords(sentence);
    
    printf("Number of words: %d\n", words);
    
    return 0;
}
