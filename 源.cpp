#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
//游戏画面尺寸
#define High 480
#define Width 640
#define PI 3.1415926
int main(void)
{
	initgraph(Width, High);
	int center_x, center_y;
	center_x = Width / 2;
	center_y = High / 2;

	int secondLength;                          //秒钟的长度
	secondLength = Width / 5;                
	int secondEnd_x = 0, secondEnd_y = 0;     //秒钟的终点坐标
	secondEnd_x = secondEnd_x + secondLength;
	secondEnd_y = center_y;

	float secondAngle = 0;    //秒钟对应的转动角度
	SYSTEMTIME ti;            //定义变量储存系统时间
	BeginBatchDraw();
	while (1)
	{
		GetLocalTime(&ti);
		secondAngle = ti.wSecond* 2 * PI / 60;

		secondEnd_x = center_x + secondLength * sin(secondAngle);
		secondEnd_y = center_y - secondLength * cos(secondAngle);
		//画秒钟
		setlinestyle(PS_SOLID, 2);
		setcolor(WHITE);
		line(center_x, center_y, secondEnd_x, secondEnd_y);
		FlushBatchDraw();
		Sleep(1000);
		//隐藏前一帧的秒钟
		setcolor(BLACK);
		line(center_x, center_y, secondEnd_x, secondEnd_y);

	}
	EndBatchDraw();

	_getch();
	closegraph();
	return 0;
}