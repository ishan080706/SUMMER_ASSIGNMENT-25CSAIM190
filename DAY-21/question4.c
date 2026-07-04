#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char line[512];

    printf("Enter a line of text:\n");
    if (fgets(line, sizeof(line), stdin) == NULL)
        return 0;

    for (int i = 0; line[i] != '\0'; i++) {
        line[i] = toupper((unsigned char)line[i]);
    }

    printf("Uppercase: %s", line);
    return 0;
}

