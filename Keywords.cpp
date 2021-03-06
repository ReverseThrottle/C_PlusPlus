/*
	Zachary Hopping
	10/6/2020
	CIA Codebreaker/Keywords
	Random 10 words scramble them and have user guess the words include hints if they need help 
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


void jumblefunc()
{
    enum fields { WORD, HINT, NUM_FIELDS };
    const int NUM_WORDS = 10;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
        {"wall", "Do you feel you're banging your head against something?"},
        {"glasses", "These might help you see the answer."},
        {"labored", "Going slowly, is it?"},
        {"persistent", "Keep at it."},
        {"jumble", "It's what the game is all about."},
        {"secret", "It's unknown by others."},
        {"brilliant", "Very bright."},
        {"angry", "Strong feelings showing annoyance."},
        {"dido", "Mischievous deed."},
        {"english", "You speak this language"}
    };

    srand(static_cast<unsigned int>(time(NULL)));
    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD];  // word to guess
    string theHint = WORDS[choice][HINT];  // hint for word

    string jumble = theWord;  // jumbled version of word
    int length = jumble.size();
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = jumble[index1];
        jumble[index1] = jumble[index2];
        jumble[index2] = temp;
    }

    cout << "Enter 'hint' for a hint.\n";
    cout << "Enter 'quit' to quit the game.\n\n";
    cout << "The jumble is: " << jumble;

    string guess;
    int guessCounter = 1;
    cout << "\n\nYour guess: ";
    cin >> guess;

    while ((guess != theWord) && (guess != "quit"))
    {
        if (guess == "hint")
        {
            cout << theHint;
        }
        else
        {
            cout << "Sorry, that's not it.";
            ++guessCounter;
        }

        cout << "\n\nYour guess: ";
        cin >> guess;
    }

    if (guess == theWord)
    {
        cout << "\nThat's it!  You guessed it!\n";
        cout << "\nIt took you " << guessCounter << " tries to guess the word, " << theWord << endl;
    }

    if (guess == "quit")
    {
        cout << "\nYou have failed your mission.\n";
        cout << "The word was " << theWord << endl;
    }
}


int main()
{
    cout << "Welcome to the CIA Code Breakers Challenge!\n";
    cout << "Your job is to unscramble the letters to make a word.\n";
    
    jumblefunc();

    cout << "\n\n";

    jumblefunc();

    cout << "\n\n";

    jumblefunc();
    
    cout << "\nThanks for playing.\n";

    cout << "Would you like to try again?\n";
    cout << "[Y]es or [N]o\n";
    string again;
    cin >> again;
    
    return 0;
}
