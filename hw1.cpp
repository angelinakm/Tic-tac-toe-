// Pic 10B 2A, Homework 1
// Purpose: Tic-Tac-Toe Game
// Author: Angelina Kim
// Date: 04/19/2020

#include <iostream>
#include "person.h"
#include "game.h"
using namespace std;

int main() {
    cout<<"Number of games? ";
    int num_games;
    cin>>num_games;
    cin.get();
    string playerone, playertwo;
    cout <<"Player's name ";
    getline (cin, playerone);
    cout<<"Player's name ";
    getline (cin, playertwo);
  
    Game game (playerone, playertwo);

    for (int i = 0; i<num_games; i++){
       cout<<"Round "<< i+1<<endl;
        game.gameplay();
    }

    game.results();

}
