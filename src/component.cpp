// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "guisystem.h"

void Component::DrawComponent(Context& ctx, int x, int y) {
	this->x = x;
	this->y = y;
	this->Draw(ctx);
}
