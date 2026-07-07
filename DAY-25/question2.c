#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], result[100];
    int i, j, k = 0;
    int visited[256] = {0};

    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);

    for (i = 0; str1[i] != '\0'; i++) {
        for (j = 0; str2[j] != '\0'; j++) {
            if (str1[i] == str2[j] && !visited[(unsigned char)str1[i]]) {
                result[k++] = str1[i];
                visited[(unsigned char)str1[i]] = 1;
                break;
            }
        }
    }

    result[k] = '\0';
    printf("Common characters: %s\n", result);
    return 0;
}

