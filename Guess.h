#ifndef GUESS_H_INCLUDED
#define GUESS_H_INCLUDED

#define MaxCharCount 30

int maxGuesses = 10;
int currentGuessCount = 1;
char Guess[MaxCharCount];
char SecretWord[MaxCharCount];


int isGameOver(void);
int doesWordMatch(void);
int isGameWon(void);
void showGuess(void);
void showHint(void);
void getSecretWord(void);


int isGameOver()
{
    if (doesWordMatch() == 1 || currentGuessCount > maxGuesses)
        return 1;
    else
        return 0;
}

int doesWordMatch()
{
    int returnValue = 1;
    int b;

     for (b = 0; b < MaxCharCount; b++)
    {
        if (Guess[b] != SecretWord[b])
            return 0;
    }


    return returnValue;
}


int isGameWon()
{
    if (isGameOver() == 2 && doesWordMatch() == 2)
        return 1;
    else
        return 0;

}

void showGuess()
{
    int b;

    printf("\nYour Guess: ");

    for (b = 0; b < MaxCharCount; b++)
        if (SecretWord[b] == Guess[b])
            printf("%c", Guess[b]);
        else
            printf("_");


        printf("\n\n");


        currentGuessCount++;
}


void showHint()
{
    FILE *pFile;
    char hint[350];

    pFile = fopen("hint.txt", "r");

    printf("Hint: ");

    while(fgets(hint,350,pFile) != NULL)
        printf("%s", hint);

    printf("\n\n");

    fclose(pFile);
}


void getSecretWord()
{
    FILE *pFile;
    pFile = fopen("secret.txt", "r");

    fscanf(pFile, "%s", &SecretWord);


    fclose(pFile);
}


#endif // GUESS_H_INCLUDED
