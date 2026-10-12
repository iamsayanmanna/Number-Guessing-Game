#include <ctype.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int target, attempts = 0;
    char input[100];

    srand((unsigned int)time(NULL));
    target = rand() % 100 + 1;

    printf("Welcome to the Number Guessing Game!\n");

    while (1) {
        char *end;
        long value;

        printf("\nEnter a number between 1 and 100: ");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("\nInput ended. Goodbye!\n");
            return 0;
        }

        errno = 0;
        value = strtol(input, &end, 10);

        while (isspace((unsigned char)*end)) {
            end++;
        }

        if (end == input || *end != '\0' || errno == ERANGE) {
            printf("Invalid input! Please enter a whole number.\n");
            continue;
        }

        if (value < 1 || value > 100) {
            printf("Out of range! Enter a number from 1 to 100.\n");
            continue;
        }

        attempts++;

        if (value < target) {
            printf("Try a larger number.\n");
        } else if (value > target) {
            printf("Try a smaller number.\n");
        } else {
            printf("Congratulations! You guessed it in %d valid attempt(s).\n",
                   attempts);
            break;
        }
    }

    printf("Thanks for playing!\n");
    return 0;
}
