//
// ����FLTK 1.1.10��ͼ�����Ĳ��Գ���
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
//
// ��ͬѧ���ڴ��ļ��������Լ��Ķ����ű����롣

#include "XWindow.h"
#include<iostream>
using namespace std;
int main(int argc, char **argv) {
	// ��������ʾ����ʽ�Ļ�ͼ����
	XInteractiveWindow window(700, 400, "���ȹ���");
	window.show(argc, argv);
	// �ȴ���������һ������ť�������ʵ����ͣ����
	window.WaitForClick();
	//̫��������������
	XSun sun(XPoint(100, 300), 30);
	sun.SetLineColor(XColor::XCOLOR_RED);
	window.Add(sun);
	for (unsigned i = 1;i < 25;i++) {
		sun.MoveRightUp();
		window.Delay(50);
	}
	for (unsigned i = 1;i < 45;i++) {
		sun.MoveRightDown();
		window.Delay(50);
	}
	XWater water1(XPoint(0, 100));
	water1.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(water1);
	for (unsigned i = 0;i < 90;i++) {
		water1.MoveRight();
		window.Delay(50);
	}
	//������Ϸ����
	window.Delay(100);
	
	XCircle circle1 = XCircle(XPoint(300, 200), 50);
	circle1.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(circle1);
	XSun sun2 = XSun(XPoint(300, 200), 55);
	sun2.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(sun2);
	window.Add(window.diamond);

	



	// ���������е�ͼ��
	window.WaitForClick();
	window.Clear();

	window.WaitForClick();
}
