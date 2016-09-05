//
// 基于FLTK 1.1.10的图形类库基础版
// 窗口类的实现
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
//
// 如果不增加新功能，就不必修改此文件中的代码。

#include "XWindow.h"

void XWindow::Add(XShape& shape)
{
	shapes.push_back(&shape);
}

void XWindow::Clear()
{
	shapes.clear();
}

void XWindow::draw()
{
	Fl_Window::draw();

	for (int i=0; i<shapes.size(); i++)
	{
		shapes[i]->Draw();
	}
}

void XInteractiveWindow::WaitForClick()
{
	while (!buttonClicked) Fl::wait();
	buttonClicked = false;
	Fl::redraw();
}

void XInteractiveWindow::Delay(unsigned ms)
{
	Fl::wait();
	Sleep(ms);
	Fl::redraw();
}

void XInteractiveWindow::CbNext(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->Next();
		}
	}
}

//判断障碍物
bool XInteractiveWindow::UpIsClear()
{
	bool x, y;
	for (unsigned i = 0;i < 9;i++) {
		x = (prince.center.xx > walls[i].x1&&prince.center.xx < walls[i].x2);
		y = ((prince.center.yy - 12) > walls[i].y1 && (prince.center.yy - 12) < walls[i].y2);
		if (x&&y) 
			return false;
	}
	return true;
}


bool XInteractiveWindow::RightIsClear()
{
	bool x, y;
	for (unsigned i = 0;i < 9;i++) {
		bool x = ((prince.center.xx + 7) > walls[i].x1 && (prince.center.xx + 7) < walls[i].x2);
		bool y = (prince.center.yy > walls[i].y1 && prince.center.yy < walls[i].y2);
		if (x&&y)
			return false;
	}
	return true;
}

bool XInteractiveWindow::LeftIsClear()
{
	bool x, y;
	for (unsigned i = 0;i < 9;i++) {
		bool x = ((prince.center.xx - 7) > walls[i].x1 && (prince.center.xx - 7) < walls[i].x2);
		bool y = (prince.center.yy > walls[i].y1 && prince.center.yy < walls[i].y2);
		if (x&&y)
			return false;
	}
	return true;
}

bool XInteractiveWindow::DownIsClear()
{
	bool x, y;
	for (unsigned i = 0;i < 9;i++) {
		bool x = (prince.center.xx > walls[i].x1&&prince.center.xx < walls[i].x2);
		bool y = ((prince.center.yy + 11) > walls[i].y1 && (prince.center.yy + 11) < walls[i].y2);
		if (x&&y)
			return false;
	}
	return true;
}

//对单击“方向”按钮事件的处理
void XInteractiveWindow::CCMoveUp()
{
	if (UpIsClear()) {
		buttonClicked = true;
		prince.MoveUp();
		WaitForClick();
	}
	buttonClicked = false;
	WaitForClick();
}

void XInteractiveWindow::CCMoveDown()
{
	if (DownIsClear()) {
		buttonClicked = true;
		prince.MoveDown();
		WaitForClick();
	}
	buttonClicked = false;
	WaitForClick();
}

void XInteractiveWindow::CCMoveRight()
{
	if (RightIsClear()) {
		buttonClicked = true;
		prince.MoveRight();
		WaitForClick();
	}
	buttonClicked = false;
	WaitForClick();
}

void XInteractiveWindow::CCMoveLeft()
{
	if (LeftIsClear()) {
		buttonClicked = true;
		prince.MoveLeft();
		WaitForClick();
	}
	buttonClicked = false;
	WaitForClick();
}

//对单击“获取宝石”按钮事件的处理
void XInteractiveWindow::CCGet()
{
	buttonClicked = true;
	int a = abs(prince.center.xx - diamond.center.xx);
	int b = abs(prince.center.yy - diamond.center.yy);
	if (a < 10 && b < 15) {
		diamond.ChangeSize(0);
		diamond.SetLineColor(XColor::XCOLOR_WHITE);
	}
	WaitForClick();
	buttonClicked = false;
	WaitForClick();
}

void XInteractiveWindow::CCSave()
{
	buttonClicked = true;
	int a = abs(prince.center.xx - princess.head.xx);
	int b = abs(prince.center.yy - (princess.head.yy + 7));
	if (a < 10 && b < 15) {
		Add(cc);
		for (unsigned i = 1;i < 10;i++) {
			cc.ChangeSize(i);
			Delay(100);
		}
		WaitForClick();
		buttonClicked = false;
		WaitForClick();
	}
}

void XInteractiveWindow::CMoveUp(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->CCMoveUp();
		}
	}
}

void XInteractiveWindow::CMoveDown(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->CCMoveDown();
		}
	}
}

void XInteractiveWindow::CMoveRight(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->CCMoveRight();
		}
	}
}

void XInteractiveWindow::CMoveLeft(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->CCMoveLeft();
		}
	}
}

void XInteractiveWindow::CGet(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->CCGet();
		}
	}
}

void XInteractiveWindow::CSave(Fl_Widget* pWidget, void*)
{
	if (pWidget)
	{
		void* pWnd = pWidget->window();
		if (pWnd)
		{
			((XInteractiveWindow*)pWnd)->CCSave();
		}
	}
}