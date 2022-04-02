// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef LUDUMDARE50_ENEMY_H
#define LUDUMDARE50_ENEMY_H
#include "character.h"

#endif //LUDUMDARE50_ENEMY_H

class Enemy : public Character {
public:
    Enemy();
    ~Enemy();

private:
    struct bossEnemy() {
    public:
        bossEnemy();
        ~bossEnemy();
    private:

    }
}

Enemy::Enemy() {
    // No separate variables yet;
}

~Enemy::~Enemy() {
    // Nothing to destroy yet;
}

Enemy::bossEnemy::bossEnemy() {
    // Will eventually right multipliers to the character variables
}

Enemy::bossEnemy::~bossEnemy() {
    // Nothing to destroy yet;
}