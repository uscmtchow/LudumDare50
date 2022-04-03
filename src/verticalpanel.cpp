// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "guisystem.h"

VerticalPanel::VerticalPanel(Context& ctx, float widthScale, float heightScale) {
	this->widthScale = widthScale;
	this->heightScale = heightScale;
	this->children = new std::vector<Component*>();
}

VerticalPanel::~VerticalPanel() {
	for (Component* child : *children) {
		delete(child);
	}
	delete(this->children);
}

int VerticalPanel::Height(Context& ctx) {
	if (parent == nullptr) {
		return ctx.ScreenHeight();
	}
	return (int)((float)parent->Height(ctx) * heightScale);
}

int VerticalPanel::Width(Context& ctx) {
	if (parent == nullptr) {
		return ctx.ScreenWidth();
	}
	return (int)((float)parent->Width(ctx) * widthScale);
}

void VerticalPanel::Draw(Context& ctx) {
	int height = Height(ctx);
	int halfWidth = Width(ctx) / 2;
	int totalChildHeight = 0;
	for (auto& child : *children) {
		totalChildHeight += child->Height(ctx);
	}
	int childSpacing = (height - totalChildHeight) / (children->size() + 1);
	int nextChildY = Y();
	for (auto& child : *children) {
		nextChildY += childSpacing;
		child->DrawComponent(ctx, X() + (halfWidth - (child->Width(ctx) / 2)), nextChildY);
		nextChildY += child->Height(ctx);
	}
}

void VerticalPanel::AddChild(Context& ctx, Component* child) {
	child->parent = this;
	children->push_back(child);
}
