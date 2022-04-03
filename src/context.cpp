// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "context.h"

Context::Context() {
	screenWidth = 1280;
	screenHeight = 720;
}

void Context::NewFrame() {
	this->screenWidth = GetScreenWidth();
	this->screenHeight = GetScreenHeight();
}
