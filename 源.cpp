#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(void)
{
	initgraph(640, 480);
	for (int x = 100; x < 540; x += 20)
	{
		//���ƻ��ߣ���ɫ���Բ
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, 100, 20);
		//��ʱ
		Sleep(200);
		//���ƺ��ߣ���ɫ���Բ
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, 100, 20);
	}
	closegraph;
	return 0;
}