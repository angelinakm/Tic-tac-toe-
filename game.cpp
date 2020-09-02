//
//  game.cpp
//  hw1tictac
//
//  Created by Angelina Kim on 4/13/20.
//  Copyright © 2020 Angelina Kim. All rights reserved.
//

#include "game.h"
#include <iostream>
#include <vector>
using namespace std;

Game::Game(){
    player1 = new Person();
    player2 = new Person();
}
Game:: Game(const string& name1, const string& name2){
    player1 = new Person(name1);//pointer points to class Person object
    player2 = new Person(name2);
   // nameone= name2;
   // nametwo = name2;
    for (int i=0; i<3; i++){
        vector<int>vec;
        for (int j=0; j<3; j++){
            vec.push_back(0);
        }
        board.push_back(vec);
    }
}
Game::~Game()
{delete player1; delete player2;}

void Game:: putmark(int player_turn, int row, int col){

    board[row][col] = player_turn;
}

int Game::victory() const {
    for (int i = 1; i<2; i++){
        if ((board[0][0]==i && board [0][1]==i && board [0][2]==i) || (board[1][0]==i && board [1][1]==i && board [1][2]==i) || (board[2][0]==i && board [2][1]==i && board [2][2]==i)){
        return i;
        }
        else if ((board[0][0]==i && board [1][0]==i && board [2][0]==i) || (board[0][1]==i && board [1][1]==i && board [2][1]==i) || (board[0][2]==i && board [1][2]==i && board [2][2]==i)){
            return i;
    }
        else if ((board[0][0]==i && board [1][1]==i && board [2][2]==i) || (board[0][2]==i && board [1][1]==i && board [2][0]==i)){
                return i;
        }
    }
    return 0;
}
void Game:: show_board() const{
    for (int i=0; i<3; i++){
        for (int j =0; j<3; j++){
       // char mark;
      //  if (board[i][j])
      //  cout <<"    "<<"|"<<"    "<<"|"<< "    "<<"\n";
       // cout<< board[i][0]<<"   |"<<board[i][1]<<"   |"<< board[i][2]<<"\n";
      //  cout<<"_________________\n";
            char mark;
            if (board[i][j]==0){
                mark = ' ';
            }
            else if (board[i][j]==1){
                mark = 'X';
            }
            else{
                mark = 'O';
            }
           cout<<mark<<" |";
        }
        cout <<endl;
        cout<< "__________\n";
    }
  }
void Game:: clear_board() {
    for (int i=0; i<3; ++i){
        for (int j=0; j<3; ++j){
        board[i][j] = 0;
        }
    }
}

void Game:: results(){
    cout<<player1->get_name()<<" : "<< player1->get_score()<<endl;
    cout<<player2->get_name()<<" : "<< player2->get_score()<<endl;
    if (player1->get_score() > player2->get_score()){
        cout<< "Congratulations "<<player1->get_name()<<". You won!\n";
    }
    else{
        cout<<"Congratulations "<<player2->get_name()<<". You won!\n";
    }
    
}

bool Game:: correct_coord(int row, int col) const{
    if ((row >=0 && row <=2 ) && (col>=0 && row <=2)){
        if(board[row][col]==0){
        return true;
        }else{
            return false;
        }
        }
    
    else{
        return false;
    }
}
        
void Game:: gameplay(){
    int count = 0;
    clear_board();
    while (true){
        if (count%2 == 0){
            //system("clear");
            cout<<player1->get_name() << " (X) Mark Location: ";
            int row, col;
            cin>>row>>col;
             if (cin.fail()){
                 cout<<"Wrong input."<<endl;
            break;
            }
            if (correct_coord(row, col)==true){
            putmark(1, row, col);
                show_board();
               int keep_score = victory();
                if (victory()!=0){
                cout<<player1->get_name() <<" wins\n";
                   if (keep_score == 1){
                      player1->add_score();
                    }
                    else if (keep_score==2){
                        player2->add_score();
                    }
                break;
            }
                count++;
            }
                
           else{
                cout<<"Wrong coordinates\n";
           }
                }
        
        else{
            //system("clear");
            cout<<player2->get_name() <<" (O) Mark Location: ";
            int row, col;
            cin>>row>>col;
             if (cin.fail()){
                cout<<"Wrong input."<< endl;
              break;
           }
            if (correct_coord(row, col)==true){
            putmark(2, row, col);
            show_board();
            int keep_score = victory();
            if (victory()!=0){
            cout<<player2->get_name() <<" wins\n";
                if (keep_score == 1){
                    player1->add_score();
                }
                else if (keep_score==2){
                    player2->add_score();
                }
                break;
          }
                count++;
            }
           else{
               cout<<"Wrong coordinates\n";
           }

            }
        }
    }


