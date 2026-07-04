#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char str[1000];
    printf("Enter a string: ");
    if (fgets(str, sizeof(str), stdin) == NULL) {
        return 1;
    }

    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    size_t left = 0;
    size_t right = len == 0 ? 0 : len - 1;
    int is_palindrome = 1;

    while (left < right) {
        if (str[left] != str[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("%s is a palindrome.\n", str);
    } else {
        printf("%s is not a palindrome.\n", str);
    }

    return 0;
}
