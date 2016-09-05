//
// 基于FLTK 1.1.10的图形类库的测试程序
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
//
// 请同学们在此文件中增加自己的动画脚本代码。

#include "XWindow.h"
#include<iostream>
using namespace std;
int main(int argc, char **argv) {
	// 创建并显示交互式的绘图窗口
	XInteractiveWindow window(700, 400, "拯救公主");
	window.show(argc, argv);
	// 等待单击“下一步”按钮后继续，实现暂停功能
	window.WaitForClick();
	//太阳的升起与落下
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
	//设置游戏场景
	window.Delay(100);
	
	XCircle circle1 = XCircle(XPoint(300, 200), 50);
	circle1.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(circle1);
	XSun sun2 = XSun(XPoint(300, 200), 55);
	sun2.SetLineColor(XColor::XCOLOR_BLUE);
	window.Add(sun2);
	window.Add(window.diamond);

	



	// 擦除窗口中的图形
	window.WaitForClick();
	window.Clear();

	window.WaitForClick();
}
