#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int random_number;
    int guess;
    int attempts = 0;

    srand((unsigned int)time(NULL));
    random_number = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    printf("Guess a number between 1 and 100.\n");

    do {
        printf("\nEnter your guess: ");

        if (scanf("%d", &guess) != 1) {
            int ch;

            printf("Invalid input! Please enter an integer.\n");
            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear the invalid input. */
            }

            if (ch == EOF) {
                printf("\nInput ended. Thanks for playing!\n");
                return 0;
            }

            continue;
        }

        if (guess < 1 || guess > 100) {
            printf("Please enter a number between 1 and 100.\n");
            continue;
        }

        attempts++;

        if (guess < random_number) {
            printf("Too low! Try a larger number.\n");
        } else if (guess > random_number) {
            printf("Too high! Try a smaller number.\n");
        } else {
            printf("\nCongratulations! You guessed the number in %d attempt(s).\n",
                   attempts);
        }
    } while (guess != random_number);

    printf("Thanks for playing!\n");
    return 0;
}