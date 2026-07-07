#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int count[256] = {0};
    int i, maxCount = 0;
    char maxChar;

    printf("Enter a string: ");
    gets(str);

    for (i = 0; str[i] != '\0'; i++) {
        count[(unsigned char)str[i]]++;
    }

    for (i = 0; str[i] != '\0'; i++) {
        if (count[(unsigned char)str[i]] > maxCount) {
            maxCount = count[(unsigned char)str[i]];
            maxChar = str[i];
        }
    }

    printf("Maximum occurring character: %c\n", maxChar);
    return 0;
}
