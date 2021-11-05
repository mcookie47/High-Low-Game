// HighLow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Card.h"
#include "Player.h"

using namespace std;

int main()
{
    int dealer_rank;
    int player_rank;
    float bet = 0;
    char choice = 'a';
    Card card;
    Player player = Player();
    Yesno yesno = Yesno();
    yesno.answer = "yes";

    cout << "Name:";
    cin >> player.name;

    cout << "How much money would like to start with? ";
    cin >> player.starting_balance;
    while (yesno.answer == "yes") {
        player.balance = player.starting_balance;

        while (player.balance > 0 && (player.balance < player.starting_balance * 5)) {
            cout << player.name << ", you have $"
                << player.balance << ". ";

            while (bet == 0 || bet > player.balance) {
                cout << "How much money do you want to bet? ";
                cin >> bet;

                if (bet > player.balance) {
                    cout << "Sorry, you don't have enough money to make that bet.\n";
                }
            }

            card = Card();
            dealer_rank = card.get_rank();

            cout << "You draw a " << card.get_rank_string()
                << " of " << card.get_suit_string() << ".\n";
            
            cout << "Will the next card be higher or lower? "
                << "Enter \"h\" for higher or \"l\" for lower: ";
            cin >> choice;
            while (choice != 'h' && choice != 'l') {
                cout << "Error. Enter \"h\" for higher or \"l\" for lower: ";
                cin >> choice;
            }

            card = Card();
            player_rank = card.get_rank();

            cout << "You draw a " << card.get_rank_string()
                << " of " << card.get_suit_string() << ".\n";

            if ((choice == 'h' && dealer_rank > player_rank) ||
                (choice == 'l' && dealer_rank < player_rank)) {
                player.balance -= bet;

                cout << "You Lose!" << bet << ".\n";
            }
            else {
                player.balance += bet;

                cout << "YOU WIN!!! Congratulations " + player.name
                    << ". You win $" << bet << "!\n";
            }
            bet = 0;

        }
        if (player.balance <= 0) {
            cout << "Too bad " + player.name << ". "
                << "You are out of money! \n Keep playing? ";
            cin >> yesno.answer;
                if (yesno.answer == "yes") {
                    cout << "Enter new bet: ";
                    cin >> player.starting_balance;
                }
                else if (yesno.answer == "no") {
                    cout << "You lose! Thanks for playing.\n";
                    return 0;
                }
                else
                {
                    cout << "Error. Type yes or no. ";
                    cin >> yesno.answer;
                }         
        }
        else {
            cout << "You win the game " + player.name << "!";
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
