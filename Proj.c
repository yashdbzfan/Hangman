#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_TRIES 6
#define WORD_LENGTH 100
void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void displayHangman(int tries)
{
    switch (tries)
    {
    case 0:
        printf(" _______\n |/    |\n |\n |\n |\n |\n |\n_|____\n");
        break;
    case 1:
        printf(" _______\n |/    |\n |     O\n |\n |\n |\n |\n_|____\n");
        break;
    case 2:
        printf(" _______\n |/    |\n |     O\n |     |\n |    \n |\n |\n_|____\n");
        break;
    case 3:
        printf(" _______\n |/    |\n |     O\n |    /|\n |    \n |\n |\n_|____\n");
        break;
    case 4:
        printf(" _______\n |/    |\n |     O\n |    /|\\\n |    \n |\n |\n_|____\n");
        break;
    case 5:
        printf(" _______\n |/    |\n |     O\n |    /|\\\n |    /\n |\n |\n_|____\n");
        break;
    case 6:
        printf(" _______\n |/    |\n |     O\n |    /|\\\n |    / \\\n |\n |\n_|____\n");
        break;
    }
}
void printWord(char *word, int length, int *guessed)
{
    for (int i = 0; i < length; i++)
    {
        if (guessed[i])
        {
            printf("%c ", word[i]);
        }
        else
        {
            printf("_ ");
        }
    }
    printf("\n");
}
int main()
{
    char word[WORD_LENGTH];
    int guessed[WORD_LENGTH] = {0};
    char guessedLetters[26] = {0};
    int tries = 0;
    int wordLength;
    int correctGuesses = 0;
    char guess;
    int letterFound;
    printf("Input the word to be guessed: ");
    scanf("%s", word);
    wordLength = strlen(word);
    while (tries < MAX_TRIES && correctGuesses < wordLength)
    {
        clearScreen();
        displayHangman(tries);
        printf("\nGuessed letters: ");
        for (int i = 0; i < 26; i++)
        {
            if (guessedLetters[i])
            {
                printf("%c ", guessedLetters[i]);
            }
        }
        printf("\n");
        printWord(word, wordLength, guessed);
        printf("\nEnter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);
        letterFound = 0;
        for (int i = 0; i < wordLength; i++)
        {
            if (word[i] == guess && !guessed[i])
            {
                guessed[i] = 1;
                correctGuesses++;
                letterFound = 1;
            }
        }
        if (!letterFound)
        {
            guessedLetters[tries] = guess;
            tries++;
        }
    }
    clearScreen();
    displayHangman(tries);
    if (correctGuesses == wordLength)
    {
        printf("\nCongratulations! You guessed the word '%s'!\n", word);
    }
    else
    {
        printf("\nGame over! The word was '%s'.\n", word);
    }
    return 0;
}
