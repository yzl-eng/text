#include<stdio.h>
#include<graphics.h>
#include<conio.h>
//��Ϸ����ߴ�
#define High 480
#define Width 640
int main(void)
{
	initgraph(Width,High);//��ʼ������

	float ball_x, ball_y;//С������
	float ball_vx, ball_vy;//С���ٶ�
	float radius;//С��뾶

	ball_x = Width / 2;
	ball_y = High / 2;
	ball_vx = 1;
	ball_vy = 1;
	radius = 20;
	for (int x = 100; x < 540; x += 20)
	{
		//���ƻ��ߣ���ɫ���Բ
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(ball_x,ball_y,radius);
		//��ʱ
		Sleep(200);
		//���ƺ��ߣ���ɫ���Բ
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(ball_x,ball_y,radius);
	}
	closegraph;
	return 0;
}