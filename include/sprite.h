// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include "raylib.h"

class Sprite {
public:
    Sprite();
    ~Sprite();
    Sprite& LoadSprite(std::string name, std::string color, Vector2 position);
private:
    std::string spriteName;


};

Sprite::Sprite() {
    // Set initial variables to their base values
    spriteName = "";
}

Sprite::~Sprite() {
    // Nothing dynamically allocated
}
/*
   Name: Determined by random generator
   Color: Determined by type of the character, which correspond to the appropriate elmental resistances
   Position: Used to determine which fighting location enemy spawns in
        - Position of enemies can change depending on number of them already on the field
*/

Sprite& Sprite::LoadSprite(std::string name, std::string color, Vector2 position) {
    spriteName = name;
    if (name == "goblin") {
        Image grayGoblin = LoadImage("")
    }
}

#endif //CHARACTER_H
