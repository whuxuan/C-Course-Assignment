//
// 基于FLTK 1.1.10的图形库基础版
// 图形类的实现
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
//
// 请同学们在此文件增加自定义图形类的实现代码。

#include "XGraph.h"
#include<math.h>

#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
#include <FL/fl_draw.h>

#define PI 3.1415926

void XShape::AddPoint(XPoint point)
{
	// 把点添加到点集
	points.push_back(point);
}

void XShape::SetPoint(int idx, XPoint point)
{
	// 修改点集中的指定点
	if (idx>=0 && idx<points.size())
	{
		points[idx] = point;
	}
}

void XShape::Draw()
{
	// 设置画笔的颜色
	fl_color(lineColor.ToInt());

	// 绘出图形
	DrawLines();

	// 恢复画笔的颜色
	XColor defaultColor;
	fl_color(defaultColor.ToInt());
}

void XShape::MoveDown()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].yy += 8;
}

void XShape::MoveUp()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].yy -= 8;
}

void XShape::MoveRight()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].xx += 8;
}

void XShape::MoveLeft()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].xx -= 8;
}

void XShape::MoveRightDown()
{
	for (unsigned idx = 0;idx < points.size();idx++) {
		points[idx].xx += 8;
		points[idx].yy += 8;
	}
}

void XShape::MoveRightUp()
{
	for (unsigned idx = 0;idx < points.size();idx++) {
		points[idx].xx += 8;
		points[idx].yy -= 8;
	}
}

XLine::XLine(XPoint p1, XPoint p2)
{
	// 把直线的两个点添加到点集中
	AddPoint(p1);
	AddPoint(p2);
}

void XLine::DrawLines()
{
	// 使用FLTK中的绘线函数画出直线
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
}

XTriangle::XTriangle(XPoint p1, XPoint p2, XPoint p3)
{
	//把三角形的三个点添加到点集中
	AddPoint(p1);
	AddPoint(p2);
	AddPoint(p3);
}

void XTriangle::DrawLines()
{
	//使用FLTK中的绘线函数画出直线
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
	fl_line(points[1].xx, points[1].yy, points[2].xx, points[2].yy);
	fl_line(points[2].xx, points[2].yy, points[0].xx, points[0].yy);
}

XRectangle::XRectangle(XPoint p, int l, int w)
{
	center = p;
	length = l;
	width = w;
	//根据中心点及长和宽确定四个顶点的位置并将其添加到点集中
	XPoint p1 = XPoint(p.xx - length / 2, p.yy + width / 2);
	XPoint p2 = XPoint(p.xx + length/2, p.yy+width/2);
	XPoint p3 = XPoint(p.xx-length/2, p.yy - width/2);
	XPoint p4 = XPoint(p.xx + length/2, p.yy - width/2);
	AddPoint(p1);
	AddPoint(p2);
	AddPoint(p3);
	AddPoint(p4);
}

void XRectangle::DrawLines()
{
	//使用FLTK中的绘线函数画出直线
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
	fl_line(points[1].xx, points[1].yy, points[3].xx, points[3].yy);
	fl_line(points[3].xx, points[3].yy, points[2].xx, points[2].yy);
	fl_line(points[2].xx, points[2].yy, points[0].xx, points[0].yy);
}

void XRectangle::ChangeSize(int n)
{
	length = length*n;
	width = width*n;
	points[0]= XPoint(center.xx - length / 2, center.yy + width / 2);
	points[1] = XPoint(center.xx + length / 2, center.yy + width / 2);
	points[2] = XPoint(center.xx - length / 2, center.yy - width / 2);
	points[3] = XPoint(center.xx + length / 2, center.yy - width / 2);
}

XCircle::XCircle(XPoint p1, int r)
{
	center = p1;
	//给半径赋值
	radius = r;
	AddPoint(center);
}

void XCircle::DrawLines()
{
	//使用FLTK中的函数画出圆
	fl_circle(points[0].xx, points[0].yy, radius);
}

