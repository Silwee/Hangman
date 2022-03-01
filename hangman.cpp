#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

//some define
const string WORD_LIST[] = {
     "angle", "ant", "apple", "arch", "arm", "army",
     "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell",
     "berry", "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
     "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
     "cake", "camera", "card", "cart", "carriage", "cat", "chain", "cheese", "chest",
     "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
     "cow", "cup", "curtain", "cushion",
     "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
     "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
     "foot", "fork", "fowl", "frame", "garden", "girl", "glove", "goat", "gun",
     "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
     "hospital", "house", "island", "jewel", "kettle", "key", "knee", "knife", "knot",
     "leaf", "leg", "library", "line", "lip", "lock",
     "map", "match", "monkey", "moon", "mouth", "muscle",
     "nail", "neck", "needle", "nerve", "net", "nose", "nut",
     "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
     "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
     "rail", "rat", "receipt", "ring", "rod", "roof", "root",
     "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
     "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
     "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
     "store", "street", "sun", "table", "tail", "thread", "throat", "thumb", "ticket",
     "toe", "tongue", "tooth", "town", "train", "tray", "tree", "trousers", "umbrella",
     "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm"
};
const string FIGURE[] = {
    " ------------- \n"
    " |            \n"
    " |            \n"
    " |            \n"
    " |            \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |            \n"
    " |            \n"
    " |            \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |            \n"
    " |            \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |           | \n"
    " |            \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /| \n"
    " |            \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /|\\ \n"
    " |            \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /|\\ \n"
    " |          / \n"
    " |            \n"
    " ----- \n",

    " ------------- \n"
    " |           | \n"
    " |           O \n"
    " |          /|\\ \n"
    " |          / \\ \n"
    " | \n"
    " ----- \n"
};
const int MAX_BAD_GUESS = 7;


string chooseSecretWord();
void renderGuessing(string guessWord, int numBadGuess=0);
char readGuess();
bool checkGuess(string secretWord, string guessWord, char &guessChar);
void updateGuessWord(string secretWord, string &guessWord, char guessChar);
void renderEndGame(string secretWord, int numBadGuess=MAX_BAD_GUESS);

int main()
{
    //initalize
    srand(time(NULL));
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
    while(numBadGuess<MAX_BAD_GUESS && secretWord!=guessWord);

    //result
    renderEndGame(secretWord, numBadGuess);
    return 0;
}

string chooseSecretWord()
{
    const int NUM_WORD = sizeof(WORD_LIST)/sizeof(string);
    int random_index = rand()%NUM_WORD;
    return WORD_LIST[random_index];
}

void renderGuessing(string guessWord, int numBadGuess)
{
    cout << FIGURE[numBadGuess] << endl;
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

bool checkGuess(string secretWord, string guessWord, char &guessChar)
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
    for(int i=0; i<guessWord.size(); ++i)
    {
        if(guessChar==guessWord[i])
        {
            cout << "You've guessed this word before!" << endl;
            return true;
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

void renderEndGame(string secretWord, int numBadGuess)
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
    cout << "The correct word is " << secretWord;
}
