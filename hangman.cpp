#include <iostream>
#include <string>
#include <vector>
using namespace std;

string chooseSecretWord();
void renderGuessing(string guessWord, int numBadGuess=0);
char readGuess();
bool checkGuess(string secretWord, string guessWord, char guessChar);
void updateGuessWord(string secretWord, string &guessWord, char guessChar);
void renderEndGame(int numBadGuess=7);

int main()
{
    //initalize
    string secretWord, guessWord;
    secretWord = chooseSecretWord();
    guessWord = secretWord;
    fill(guessWord.begin(),guessWord.end(),'-');
    int numBadGuess=0;

    //game loop
    do
    {
        renderGuessing(guessWord, numBadGuess);
        char guessChar = readGuess();
        if(checkGuess(secretWord, guessWord, guessChar))
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
    while(numBadGuess<7 && secretWord!=guessWord);

    //result
    renderEndGame(numBadGuess);
    return 0;
}

string chooseSecretWord()
{
    return "random";
}

void renderGuessing(string guessWord, int numBadGuess)
{
    cout << "Num wrong guess: " << numBadGuess << endl;
    cout << guessWord << endl;
}

char readGuess()
{
    cout << "Your guess: ";
    char guessChar;
    cin >> guessChar;
    return guessChar;
}

bool checkGuess(string secretWord, string guessWord, char guessChar)
{
    for(int i=0; i<guessWord.size(); ++i)
    {
        if(guessChar==guessWord[i])
        {
            cout << "You've guessed this word before!" << endl;
            readGuess();
        }
    }
    for(int i=0; i<secretWord.size(); ++i)
    {
        if(guessChar==secretWord[i])
        {
            return true;
        }
    }
    return false;
}

void updateGuessWord(string secretWord, string &guessWord, char guessChar)
{
    for(int i=0; i<guessWord.size(); ++i)
    {
        if(guessChar==secretWord[i])
        {
            guessWord[i]=guessChar;
        }
    }
}

void renderEndGame(int numBadGuess)
{
    if(numBadGuess<7)
    {
        cout << "You win!";
    }
    else
    {
        cout << "You lose!";
    }
}
