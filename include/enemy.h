// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character {
public:
    Enemy();
    ~Enemy();
};

Enemy::Enemy() {
    // No separate variables yet;
}

Enemy::~Enemy() {
    // Nothing to destroy yet;
}

#endif //ENEMY_H
