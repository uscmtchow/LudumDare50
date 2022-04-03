// Copyright © 2022 Daylon Wilkins & Maxwell Chow
//
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "guisystem.h"

int main(void) {
	Context ctx = Context();
	const Color background = Color{30, 30, 30, 255};

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(ctx.ScreenWidth(), ctx.ScreenHeight(), "The Fastest RPG");
	SetTargetFPS(60);

	int menu = 0;

	auto mainMenu = VerticalPanel(ctx, 1, 1);
	auto titlePanel = new VerticalPanel(ctx, 1, 0.4);
	auto buttonPanel = new VerticalPanel(ctx, 1, 0.6);
	mainMenu.AddChild(ctx, titlePanel);
	mainMenu.AddChild(ctx, buttonPanel);

	titlePanel->AddChild(ctx, new Label(ctx, "The Fastest RPG", .7, .5));
	auto playButton = new Button(ctx, 0.4, 0.15, new Label(ctx, "PLAY", 0.7, 0.7));
	buttonPanel->AddChild(ctx, playButton);
	auto leaderboardsButton = new Button(ctx, 0.4, 0.15, new Label(ctx, "LEADERBOARDS", 0.7, 0.7));
	buttonPanel->AddChild(ctx, leaderboardsButton);
	auto playerButton = new Button(ctx, 0.4, 0.15, new Label(ctx, "PLAYER", 0.7, 0.7));
	buttonPanel->AddChild(ctx, playerButton);
	auto volPlaceholderButton = new Button(ctx, 0.4, 0.15, new Label(ctx, "VOL PLACEHOLDER", 0.7, 0.7));
	buttonPanel->AddChild(ctx, volPlaceholderButton);

	while (!WindowShouldClose()) {
		ctx.NewFrame();
		BeginDrawing();
		ClearBackground(background);

		if (menu == 0) {
			mainMenu.DrawComponent(ctx, 0, 0);
		} else if (menu == 1) {

		}

		EndDrawing();
	}

	CloseWindow();
	return 0;
}
