#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(void) {
    int target;
    int attempts = 0;
    char input[128];

    srand((unsigned int)time(NULL));
    target = rand() % 100 + 1;

    printf("=== Number Guessing Game ===\n");
    printf("Guess a number between 1 and 100.\n");

    while (1) {
        char *end;
        long guess;
        size_t length;

        printf("\nEnter your guess: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nInput ended. Thanks for playing!\n");
            break;
        }

        length = strlen(input);

        if (strchr(input, '\n') == NULL &&
            length == sizeof(input) - 1) {
            int ch;

            while ((ch = getchar()) != '\n' && ch != EOF) {
                /* Clear the remaining input. */
            }

            printf("Input is too long. Please try again.\n");
            continue;
        }

        if (length > 0 && input[length - 1] == '\n') {
            input[length - 1] = '\0';
        }

        errno = 0;
        guess = strtol(input, &end, 10);

        if (end == input) {
            printf("Invalid input! Please enter a whole number.\n");
            continue;
        }

        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (*end != '\0' || errno == ERANGE) {
            printf("Invalid input! Please enter a whole number.\n");
            continue;
        }

        if (guess < 1 || guess > 100) {
            printf("Out of range! Enter a number from 1 to 100.\n");
            continue;
        }

        attempts++;

        if (guess < target) {
            printf("Too low! Try a larger number.\n");
        } else if (guess > target) {
            printf("Too high! Try a smaller number.\n");
        } else {
            printf(
                "\nCongratulations! You guessed the number "
                "in %d valid attempt(s).\n",
                attempts
            );
            break;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}
