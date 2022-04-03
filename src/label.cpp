// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "guisystem.h"

Label::Label(Context& ctx, std::string text, float widthScale, float heightScale) {
	this->text = text;
	this->widthScale = widthScale;
	this->heightScale = heightScale;
	this->textLengthAt10 = (float)MeasureText(text.c_str(), 10);
}

Label::~Label() {}

int Label::Height(Context& ctx) {
	return (int)((float)parent->Height(ctx) * heightScale);
}

int Label::Width(Context& ctx) {
	return (int)((float)parent->Width(ctx) * widthScale);
}

void Label::Draw(Context& ctx) {
	int fontSize = Height(ctx);
	int fontLength = MeasureText(text.c_str(), fontSize);
	if (fontLength > Width(ctx)) {
		fontLength = Width(ctx);
		fontSize = (int)(((float)fontLength / textLengthAt10) * 10.0f);
	}
	DrawText(text.c_str(),
		X() + (Width(ctx) / 2) - (fontLength / 2),
		Y() + (Height(ctx) / 2) - (fontSize / 2),
		fontSize,
		Color{70, 70, 70, 255});
}
