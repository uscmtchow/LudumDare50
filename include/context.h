// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef CONTEXT_H
#define CONTEXT_H
#include "raylib/raylib.h"

class Context;

struct Colors_ {
	Color Background = Color{30, 30, 30, 255};
};

struct Mouse_ {
	friend class Context;

public:
	int X() { return x; }
	int Y() { return y; }
	bool IsDown() { return down; }
	bool HasClicked() { return clicked; }

private:
	int x = -2147483648;
	int y = -2147483648;
	bool down = false;
	bool clicked = false;
};

struct Screen_ {
	friend class Context;

public:
	int Width() const { return width; };
	int Height() const { return height; };

private:
	int width = 0;
	int height = 0;
};

class Context {
public:
	Context();
	~Context() = default;
	void Update();
	const Colors_ Colors;
	Screen_ Screen;
	Mouse_ Mouse;
};

#endif //CONTEXT_H
