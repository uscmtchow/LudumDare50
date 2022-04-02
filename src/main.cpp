#include "../include/raylib.h"

int main(void) {
	InitWindow(800, 450, "TestWindow");

	while (!WindowShouldClose()) {
		BeginDrawing();
		ClearBackground(RAYWHITE);
		DrawText("Some random text", 200, 200, 20, BLACK);
		EndDrawing();
	}

	CloseWindow();

	return 0;
}