#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

void intro(int difficulty)
{
    cout << "Level " << difficulty << endl;
    cout << "Guess the three numbers." << endl;
}

bool playGame(int difficulty)
{
    
    const int a = rand() % difficulty + difficulty;
    const int b = rand() % difficulty + difficulty;
    const int c = rand() % difficulty + difficulty;
    
    const int sum = a + b + c;
    const int prod = a * b * c;

    cout << "the sum of them is: " << sum << endl;
    cout << "the product of them is: " << prod << endl;

    int guessCount = 2;

    while(guessCount >= 0)
    {
        cout << "Enter your guess:" << endl;
        int guessA;
        int guessB;
        int guessC;
        cin >> guessA >> guessB >> guessC;
        int guessSum = guessA + guessB + guessC;
        int guessProd = guessA * guessB * guessC;

        if(guessSum == sum && guessProd == prod)
        {
            cout << "Noice! You got it right!" << endl;
            cout << endl;
            return true;
        }
        cout << "Incorrect. You have " << guessCount << " attemp(s) left" << endl;
        --guessCount;
        cin.clear();
        cin.ignore(100, '\n');
    }
    return false; 
}

int main()
{
    srand(time(NULL));

    int difficulty = 1;
    const int maxDif = 10;
    while(difficulty <= maxDif)
    {
        bool levelComplete = playGame(difficulty);

        if(levelComplete)
        {
            if(difficulty == maxDif)
            {
                cout << "Congratulations! You finished the game";
                exit(0); 
            }
            ++difficulty;
        }
        else
        {
            cout << "Good luck next time loser!" << endl;
            exit(0);
        }
    }
    return 0;
}