#include <stdio.h>
#include <string.h>

int main()
{
    char str[200], word[100], longest[100];
    int i, j, len, maxLen = 0;

    printf("Enter a sentence: ");
    gets(str);

    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != ' ')
        {
            word[j++] = str[i];
        }
        else
        {
            word[j] = '\0';
            len = strlen(word);
            if (len > maxLen)
            {
                maxLen = len;
                strcpy(longest, word);
            }
            j = 0;
        }
        i++;
    }

    word[j] = '\0';
    len = strlen(word);
    if (len > maxLen)
    {
        strcpy(longest, word);
    }

    printf("Longest word: %s\n", longest);
    return 0;
}
