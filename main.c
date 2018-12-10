#include <stdio.h>
#include <stdlib.h>
#include "Game1.h"



int main()
{
    //displays the text
    printf("Can you guess the word?\n\n\n");

     getSecretWord();
    showHint();

 while (isGameOver() != 1)
    {

        printf("Guess %d of %d \n", currentGuessCount, maxGuesses);

       //The person can submit their guess
        printf("Enter guess: ");
        scanf("%s", &Guess);

        showGuess();
    }

 if (isGameWon() == 1)
        printf(" Your Good.You've guessed the secret word!\n\n"); //if they guess the right word
    else
        printf("Better luck next time!\n\n"); // if they cannot guess the word

    return 0;
}






















