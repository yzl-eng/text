#include<stdio.h>
#include<graphics.h>
#include<conio.h>
//游戏画面尺寸
#define High 480
#define Width 640
int main(void)
{
	initgraph(Width,High);//初始化画布

	float ball_x, ball_y;//小球坐标
	float ball_vx, ball_vy;//小球速度
	float radius;//小球半径

	ball_x = Width / 2;
	ball_y = High / 2;
	ball_vx = 1;
	ball_vy = 1;
	radius = 20;
	for (int x = 100; x < 540; x += 20)
	{
		//绘制黄线，绿色填充圆
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(ball_x,ball_y,radius);
		//延时
		Sleep(200);
		//绘制黑线，黑色填充圆
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(ball_x,ball_y,radius);
	}
	closegraph;
	return 0;
}