#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include "hangman.h"
#include "wordlist.h"
using namespace std;

int main(int argc, char* argv[])
{
    srand(time(NULL));
    do
    {
        playHangman();
    }
    while(continuePlaying());
    return 0;
}
