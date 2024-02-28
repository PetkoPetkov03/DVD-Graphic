#include "graphics.h"
#include <iostream>

typedef struct {
	int x;
	int y;
} Vector2D;

void draw_flower(Vector2D position, int del) {
	setlinestyle(SOLID_FILL, 0, 4);
	arc(position.x+del, position.y - del, 135, 315, 141);
	arc(position.x - del, position.y + del, 315, 135, 141);
	arc(position.x - del, position.y - del, 225, 405, 141);
	arc(position.x + del, position.y + del, 45, 225, 141);
	putpixel(position.x + del, position.y, WHITE);
	putpixel(position.x - del, position.y, WHITE);
	putpixel(position.x, position.y - del, WHITE);
	putpixel(position.x, position.y + del, WHITE);
}

void move(int speedx, int speedy, Vector2D* position) {
	position->x += speedx;
	position->y += speedy;
}

int main()
{
	bool running = true;
	int speedx = 2;
	int speedy = 2;
	int maxWidth = 1800;
	int maxHeight = 800;
	initwindow(maxWidth, maxHeight, "DVD");
	Vector2D position = { 300, 300 };
	int del = 100;
	
	

	while (running) {
		draw_flower(position, del);
		if (position.x + del * 2 >= maxWidth || position.x - del*2 <= 0) {
			speedx = -speedx;
		}

		if (position.y + del * 2 >= maxHeight || position.y - del*2 <= 0) {
			speedy = -speedy;
		}

		std::cout << speedx << " " << speedy << std::endl;
		
		move(speedx, speedy, &position);
		cleardevice();
	}
	getch();
	closegraph();
}