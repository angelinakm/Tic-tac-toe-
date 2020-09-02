//
//  game.h
//  hw1tictac
//
//  Created by Angelina Kim on 4/13/20.
//  Copyright © 2020 Angelina Kim. All rights reserved.
//

#ifndef game_h
#define game_h
#include "person.h"
#include <string>
#include <vector>
using namespace std;

class Game{
    public:
    Game();
    Game(const string& name1, const string& name2);
    ~Game();
    void drawboard () const;
    void gameplay();
    bool checkcoord(int row, int col) const;
    void putmark (int player_turn, int row, int col);
    void show_board() const;
    int victory() const;
    bool correct_coord(int row, int col) const;
    void clear_board();
    void results();
    
    
    private:
    Person* player1;
    Person* player2;
    string nameone;
    string nametwo;
    vector <vector<int>> board;
};

#endif /* game_h */
