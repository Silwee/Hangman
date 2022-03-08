#include <iostream>
#include <string>
#include <random>
#include "hangman.h"
#include "wordlist.h"
using namespace std;

void clearScreen()
{
    cout << string(50,'\n');
}

string chooseSecretWord()
{
    const int NUM_WORD = sizeof(WORD_LIST)/sizeof(string);
    int random_index = rand()%NUM_WORD;
    return WORD_LIST[random_index];
}

void renderGuessing(const string &guessWord, const int numBadGuess, const string &charGuessed)
{
    clearScreen();
    cout << FIGURE[numBadGuess] << endl;
    cout << "What you've guessed: " << charGuessed << endl;
    cout << "Num wrong guess: " << numBadGuess << "/" << MAX_BAD_GUESS << endl;
    cout << guessWord << endl;
}

char readGuess()
{
    cout << "Your guess: ";
    char guessChar;
    cin >> guessChar;
    return guessChar;
}

bool checkGuess(const string &secretWord, const string &guessWord, char &guessChar, string &charGuessed)
{
    if(!isalpha(guessChar))
    {
        cout << "Please enter a letter in English alphabet." << endl;
        return true;
    }
    if(isupper(guessChar))
    {
        guessChar-='A'-'a';
    }
    for(int i=0; i<charGuessed.size(); ++i)
    {
        if(guessChar==charGuessed[i])
        {
            cout << "You've guessed this word before!" << endl;
            cout << "Enter any character to continue... ";
            char temp; cin >> temp;
            return true;
        }
    }
    charGuessed.push_back(guessChar);
    for(int i=0; i<secretWord.size(); ++i)
    {
        if(guessChar==secretWord[i])
        {
            return true;
        }
    }
    return false;
}

void updateGuessWord(string const &secretWord, string &guessWord, char guessChar)
{
    for(int i=0; i<guessWord.size(); ++i)
    {
        if(guessChar==secretWord[i])
        {
            guessWord[i]=guessChar;
        }
    }
}

void renderEndGame(const string &secretWord, const int numBadGuess)
{
    if(numBadGuess<MAX_BAD_GUESS)
    {
        cout << "You win!" << endl;
    }
    else
    {
        cout << FIGURE[MAX_BAD_GUESS];
        cout << "You lose!" << endl;
    }
    cout << "The correct word is " << secretWord << endl;
}

bool continuePlaying()
{
    char isContinued;
	cout << "Do you want to continue playing?" << endl;
	cout << "Y to continue, N to exit: ";
	cin >> isContinued;
    if(isContinued=='y' || isContinued=='Y')
    {
		return true;
	}
	return false;
}

void playHangman()
{
    //initalize
    string secretWord, guessWord, charGuessed;
    secretWord = chooseSecretWord();
    guessWord = secretWord;
    fill(guessWord.begin(),guessWord.end(),'-');
    int numBadGuess=0;

    //game loop
    do
    {
        renderGuessing(guessWord, numBadGuess, charGuessed);
        char guessChar = readGuess();
        if(checkGuess(secretWord, guessWord, guessChar, charGuessed))
        {
            //right guess
            updateGuessWord(secretWord, guessWord, guessChar);
        }
        else
        {
            //wrong guess
            numBadGuess++;
        }
    }
    while(numBadGuess<MAX_BAD_GUESS && secretWord!=guessWord);

    //result
    renderEndGame(secretWord, numBadGuess);
}
