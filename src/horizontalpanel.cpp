// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "guisystem.h"

HorizontalPanel::HorizontalPanel(Context& ctx, float widthScale, float heightScale) {
	this->widthScale = widthScale;
	this->heightScale = heightScale;
	this->children = new std::vector<Component*>();
}

HorizontalPanel::~HorizontalPanel() {
	for (Component* child : *children) {
		delete(child);
	}
	delete(this->children);
}

int HorizontalPanel::Height(Context& ctx) {
	if (parent == nullptr) {
		return ctx.ScreenHeight();
	}
	return (int)((float)parent->Height(ctx) * heightScale);
}

int HorizontalPanel::Width(Context& ctx) {
	if (parent == nullptr) {
		return ctx.ScreenWidth();
	}
	return (int)((float)parent->Width(ctx) * widthScale);
}

void HorizontalPanel::Draw(Context& ctx) {
	int width = Width(ctx);
	int halfHeight = Height(ctx) / 2;
	int totalChildWidth = 0;
	for (auto& child : *children) {
		totalChildWidth += child->Width(ctx);
	}
	int childSpacing = (width - totalChildWidth) / (children->size() + 1);
	int nextChildX = X();
	for (auto& child : *children) {
		nextChildX += childSpacing;
		child->DrawComponent(ctx, nextChildX, Y() + (halfHeight - (child->Height(ctx) / 2)));
		nextChildX += child->Width(ctx);
	}
}

void HorizontalPanel::AddChild(Context& ctx, Component* child) {
	child->parent = this;
	children->push_back(child);
}
