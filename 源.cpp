#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
//游戏画面尺寸
#define High 480
#define Width 640
#define N 8          //小球数目
int main(void)
{
	srand((unsigned int)time(NULL));
	initgraph(Width, High);//初始化画布

	float ball_x[N], ball_y[N];//小球坐标
	float ball_vx[N], ball_vy[N];//小球速度
	float radius=20;//小球半径

	for (int i = 0; i < N; i++)
	{
		ball_x[i] = rand() % (Width / 2) + radius;
		ball_y[i] = rand() % (High / 2) + radius;

		ball_vx[i] = rand() % 3 + 1;
		ball_vy[i] = rand() % 3 + 1;
	}

	BeginBatchDraw();//开始批量绘制
	while(1)
	{
		//绘制黄线，绿色填充圆
		for (int i = 0; i < N; i++)
		{
			setcolor(YELLOW);
			setfillcolor(GREEN);
			fillcircle(ball_x[i], ball_y[i], radius);
		}

		FlushBatchDraw();//
		//延时
		Sleep(3);
		//绘制黑线，黑色填充圆
		for (int i = 0; i < N; i++)
		{
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(ball_x[i], ball_y[i], radius);
			ball_x[i] = ball_x[i] + ball_vx[i];
			ball_y[i] = ball_y[i] + ball_vy[i];
			if (ball_x[i] <= radius || ball_x[i] >= Width - radius)
				ball_vx[i] = -ball_vx[i];
			if (ball_y[i] <= radius || ball_y[i] >= High - radius)
				ball_vy[i] = -ball_vy[i];
		}
	}
	EndBatchDraw();
	closegraph;
	return 0;
}