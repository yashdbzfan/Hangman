# Hangman Game in C

## About
This C program implements a classic Hangman game where the player guesses letters to reveal a hidden word. The game features a dynamic word selection from predefined lists based on difficulty, a visual hangman that progresses with incorrect guesses, tracking of guessed letters, and clear win/loss outcomes. The program is designed to be interactive and user-friendly, with robust input validation and replay functionality.

## How It Starts and Works
- **Game Startup**:
  - The program begins by prompting the player to select a difficulty level: Easy (1, for 3-5 letter words), Medium (2, for 6-8 letter words), or Hard (3, for 9+ letter words). If an invalid choice is entered, it defaults to Medium.
  - A word is randomly selected from the corresponding difficulty-based word list (e.g., "cat" for Easy, "computer" for Medium, "programming" for Hard).
  - The game initializes with 6 tries, an empty list of guessed letters, and the word displayed as underscores (e.g., `_ _ _` for "cat").
- **Gameplay Mechanics**:
  - The player is shown the current state of the word (with revealed letters and underscores for unguessed ones), the hangman ASCII art, remaining tries, and previously guessed letters.
  - The player inputs a single letter guess. The program validates the input to ensure it’s an alphabetic letter and not previously guessed.
  - If the letter is in the word, it’s revealed in all matching positions, and the correct guess count increases. If not, the hangman progresses (e.g., adding the head, arms, etc.), and a try is consumed.
  - The game continues until the player either guesses the entire word (win) or uses all 6 tries (loss).
  - After the game ends, the final hangman state and word are displayed, along with a win or loss message.
  - The player is prompted to play again (y/n). If they choose 'y', a new game starts with a new difficulty selection and random word.

## Features
- **Interactive Gameplay**: Players guess one letter at a time to uncover the hidden word, with feedback on valid and invalid guesses.
- **Difficulty Selection**: Choose from Easy (3-5 letters), Medium (6-8 letters), or Hard (9+ letters) word pools for varied challenges.
- **Random Word Selection**: Words are randomly selected from curated lists to ensure replayability.
- **Clear Screen Functionality**: The screen clears after each guess to keep the interface clean (supports Windows and Unix-like systems).
- **Hangman Display**: Simple ASCII art shows the hangman’s progression based on incorrect guesses (up to 6 tries).
- **Guessed Letters Tracking**: Displays all previously guessed letters to help players strategize.
- **Win/Lose Results**: Informs the player of the game outcome, revealing the word and offering a replay option.
- **Input Validation**: Ensures only valid alphabetic letters are accepted, preventing duplicate guesses.
- **Remaining Tries Indicator**: Shows how many tries remain before the game ends.

## Tech Stack
- **C**: Core programming language for logic and execution.
- **Standard Input/Output**: Uses `stdio.h` for user interaction via `printf` and `scanf`.
- **String Handling**: Leverages `string.h` for word manipulation and `ctype.h` for case conversion and validation.
- **Control Structures**: Implements loops and conditionals for game flow and logic.
- **Time Library**: Uses `time.h` for random word selection with `srand` and `rand`.