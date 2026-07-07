#include <stdio.h>

int main()
{
    int score = 0;
    char answer;

    printf("Welcome to the Quiz Application!\n");

    printf("1. What is the capital of France?\n");
    printf("a) London\n");
    printf("b) Paris\n");
    printf("c) Rome\n");
    printf("Enter your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B')
    {
        score++;
    }

    printf("2. What is 2 + 2?\n");
    printf("a) 3\n");
    printf("b) 4\n");
    printf("c) 5\n");
    printf("Enter your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B')
    {
        score++;
    }

    printf("3. Which planet is known as the Red Planet?\n");
    printf("a) Venus\n");
    printf("b) Mars\n");
    printf("c) Jupiter\n");
    printf("Enter your answer: ");
    scanf(" %c", &answer);
    if (answer == 'b' || answer == 'B')
    {
        score++;
    }

    printf("Your score: %d/3\n", score);
    return 0;
}
