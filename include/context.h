// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef CONTEXT_H
#define CONTEXT_H
#include "raylib.h"

class Context {
public:
	Context();
	~Context() = default;
	void NewFrame();
	int ScreenWidth() const { return screenWidth; };
	int ScreenHeight() const { return screenHeight; };
	//int TimeSinceGameStart();
private:
	int screenWidth;
	int screenHeight;
};

#endif //CONTEXT_H
