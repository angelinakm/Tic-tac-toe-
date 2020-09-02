//
//  person.cpp
//  hw1tictac
//
//  Created by Angelina Kim on 4/13/20.
//  Copyright © 2020 Angelina Kim. All rights reserved.
//

#include "person.h"
#include <iostream>
using namespace std;


Person::Person ():name("default"), score(0){}
Person::Person (const string& pname):name(pname), score(0){}

string Person::get_name() const{
    return name;
}

void Person::add_score(){
    score++;
}

int Person::get_score() const{
    return score;
}
