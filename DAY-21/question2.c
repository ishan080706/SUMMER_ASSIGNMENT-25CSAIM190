#include <stdio.h>

void reverseString(char str[]) {
    int i, j;
    char temp;
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    reverseString(str);
    printf("Reversed string: %s", str);

    return 0;
}
