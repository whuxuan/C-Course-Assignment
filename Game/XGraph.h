//
// 基于FLTK 1.1.10的图形库基础版
// 图形类
// XPoint（点）
// XShape（形状）
// XLine（直线）
// XColor（颜色）
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
//
// 请同学们在此文件增加自己的图形类。

#ifndef _XGRAPH_H_
#define _XGRAPH_H_

#include <vector>
using namespace std;

#include "FL/fl_draw.h"


// 点
class XPoint
{
public:
	int xx, yy; // 点的坐标值

	XPoint(int x=0, int y=0) { xx=x; yy=y; }
};

// 颜色（重新包装FLTK中的颜色）
class XColor
{
private:
	Fl_Color cc; // 颜色值

public:
	enum XColorType
	{
		XCOLOR_RED = FL_RED,
		XCOLOR_GREEN = FL_GREEN,
		XCOLOR_BLUE = FL_BLUE,
		XCOLOR_YELLOW = FL_YELLOW,
		XCOLOR_WHITE = FL_WHITE,
		XCOLOR_BLACK = FL_BLACK
	};

	XColor(XColorType c=XCOLOR_RED) : cc(Fl_Color(c)) { }

	int ToInt() { return cc; }
};

// 形状
class XShape
{
private:
	XColor lineColor; // 线段颜色

protected:
	vector<XPoint> points; // 点集

public:
	XShape() : lineColor() {}

	// 添加点
	void AddPoint(XPoint point);
	// 修改某一点的值
	void SetPoint(int idx, XPoint point);
	// 设置线段颜色
	void SetLineColor(XColor c) { lineColor = c; }
	// 绘制图形（包括设置画笔颜色、绘出线段、恢复画笔的颜色）
	void Draw();
	//向上移动
	void MoveUp();
	//向下移动
	void MoveDown();
	//向右移动
	void MoveRight();
	//向左移动
	void MoveLeft();
	//右上移动
	void MoveRightUp();
	//右下移动
	void MoveRightDown();

protected:
	// 绘制某一种具体图形（只有具体的类才能实现）
	// 注意：这是一个纯虚函数，在每一个非抽象子类中必须重新声明和定义此函数！
	virtual void DrawLines() = 0;
};

// 直线
class XLine : public XShape
{
public:
	// 直线包括两个点
	XLine(XPoint p1=XPoint(0, 0), XPoint p2=XPoint(0, 0));
	// 绘出直线
	void DrawLines();
};

//三角形
class XTriangle :public XShape
{
public:
	//三角形包括三个点
	XTriangle(XPoint p1 = XPoint(0, 0), XPoint p2 = XPoint(0, 0), XPoint p3 = XPoint(0, 0));
	//绘出三角形
	void DrawLines();
};

//矩形
class XRectangle :public XShape
{
private:
	int length;//长
	int width; //宽
	XPoint center;//中心
public:
	//确定一个矩形需要三个要素：中心的位置、长和宽
	XRectangle(XPoint p = XPoint(0, 0), int l = 0, int w = 0);
	//绘出矩形
	void DrawLines();
	//改变大小
	void ChangeSize(int n);
};

//圆
class XCircle :public XShape
{
private:
	//圆的半径
	int radius;
	//圆的圆心
	XPoint center;
public:
	//确定一个圆需要两个要素：圆心和半径
	XCircle(XPoint p1 = XPoint(0, 0), int r = 0);
	//绘出图形
	void DrawLines();
	//改变大小
	void ChangeSize(int n);
};

//多边形
class XPolygon :public XShape
{
public:
	//确定正多边形需要三个要素：中心点的位置、边长、顶点数
	XPolygon(XPoint p=XPoint(0,0), int l=0, int n=0);
	//绘出多边形
	void DrawLines();
	//改变大小
	void ChangeSize(int n);
	XPoint center;//中心点(此处将其放在public中是为了在XWindow.h中便于访问宝石中心点坐标的位置）
private:
	int length;   //边长
	int num;      //顶点数
};

//人物：王子
class XPrince :public XShape
{
private:
	XPoint body1, body2, body3, body4;//王子身体的四个顶点
	XPoint head;//王子头部中心点
	XPoint arm1, arm2;//王子胳臂的顶点
	XPoint leg1, leg2;//王子腿的顶点
public:
	XPoint center;//王子身体中心点
	//确定王子的位置
	XPrince(XPoint p=XPoint(0,0));
	//绘出王子
	void DrawLines();
	//下面重新定义移动函数是在各个函数中增加了记录王子身体中心点位置的功能
	//向上移动
	void MoveUp();
	//向下移动
	void MoveDown();
	//向右移动
	void MoveRight();
	//向左移动
	void MoveLeft();

};

//人物：公主
class XPrincess :public XShape
{
private:
	XPoint body1, body2, body3;//公主身体的三个顶点
	XPoint arm11, arm12,arm21,arm22, leg11, leg12,leg21,leg22;//公主的胳臂和腿的八个顶点
public:
	XPoint head;//公主头部的中心点
	//确定公主的位置
	XPrincess(XPoint p=XPoint(0,0));
	//绘出公主
	void DrawLines();
};

//太阳
class XSun :public XShape
{
private:
	int radius;//太阳半径
	XPoint center;//太阳的中心点
	XPoint p1,p2;//太阳光芒射线的端点
public:
	//确定太阳的位置
	XSun(XPoint p=XPoint(0,0),int r=0);
	//绘出太阳
	void DrawLines();
};

//浪花
class XWater :public XShape
{
private:
	XPoint p;
public:
	//确定浪花的位置
	XWater(XPoint p=XPoint(0,0));
	//绘出浪花
	void DrawLines();
};

//墙壁
class XWall :public XShape
{
private:
	int length;//长
	int width;//宽
	XPoint leftp;//左顶点
public:
	int x1, x2;//墙壁横向的范围
	int y1, y2;//墙壁纵向的范围
	XWall(XPoint p=XPoint(0,0), int l=0, int w=0);//确定墙壁
	void DrawLines();//绘出墙壁

};
#endif