void XCircle::ChangeSize(int n)
{
	radius = n*radius;
}

XPolygon::XPolygon(XPoint p, int l, int n)
{
	//根据中心点以及顶点数和边长确定每个顶点的位置
	center = p;
	length = l;
	num = n;
	XPoint vertex = XPoint(0, 0);
	for (int i = 0;i < n;i++) {
		vertex = XPoint(center.xx + length*cos(2 * i*PI / num), center.yy + length*sin(2 * i*PI / num));
		AddPoint(vertex);
	}
}

void XPolygon::DrawLines()
{
	//使用FLTK中的函数画多边形
	for (int i = 0;i < num - 1;i++) {
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
	}
	fl_line(points[num - 1].xx, points[num - 1].yy, points[0].xx, points[0].yy);
}

void XPolygon::ChangeSize(int n)
{
	length = length*n;
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx] = XPoint(center.xx + length*cos(2 * idx*PI / num), center.yy + length*sin(2 * idx*PI / num));
}

XPrince::XPrince(XPoint p)
{
	//根据王子身体中心点的位置确定其身体各个点的位置
	center = p;
	AddPoint(center);
	body1 = XPoint(center.xx - 3, center.yy - 6);body2 = XPoint(center.xx + 3, center.yy - 6);body4 = XPoint(center.xx - 3, center.yy + 6);body3 = XPoint(center.xx + 3, center.yy + 6);
	head= XPoint(center.xx, center.yy - 9);
	arm1 = XPoint(center.xx - 7, center.yy);arm2 = XPoint(center.xx + 7, center.yy);
	leg1 = XPoint(center.xx - 5, center.yy + 11);leg2 = XPoint(center.xx + 5, center.yy + 11);
	AddPoint(body1);AddPoint(body2);AddPoint(body3);AddPoint(body4);AddPoint(head);AddPoint(arm1);AddPoint(arm2);AddPoint(leg1);AddPoint(leg2);

}

void XPrince::DrawLines()
{
	for (unsigned i = 1;i < 4;i++)
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
	fl_line(points[4].xx, points[4].yy, points[1].xx, points[1].yy);
	fl_circle(points[5].xx, points[5].yy, 4);
	fl_line(points[6].xx, points[6].yy, points[1].xx, points[1].yy);
	fl_line(points[7].xx, points[7].yy, points[2].xx, points[2].yy);
	fl_line(points[8].xx, points[8].yy, points[4].xx, points[4].yy);
	fl_line(points[9].xx, points[9].yy, points[3].xx, points[3].yy);
}

void XPrince::MoveDown()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].yy += 8;
	center = points[0];
}

void XPrince::MoveUp()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].yy -= 8;
	center = points[0];
}

void XPrince::MoveRight()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].xx += 8;
	center = points[0];
}

void XPrince::MoveLeft()
{
	for (unsigned idx = 0;idx < points.size();idx++)
		points[idx].xx -= 8;
	center = points[0];
}


XPrincess::XPrincess(XPoint p)
{
	//根据初始点确定公主身体各个点的位置并将其添加到点集中
	body1 = p;body2 = XPoint(body1.xx - 3, body1.yy + 12);body3 = XPoint(body1.xx + 3, body1.yy + 12);
	head = XPoint(body1.xx, body1.yy - 3);
	arm11 = XPoint(body1.xx - 5, body1.yy);arm12 = XPoint(body1.xx - 1, body1.yy + 5);arm21 = XPoint(body1.xx + 5, body1.yy);arm22 = XPoint(body1.xx + 1, body1.yy + 5);
	leg11 = XPoint(body2.xx + 1, body2.yy);leg12 = XPoint(leg11.xx, leg11.yy + 5);leg21 = XPoint(body3.xx - 1, body3.yy);leg22 = XPoint(leg21.xx, leg21.yy + 5);
	AddPoint(head);AddPoint(body1);AddPoint(body2);AddPoint(body3);
	AddPoint(arm11);AddPoint(arm12);AddPoint(arm21);AddPoint(arm22);AddPoint(leg11);AddPoint(leg12);AddPoint(leg21);AddPoint(leg22);
}

