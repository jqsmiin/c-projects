#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

string generateComputerChoice();
void getWinner(string user, string computer);
int main()
{
    cout << "****************This is a rock, paper scissor game******************\n";

    int choice;
    string user;
    string computer;

    cout << "Please choose a number between 1 & 3 \n";
    cout << "#1 - Rock\n";
    cout << "#2 - Paper\n";
    cout << "#3 - Scissor\n";

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You choosed rock! \n";
        user = "rock";
        break;
    case 2:
        cout << "You choosed paper! \n";
        user = "paper";
        break;
    case 3:
        cout << "You choosed scissor! \n";
        user = "scissor";
        break;
    default:
        cout << "Please choose number between 1 - 3 \n";
    }

    computer = generateComputerChoice();
    getWinner(user, computer);

    return 0;
}
string generateComputerChoice()
{
    string computer;
    // Providing a seed value
    srand((unsigned)time(NULL));

    // Get a random number
    int random = 1 + (rand() % 3);

    switch (random)
    {
    case 1:
        cout << "Computer choosed rock! \n";
        computer = "rock";
        break;
    case 2:
        cout << "Computer choosed paper! \n";
        computer = "paper";
        break;
    case 3:
        cout << "Computer choosed scissor! \n";
        computer = "scissor";
        break;
    default:
        break;
    }

    return computer;
}
void getWinner(string user, string computer)
{
    if (computer == "rock")
    {
        if (user == "rock")
        {
            std::cout << "It's a tie!";
        }
        else if (user == "paper")
        {
            std::cout << "You win!";
        }
        else if (user == "scissor")
        {
            std::cout << "You lost!";
        }
    }
    else if (computer == "paper")
    {
        if (user == "rock")
        {
            std::cout << "You lost!";
        }
        else if (user == "paper")
        {
            std::cout << "It's a tie!";
        }
        else if (user == "scissor")
        {
            std::cout << "You win!";
        }
    }
    else if (computer == "scissor")
    {
        if (user == "rock")
        {
            std::cout << "You win!";
        }
        else if (user == "paper")
        {
            std::cout << "You lost!";
        }
        else if (user == "scissor")
        {
            std::cout << "It's a tie!";
        }
    }
}