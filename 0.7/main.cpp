#include <iostream>
#include "random.h"


//Update your previous solution to handle invalid guesses (e.g. ‘x’), out of bounds guesses (e.g. 0 or 101),
//or valid guesses that have extraneous characters (e.g. 43x). Also handle the user entering extra characters
//when the game asks them whether they want to play again.
//
//Hint: Write a separate function to handle the user inputting their guess (along with the associated
//error handling).

//bool validateInput(int x)
//{
//    return true;
//}

int getInput()
{
    int userInput{};
    std::cout << "What is your guess? ";

    while (true)
    {
        std::cin >> userInput;
        if (std::cin.fail() or (userInput < 0 || userInput > 100))
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break;
    }
    return userInput;
}

bool checkAnswer(int userInput, int answer)
{
    if (userInput > answer)
        std::cout << "Too high!" << '\n';
    else if (userInput < answer)
        std::cout << "Too low!" << '\n';
    else
        std::cout << "You won!" << '\n';
    return userInput == answer;
}

void startGame()
{
    int randNum {Random::get(1, 100)};
    int tries{7};
    bool userWin{false};
    std::cout << "Let's play a game. I'm thinking of a "
                 "number between 1 and 100. You have 7 tries to guess what it is." << '\n';

    while (tries > 0)
    {
        if (checkAnswer(getInput(), randNum))
        {
            userWin = true;
            break;
        }
        --tries;
    }
    if (!userWin){
        std::cout << "Sorry, you lose. The number was: " << randNum << '\n';
    }
}

int main(){
gameStart:
    startGame();

replay:
    char playAgain{};
    std::cout << "Would you like to play again? (y/n)" << ' ';
    std::cin >> playAgain;

    while (true){
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        break;
    }


    if (playAgain == 'y')
        goto gameStart;
    else if (playAgain == 'n')
        std::cout << "Thank you for playing";
    else
        goto replay;
}