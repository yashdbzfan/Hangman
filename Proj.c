#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_TRIES 6
#define WORD_LENGTH 100
#define ALPHABET_SIZE 26

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
        printf(" _______\n |/    |\n |     O\n |     |\n |\n |\n |\n_|____\n");
        break;
    case 3:
        printf(" _______\n |/    |\n |     O\n |    /|\n |\n |\n |\n_|____\n");
        break;
    case 4:
        printf(" _______\n |/    |\n |     O\n |    /|\\\n |\n |\n |\n_|____\n");
        break;
    case 5:
        printf(" _______\n |/    |\n |     O\n |    /|\\\n |    /\n |\n |\n_|____\n");
        break;
    case 6:
        printf(" _______\n |/    |\n |     O\n |    /|\\\n |    / \\\n |\n |\n_|____\n");
        break;
    }
}

void printWord(const char *word, int length, const int *guessed)
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

void initializeGame(char *word, int *guessed, int *wordLength, int difficulty)
{
    const char *easyWords[] = {"cat", "dog", "fish", "bird", "tree", "sun", "moon", "star", "lake", "hill"};
    const char *mediumWords[] = {"apple", "banana", "computer", "puzzle", "rocket", "guitar", "painting", "window", "forest", "river"};
    const char *hardWords[] = {"programming", "algorithm", "developer", "recursion", "inheritance", "polymorphism", "encapsulation", "abstraction", "framework", "compiler"};

    const char **wordList;
    int numWords;

    switch (difficulty)
    {
    case 1:
        wordList = easyWords;
        numWords = sizeof(easyWords) / sizeof(easyWords[0]);
        break;
    case 2:
        wordList = mediumWords;
        numWords = sizeof(mediumWords) / sizeof(mediumWords[0]);
        break;
    case 3:
        wordList = hardWords;
        numWords = sizeof(hardWords) / sizeof(hardWords[0]);
        break;
    default:
        wordList = mediumWords;
        numWords = sizeof(mediumWords) / sizeof(mediumWords[0]);
    }

    strcpy(word, wordList[rand() % numWords]);
    *wordLength = strlen(word);
    for (int i = 0; i < *wordLength; i++)
    {
        word[i] = tolower(word[i]);
        guessed[i] = 0;
    }
}

int isValidGuess(char guess, const int *guessedLetters)
{
    if (!isalpha(guess))
    {
        printf("Please enter a valid letter!\n");
        return 0;
    }
    if (guessedLetters[tolower(guess) - 'a'])
    {
        printf("You already guessed '%c'!\n", guess);
        return 0;
    }
    return 1;
}

int getDifficulty()
{
    int difficulty;
    printf("Choose difficulty (1: Easy, 2: Medium, 3: Hard): ");
    scanf("%d", &difficulty);
    while (getchar() != '\n')
        ;
    if (difficulty < 1 || difficulty > 3)
    {
        printf("Invalid choice, defaulting to Medium.\n");
        difficulty = 2;
    }
    return difficulty;
}

int main()
{
    char word[WORD_LENGTH];
    int guessed[WORD_LENGTH] = {0};
    int guessedLetters[ALPHABET_SIZE] = {0};
    int tries = 0;
    int wordLength;
    int correctGuesses = 0;
    char guess;
    char playAgain;

    srand(time(NULL));

    do
    {
        tries = 0;
        correctGuesses = 0;
        memset(guessed, 0, sizeof(guessed));
        memset(guessedLetters, 0, sizeof(guessedLetters));
        int difficulty = getDifficulty();
        initializeGame(word, guessed, &wordLength, difficulty);

        while (tries < MAX_TRIES && correctGuesses < wordLength)
        {
            clearScreen();
            displayHangman(tries);
            printf("Tries remaining: %d\n", MAX_TRIES - tries);
            printf("\nGuessed letters: ");
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (guessedLetters[i])
                {
                    printf("%c ", 'a' + i);
                }
            }
            printf("\n");
            printWord(word, wordLength, guessed);
            printf("\nEnter a letter: ");
            scanf(" %c", &guess);
            while (getchar() != '\n')
                ;

            guess = tolower(guess);
            if (!isValidGuess(guess, guessedLetters))
            {
                printf("Press Enter to continue...");
                getchar();
                continue;
            }

            int letterFound = 0;
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
                guessedLetters[guess - 'a'] = 1;
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

        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
        while (getchar() != '\n')
            ;
    } while (tolower(playAgain) == 'y');

    return 0;
}
