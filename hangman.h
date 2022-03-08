using std::string;

#ifndef _HANGMAN_H
#define _HANGMAN_H

const string FIGURE[] = {
    " ------------- \n"
    " |             \n"
    " |             \n"
    " |             \n"
    " |             \n"
    " |             \n"
    " -----         \n",

    " ------------- \n"
    " |           | \n"
    " |             \n"
    " |             \n"
    " |             \n"
    " |             \n"
    " -----         \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |             \n"
    " |             \n"
    " |             \n"
    " -----         \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |           | \n"
    " |             \n"
    " |             \n"
    " -----         \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /| \n"
    " |             \n"
    " |             \n"
    " -----         \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |                 \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |          /      \n"
    " |                 \n"
    " -----             \n",

    " -------------     \n"
    " |           |     \n"
    " |           O     \n"
    " |          /|\\   \n"
    " |          / \\   \n"
    " |                 \n"
    " -----             \n"
};
const int MAX_BAD_GUESS = 7;

void clearScreen();

string chooseSecretWord();
void renderGuessing(const string &guessWord, const int numBadGuess, const string &charGuessed);
char readGuess();
bool checkGuess(const string &secretWord, const string &guessWord, char &guessChar, string &charGuessed);
void updateGuessWord(const string &secretWord, string &guessWord, char guessChar);
void renderEndGame(const string &secretWord, const int numBadGuess=MAX_BAD_GUESS);
bool continuePlaying();
void playHangman();

#endif // _HANGMAN_H
