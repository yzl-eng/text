#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
//��Ϸ����ߴ�
#define High 480
#define Width 640
#define PI 3.1415926
int main(void)
{
	initgraph(Width, High);
	int center_x, center_y;
	center_x = Width / 2;
	center_y = High / 2;

	int secondLength;                          //���ӵĳ���
	secondLength = Width / 5;                
	int secondEnd_x = 0, secondEnd_y = 0;     //���ӵ��յ�����
	secondEnd_x = secondEnd_x + secondLength;
	secondEnd_y = center_y;

	float secondAngle = 0;    //���Ӷ�Ӧ��ת���Ƕ�

	BeginBatchDraw();
	while (1)
	{
		secondEnd_x = center_x + secondLength * sin(secondAngle);
		secondEnd_y = center_y - secondLength * cos(secondAngle);
		//������
		setlinestyle(PS_SOLID, 2);
		setcolor(WHITE);
		line(center_x, center_y, secondEnd_x, secondEnd_y);
		FlushBatchDraw();
		Sleep(1000);
		//����ǰһ֡������
		setcolor(BLACK);
		line(center_x, center_y, secondEnd_x, secondEnd_y);

		secondAngle = secondAngle + 2 * PI / 60;
	}
	EndBatchDraw();

	_getch();
	closegraph();
	return 0;
}