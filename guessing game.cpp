#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int choice, number, max, attempts, min = 1, guess, chances, score;

    srand(time(0));

    do {

        printf("--Welcome to the Guessing number--\n");
        printf(" 1 for Easy (1 to 50, 7 chances)\n");
        printf(" 2 for Medium (1 to 100, 5 chances)\n");
        printf(" 3 for Hard (1 to 200, 3 chances)\n");
        printf(" 4 for Exit!!\n");
        printf(" Choose the Difficulty level: \n");

        scanf("%d", &choice);

        switch (choice) {

            case 1:
                max = 50;
                chances = 7;
                break;

            case 2:
                max = 100;
                chances = 5;
                break;

            case 3:
                max = 200;
                chances = 3;
                break;

            case 4:
                printf("Exiting the Game! see you again!\n");
                return 0;

            default:
                printf("Invalid choice!!\n");
                continue;
        }

        number = (rand() % max) + 1;
        attempts = 0;
        score = 100;

        printf("\nI have chosen %d to %d numbers \n", min, max);
        printf("You have %d chances: \n", chances);

        while (attempts < chances) {

            printf("Please Enter your Guessing number (Or -1 for Quit).\n");
            scanf("%d", &guess);

            if (guess == -1) {

                printf("You are quitting the game! Your number was %d.\n", number);
                break;
            }

            attempts++;

            if (guess == number) {

                printf("Correct! Guessing number %d\n", number);
                printf("Your score: %d\n", (score - attempts * 10));
            }

            else if (guess < number) {

                printf("Too low! Try again!\n");
            }

            else {

                printf("Too high! Try again!\n");
            }

            if (attempts == chances) {

                printf("Game Over! Your number was %d\n", number);
            }
        }

    } while (choice != 4);

    return 0;
}
