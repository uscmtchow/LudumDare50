// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef GUISYSTEM_H
#define GUISYSTEM_H
#include "vector"
#include "string"
#include "context.h"

class VerticalPanel;
class HorizontalPanel;
class Button;

class Component {
	friend class VerticalPanel;
	friend class HorizontalPanel;
	friend class Button;

public:
	virtual int Width(Context& ctx) = 0;
	virtual int Height(Context& ctx) = 0;
	void DrawComponent(Context& ctx, int x, int y);
	int X() { return x; }
	int Y() { return y; }

protected:
	virtual void Draw(Context& ctx) = 0;
	Component* parent = nullptr;

private:
	int x;
	int y;
};

class Label : public Component {
public:
	Label(Context& ctx, std::string text, float widthScale, float heightScale);
	~Label();
	int Width(Context& ctx) override;
	int Height(Context& ctx) override;

protected:
	void Draw(Context& ctx) override;

private:
	std::string text;
	float widthScale;
	float heightScale;
	float textLengthAt10;
};

class VerticalPanel : public Component {
public:
	VerticalPanel(Context& ctx, float widthScale, float heightScale);
	~VerticalPanel();
	int Width(Context& ctx) override;
	int Height(Context& ctx) override;
	void AddChild(Context& ctx, Component* child);

protected:
	void Draw(Context& ctx) override;

private:
	float widthScale;
	float heightScale;
	std::vector<Component*>* children;
};

class HorizontalPanel : public Component {
public:
	HorizontalPanel(Context& ctx, float widthScale, float heightScale);
	~HorizontalPanel();
	int Width(Context& ctx) override;
	int Height(Context& ctx) override;
	void AddChild(Context& ctx, Component* child);

protected:
	void Draw(Context& ctx) override;

private:
	float widthScale;
	float heightScale;
	std::vector<Component*>* children;
};

class Button : public Component {
public:
	Button(Context& ctx, float widthScale, float heightScale, Label* label);
	~Button();
	int Width(Context& ctx) override;
	int Height(Context& ctx) override;

protected:
	void Draw(Context& ctx) override;

private:
	std::string text;
	float widthScale;
	float heightScale;
	Label* label;
};

#endif //GUISYSTEM_H
