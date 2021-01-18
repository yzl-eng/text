#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<time.h>
//��Ϸ����ߴ�
#define High 480
#define Width 640
#define N 8          //С����Ŀ
int main(void)
{
	srand((unsigned int)time(NULL));
	initgraph(Width, High);//��ʼ������

	float ball_x[N], ball_y[N];//С������
	float ball_vx[N], ball_vy[N];//С���ٶ�
	float radius=20;//С��뾶

	for (int i = 0; i < N; i++)
	{
		ball_x[i] = rand() % (Width / 2) + radius;
		ball_y[i] = rand() % (High / 2) + radius;

		ball_vx[i] = rand() % 3 + 1;
		ball_vy[i] = rand() % 3 + 1;
	}

	BeginBatchDraw();//��ʼ��������
	while(1)
	{
		//���ƻ��ߣ���ɫ���Բ
		for (int i = 0; i < N; i++)
		{
			setcolor(YELLOW);
			setfillcolor(GREEN);
			fillcircle(ball_x[i], ball_y[i], radius);
		}

		FlushBatchDraw();//
		//��ʱ
		Sleep(3);
		//���ƺ��ߣ���ɫ���Բ
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