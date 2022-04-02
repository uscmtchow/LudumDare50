// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef USER_H
#define USER_H
#include "character.h"

class User : public Character {
public:
    User();
    ~User();

private:
    unsigned int experiencePoints; // Important for keeping track of progress towards next level
    float evasion; // The likelihood of dodging an incoming enemy attack
    float runeChance; // The percentage of dropping a rune
};

User::User() {
    // Set User specific variables to their base stats
    experiencePoints = 0;
    evasion = 0.0f;

    // NEED TO CHANGE THIS TO EQUATION [DAYLON PROGRAMMED]
    runeChance = 0.0f;
}

User::~User() {
    // Nothing to deallocate yet;
}


#endif //USER_H
