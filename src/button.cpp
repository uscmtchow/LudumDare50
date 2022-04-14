// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "guisystem.h"

Button::Button(Context& ctx, float widthScale, float heightScale, Label* label) {
	this->text = text;
	this->widthScale = widthScale;
	this->heightScale = heightScale;
	this->label = label;
	label->parent = this;
}

Button::~Button() {
	delete(this->label);
}

int Button::Height(Context& ctx) {
	return (int)((float)parent->Height(ctx) * heightScale);
}

int Button::Width(Context& ctx) {
	return (int)((float)parent->Width(ctx) * widthScale);
}

void Button::Draw(Context& ctx) {
	DrawRectangle(X(), Y(), Width(ctx), Height(ctx), GRAY);
	label->DrawComponent(ctx, X() + ((Width(ctx) / 2) - (label->Width(ctx) / 2)), Y() + ((Height(ctx) / 2) - (label->Height(ctx) / 2)));
}
