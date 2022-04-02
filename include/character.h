// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character {
public:
    Character();
    ~Character();

    /*
      Thinking of keeping track of buffs and debuffs in two ways:
      1. We can have a vector of strings and include and remove whatever buff/debuff applied to the character when they
      receive buff/debuff.
      2. We can create functions, such as
                isPoisoned() {
                    if (poisoned == true) { return true; }
                    return false;
                }
      And call them every round. Both are very scalable, I think that the functions while more work upfront are better
      in the long run, if we are just considering runtime because the second option is constant time O(1) compared to
      O(n) n being the size of the vector arrays created
    */
//    std::vector<std::string> buffs;
//    std::vector<std::string> debuffs;

    // Need to create a structure to the list of runes a character holds
    // RUNE is some data structure holding the rest of the runes data
    // std::map<runeName, RUNE> runeList;

private:
    unsigned int level; // Character Level
    unsigned int healthPoints; // The amount of damage a character can handle before dying
    unsigned int physicalArmor; // Flat reduction against physical attacks
    unsigned int specialArmor; // Flat reduction against special (magical) attacks
    int speed; // Determines who attacks first
    /* Percentage resistances corresponding to the variable title - for ex. fireResistance is a percentage resistance
        against fire attacks */
    int fireResistance, waterResistance, electricResistance, windResistance;
};

Character::Character() {
    // Set all variables to their start
    level = 0;
    healthPoints = 500;
    physicalArmor = 50;
    specialArmor = 25;
    speed = 20;
    fireResistance = 0;
    waterResistance = 0;
    electricResistance = 0;
    windResistance = 0;
}

Character::~Character() {
    // No Memory Leaked
}

#endif //CHARACTER_H
