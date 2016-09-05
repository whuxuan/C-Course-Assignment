//
// 基于FLTK 1.1.10的图形类库基础版
// 窗口类
// XWindow(绘图窗口)
//   XInteractiveWindow（带一个按钮的交互窗口）
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
//
// 如果不增加新功能，就不必修改此文件中的代码。

#ifndef _XWINDOW_H_
#define _XWINDOW_H_

#include <vector>
using namespace std;

#include <windows.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "XGraph.h"

// 绘图窗口
//   可以添加图形对象，并绘制这些图形对象
class XWindow : public Fl_Window
{
private:
	vector<XShape*> shapes; // 形状集

public:
	XWindow(int w, int h, char* c=0) : Fl_Window(w, h, c) {}

protected:
	// 重写父类中的对应函数，完成图形的绘制
	void draw();

public:
	// 添加形状，注意参数类型是引用
	void Add(XShape& shape);
	// 清空窗口
	void Clear();
};


#include <FL/Fl_Button.H>

// 交互式绘图窗口
//   包括一个按钮，为窗口提供简单的交互功能
class XInteractiveWindow : public XWindow
{
private:
	const static int wallnum = 9;
	Fl_Button button; // “下一步”按钮
	Fl_Button buttonup;//“向上”按钮
	Fl_Button buttondown;//“向下”按钮
	Fl_Button buttonleft;//“向左”按钮
	Fl_Button buttonright;//“向右”按钮
	Fl_Button buttonget;//“获取宝石”按钮
	Fl_Button buttonsave;//拯救公主
	bool buttonClicked; // “下一步”按钮是否被单击
	XPrince prince;//王子
	XPrincess princess;//公主
	XWall walls[wallnum];//墙壁
	XCircle cc;//圆圈

public:
	XPolygon diamond;//宝石
	//初始化图形窗口
	XInteractiveWindow(int w, int h, char* c = 0) : XWindow(w, h, c),
		button(w - 70, 0, 70, 20, "下一步"), buttonClicked(false), buttonsave(w-70,200,90,20,"拯救公主"), buttonget(w - 70, 180, 90, 20, "获取宝石"), buttonup(w - 105, 100, 70, 20, "向上"), buttondown(w - 105, 140, 70, 20, "向下"),
		buttonleft(w - 140, 120, 70, 20, "向左"), buttonright(w - 70, 120, 70, 20, "向右"), prince(XPoint(60, 350)), princess(XPoint(600, 60)), diamond(XPoint(300, 200), 10, 8),cc(XPoint(600,60),10)
	{   
		//将对象添加进窗口中
		walls[0] = XWall(XPoint(0,300),200,30);
		walls[1] = XWall(XPoint(50, 55), 100, 215);
		walls[2] = XWall(XPoint(150, 215), 85, 55);
		walls[3] = XWall(XPoint(200, 0), 30, 180);
		walls[4] = XWall(XPoint(235, 270), 165, 145);
		walls[5] = XWall(XPoint(230, 0), 270, 90);
		walls[6] = XWall(XPoint(375, 125), 25, 145);
		walls[7] = XWall(XPoint(440, 90), 60, 250);
		walls[8] = XWall(XPoint(550, 150), 45, 250);	
		for (unsigned i = 0;i < 9;i++) {
			walls[i].SetLineColor(XColor::XCOLOR_GREEN);
			Add(walls[i]);
		}
		diamond.SetLineColor(XColor::XCOLOR_BLUE);
		prince.SetLineColor(XColor::XCOLOR_BLACK);
		Add(prince);Add(princess);

		// 设置响应单击“下一步”按钮事件的回调函数
		button.callback(CbNext);
		//设置方向按钮事件的回调函数
		buttonup.callback(CMoveUp);
		buttondown.callback(CMoveDown);
		buttonleft.callback(CMoveLeft);
		buttonright.callback(CMoveRight);
		buttonget.callback(CGet);
		buttonsave.callback(CSave);
	}

	// 在单击“下一步”按钮之前保持窗口（暂停），并强制重画窗口
	void WaitForClick();

	// 延时ms毫秒
	void Delay(unsigned ms);

	// 对单击“下一步”按钮事件的处理
	void Next()
	{
		buttonClicked = true;
	}

	//判断障碍物
	bool UpIsClear();
	bool RightIsClear();
	bool LeftIsClear();
	bool DownIsClear();

	//对单击“方向”按钮事件的处理
	void CCMoveUp();
	void CCMoveDown();
	void CCMoveRight();
	void CCMoveLeft();

	//对单击“获取宝石”按钮事件的处理
	void CCGet();

	//对单击“拯救公主”按钮事件的处理
	void CCSave();
	
	// “下一步”按钮事件的回调函数
	static void CbNext(Fl_Widget* pWidget, void*);

	//方向按钮事件的回调函数
	static void CMoveUp(Fl_Widget* pWidget, void*);
	static void CMoveDown(Fl_Widget* pWidget, void*);
	static void CMoveRight(Fl_Widget* pWidget, void*);
	static void CMoveLeft(Fl_Widget* pWidget, void*);
	
	//“获取宝石”事件的回调函数
	static void CGet(Fl_Widget* pWidget, void*);

	//“拯救公主”事件的回掉函数
	static void CSave(Fl_Widget* pWidget, void*);
};

#endif