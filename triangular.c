#include <raylib.h>
#include <stdio.h>

#define FONT_SIZE 10 
#define PLAYER_TXT "Penrose480"

int main(void) 
{
    
    /* initialization */
    const int screenWidth = 800;
    const int screenHeight = 450;
    int score = 0;
    char txt[32];


    InitWindow(screenWidth, screenHeight, "TRIANGULAR");
    
    Vector2 text_pos = { 190, 200 };
    float speed = 200.0f;
    Rectangle rect = { 400, 200, 50, 50 };
    int textWidth = MeasureText(PLAYER_TXT, FONT_SIZE);
    
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
	/* Update */
	if (IsKeyDown(KEY_RIGHT) && text_pos.x < (float)screenWidth - textWidth) text_pos.x += speed * GetFrameTime();	
	if (IsKeyDown(KEY_LEFT) && text_pos.x > 0) text_pos.x -= speed * GetFrameTime();
	if (IsKeyDown(KEY_UP) && text_pos.y > 0) text_pos.y -= speed * GetFrameTime();
	if (IsKeyDown(KEY_DOWN) && text_pos.y < screenHeight - FONT_SIZE) text_pos.y += speed * GetFrameTime();

	/* Score */
	if(CheckCollisionPointRec(text_pos, rect)) {
	    score++;

      /* Move to random position */
	    rect.x = GetRandomValue(0, screenWidth - 50);
	    rect.y = GetRandomValue(30, screenHeight - 50); /* prevent overlapping with text */
	}

	/* Draw text and rect */
	BeginDrawing();
	    
	    ClearBackground(RAYWHITE);

	    DrawText(PLAYER_TXT, (int)text_pos.x, (int)text_pos.y, FONT_SIZE, LIGHTGRAY);

	    DrawText("Move me with arrow keys!", 0, 0, 30, DARKGREEN);

	    DrawRectangle(rect.x, rect.y, rect.width, rect.height, LIGHTGRAY);

	    snprintf(txt, sizeof(txt), "Score: %d", score);
	    DrawText(txt, 0, 30, 30, DARKPURPLE);
	
	EndDrawing();
    }

    CloseWindow();
    return 0;
}
