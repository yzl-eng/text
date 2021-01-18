#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int main(void)
{
	initgraph(640, 480);
	for (int x = 100; x < 540; x += 20)
	{
		//»æÖÆ»ÆÏß£¬ÂÌÉ«Ìî³äÔ²
		setcolor(YELLOW);
		setfillcolor(GREEN);
		fillcircle(x, 100, 20);
		//ÑÓÊ±
		Sleep(200);
		//»æÖÆºÚÏß£¬ºÚÉ«Ìî³äÔ²
		setcolor(BLACK);
		setfillcolor(BLACK);
		fillcircle(x, 100, 20);
	}
	closegraph;
	return 0;
}