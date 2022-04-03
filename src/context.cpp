// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "context.h"
#include "cmath"

Context::Context() {
	Screen.width = 1280;
	Screen.height = 720;
}

void Context::Update() {
	// Screen
	Screen.width = GetScreenWidth();
	Screen.height = GetScreenHeight();

	// Mouse
	auto mousePos = GetMousePosition();
	int prevMouseX = Mouse.x;
	int prevMouseY = Mouse.y;
	Mouse.x = (int)mousePos.x;
	Mouse.y = (int)mousePos.y;
	bool prevMouseDown = Mouse.down;
	Mouse.down = IsMouseButtonDown(MOUSE_BUTTON_LEFT);
	if (prevMouseDown && !Mouse.down && (abs(Mouse.x - prevMouseX) + abs(Mouse.y - prevMouseY)) <= 4) {
		Mouse.clicked = true;
	} else {
		Mouse.clicked = false;
	}
}
