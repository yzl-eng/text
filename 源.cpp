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

	int secondLength,minuteLength,hourLength;                          
	secondLength = Width / 5;                 //秒钟的长度
	minuteLength = Width / 6;                 //分钟长度
	hourLength = Width / 10;                  //时钟长度

	int secondEnd_x = 0, secondEnd_y = 0,
		minuteEnd_x = 0, minuteEnd_y = 0,
		hourEnd_x = 0, hourEnd_y = 0;         //秒钟，分钟，时钟的终点坐标

	secondEnd_x = secondEnd_x + secondLength;
	secondEnd_y = center_y;
	minuteEnd_x = minuteEnd_x + minuteLength;
	minuteEnd_y = center_y;
	hourEnd_x = hourEnd_x + hourLength;
	hourEnd_x = center_y;

	double secondAngle = 0,minuteAngle=0,hourAngle=0;    //秒钟对应的转动角度
	SYSTEMTIME ti;            //定义变量储存系统时间
	BeginBatchDraw();
	while (1)
	{
		GetLocalTime(&ti);
		secondAngle = ti.wSecond * 2 * PI / 60;
		minuteAngle = ti.wMinute * 2 * PI / 60;
		hourAngle = ti.wHour * 2 * PI / 60;

		secondEnd_x = center_x + secondLength * sin(secondAngle);
		secondEnd_y = center_y - secondLength * cos(secondAngle);
		minuteEnd_x = center_x + minuteLength * sin(minuteAngle);
		minuteEnd_y = center_y - minuteLength * cos(minuteAngle);
		hourEnd_x = center_x + hourLength * sin(hourAngle);
		hourEnd_y = center_y - hourLength * cos(hourAngle);
		//画秒钟
		setlinestyle(PS_SOLID, 2);
		setcolor(WHITE);
		line(center_x, center_y, secondEnd_x, secondEnd_y);
		setlinestyle(PS_SOLID, 5);
		setcolor(BLUE);
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);
		setlinestyle(PS_SOLID, 8);
		setcolor(RED);
		line(center_x, center_y, hourEnd_x, hourEnd_y);
		Sleep(1000);
		FlushBatchDraw();
		//隐藏前一帧的秒钟
		setcolor(BLACK);
		line(center_x, center_y, secondEnd_x, secondEnd_y);
		line(center_x, center_y, minuteEnd_x, minuteEnd_y);
		line(center_x, center_y, hourEnd_x, hourEnd_y);
	}
	EndBatchDraw();

	_getch();
	closegraph();
	return 0;
}