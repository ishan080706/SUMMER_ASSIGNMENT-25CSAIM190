#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char line[512];
    int vowels = 0;
    int consonants = 0;

    printf("Enter a line of text:\n");
    if (fgets(line, sizeof(line), stdin) == NULL)
        return 0;

    for (int i = 0; line[i] != '\0'; i++) {
        char ch = line[i];
        if (!isalpha((unsigned char)ch))
            continue;

        ch = tolower((unsigned char)ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
        else
            consonants++;
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
    return 0;
}