void XPrincess::DrawLines()
{
	//头
	fl_circle(points[0].xx, points[0].yy, 3);
	//身体
	fl_line(points[1].xx, points[1].yy, points[2].xx, points[2].yy);
	fl_line(points[2].xx, points[2].yy, points[3].xx, points[3].yy);
	fl_line(points[1].xx, points[1].yy, points[3].xx, points[3].yy);
	//胳臂和腿
	fl_line(points[4].xx, points[4].yy, points[5].xx, points[5].yy);
	fl_line(points[6].xx, points[6].yy, points[7].xx, points[7].yy);
	fl_line(points[8].xx, points[8].yy, points[9].xx, points[9].yy);
	fl_line(points[10].xx, points[10].yy, points[11].xx, points[11].yy);
}

XSun::XSun(XPoint p,int r)
{
	radius = r;
	center = p;
	AddPoint(center);
	for (unsigned i = 0;i < 12;i++) {
		p1 = XPoint(center.xx + radius*cos(i*PI / 6), center.yy + radius*sin(i*PI / 6));
		p2 = XPoint(center.xx + (radius + 20)*cos(i*PI/6), center.yy + (radius + 20)*sin(i*PI / 6));
		AddPoint(p1);AddPoint(p2);
	}
}

void XSun::DrawLines()
{
	fl_circle(points[0].xx, points[0].yy, radius);
	for (unsigned i = 1;i < 24;i += 2)
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
}

XWater::XWater(XPoint p)
{
	XPoint p1, p2, p3, p4,pl,pr;
	p1 = p;
	AddPoint(p1);
	for (unsigned i = 1;i <6 ;i++) {
		pl = XPoint(p1.xx + 12 * (2*i-1), p1.yy + 18);
		pr = XPoint(p1.xx + 24 * i, p1.yy);
		AddPoint(pl);AddPoint(pr);
	}
	p2 = XPoint(p1.xx - 15, p1.yy + 25);
	AddPoint(p2);
	for (unsigned i = 1;i <6;i++) {
		pl = XPoint(p2.xx + 12 * (2 * i - 1), p2.yy + 18);
		pr = XPoint(p2.xx + 24 * i, p2.yy);
		AddPoint(pl);AddPoint(pr);
	}
	p3 = XPoint(p1.xx, p2.yy + 25);
	AddPoint(p3);
	for (unsigned i = 1;i <6;i++) {
		pl = XPoint(p3.xx + 12 * (2 * i - 1), p3.yy + 18);
		pr = XPoint(p3.xx + 24 * i, p3.yy);
		AddPoint(pl);AddPoint(pr);
	}
	p4 = XPoint(p1.xx - 15, p3.yy + 25);
	AddPoint(p4);
	for (unsigned i = 1;i <6;i++) {
		pl = XPoint(p4.xx + 12 * (2 * i - 1), p4.yy + 18);
		pr = XPoint(p4.xx + 24 * i, p4.yy);
		AddPoint(pl);AddPoint(pr);
	}
}

void XWater::DrawLines()
{
	for (unsigned i = 0;i < 10;i++) {
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
	}
	for (unsigned i = 11;i < 21;i++) {
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
	}
	for (unsigned i = 22;i < 32;i++) {
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
	}
	for (unsigned i = 33;i < 43;i++) {
		fl_line(points[i].xx, points[i].yy, points[i + 1].xx, points[i + 1].yy);
	}
}

XWall::XWall(XPoint p, int l, int w)
{
	x1 = p.xx-8;x2 = p.xx + l+8;
	y1 = p.yy-8;y2 = p.yy + w+8;
	length = l;
	width = w;
	leftp = p;

}

void XWall::DrawLines()
{
	fl_rectf(leftp.xx,leftp.yy,length,width);
}