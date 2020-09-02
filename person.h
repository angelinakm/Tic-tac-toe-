//
//  person.h
//  hw1tictac
//
//  Created by Angelina Kim on 4/13/20.
//  Copyright © 2020 Angelina Kim. All rights reserved.
//

#ifndef person_h
#define person_h
#include <string>
using namespace std;

class Person{
    public:
    Person ();
    Person (const string& pname);
    
    string get_name() const;
    void add_score ();
    int get_score() const;
    
    private:
    string name;
    int score;
    
};

#endif /* person_h */
