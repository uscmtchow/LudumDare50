// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "sprite.h"
#include "raylib.h"

Sprite& intializeSprite(SpriteName spriteName, Color spriteColor) {
    switch(spriteName) {
		case SpriteName::SpearGoblin:
            Sprite* SpearGoblin;
            SpearGoblin->name = spriteName;
            SpearGoblin->color = spriteColor;
            return *SpearGoblin;
        case SpriteName::BearBaby:
            Sprite* BearBaby;
            BearBaby->name = spriteName;
            BearBaby->color = spriteColor;
            return *BearBaby;
        case SpriteName::Golem:
            Sprite* Golem;
            Golem->name = spriteName;
            Golem->color = spriteColor;
            return *Golem;
    }
}

void printSprite(Sprite sprite) {
    Image grayImage, backImage;
	SpriteName spriteCheck = sprite.name;

    switch(spriteCheck) {
        case SpriteName::SpearGoblin:
            grayImage = LoadImage("../Art/Enemies/SpearGoblin/GrayLayer.png");
            backImage = LoadImage("../Art/Enemies/SpearGoblin/ColorLayer.png");
        case SpriteName::BearBaby:
            grayImage = LoadImage("../Art/Enemies/BabyBearBaby/GrayLayer.png");
            backImage = LoadImage("../Art/Enemies/BabyBearBaby/ColorLayer.png");
        case SpriteName::Golem:
            grayImage = LoadImage("../Art/Enemies/Golem/GrayLayer.png");
            backImage = LoadImage("../Art/Enemies/Golem/ColorLayer.png");
    }
    // Resize the image to whatever size we feel necessary
//    int resizeVar = 250;
//    ImageResize(grayImage, resizeVar, resizeVar);
//    ImageResize(backImage, resizeVar, resizeVar);

    // Extract a texture from the corresponding image
    Texture2D grayTexture = LoadTextureFromImage(grayImage);
    Texture2D backTexture = LoadTextureFromImage(backImage);

    // Release the image data
    UnloadImage(grayImage);
    UnloadImage(backImage);

    // Draw the textures at the same position + tinting the gray one with the given color
    DrawTexture(grayTexture, sprite.posX, sprite.posY, sprite.color);
    DrawTexture(backTexture, sprite.posX, sprite.posY, WHITE);
}
