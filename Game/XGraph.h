//
// ����FLTK 1.1.10��ͼ�ο������
// ͼ����
// XPoint���㣩
// XShape����״��
// XLine��ֱ�ߣ�
// XColor����ɫ��
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
//
// ��ͬѧ���ڴ��ļ������Լ���ͼ���ࡣ

#ifndef _XGRAPH_H_
#define _XGRAPH_H_

#include <vector>
using namespace std;

#include "FL/fl_draw.h"


// ��
class XPoint
{
public:
	int xx, yy; // �������ֵ

	XPoint(int x=0, int y=0) { xx=x; yy=y; }
};

// ��ɫ�����°�װFLTK�е���ɫ��
class XColor
{
private:
	Fl_Color cc; // ��ɫֵ

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

// ��״
class XShape
{
private:
	XColor lineColor; // �߶���ɫ

protected:
	vector<XPoint> points; // �㼯

public:
	XShape() : lineColor() {}

	// ��ӵ�
	void AddPoint(XPoint point);
	// �޸�ĳһ���ֵ
	void SetPoint(int idx, XPoint point);
	// �����߶���ɫ
	void SetLineColor(XColor c) { lineColor = c; }
	// ����ͼ�Σ��������û�����ɫ������߶Ρ��ָ����ʵ���ɫ��
	void Draw();
	//�����ƶ�
	void MoveUp();
	//�����ƶ�
	void MoveDown();
	//�����ƶ�
	void MoveRight();
	//�����ƶ�
	void MoveLeft();
	//�����ƶ�
	void MoveRightUp();
	//�����ƶ�
	void MoveRightDown();

protected:
	// ����ĳһ�־���ͼ�Σ�ֻ�о���������ʵ�֣�
	// ע�⣺����һ�����麯������ÿһ���ǳ��������б������������Ͷ���˺�����
	virtual void DrawLines() = 0;
};

// ֱ��
class XLine : public XShape
{
public:
	// ֱ�߰���������
	XLine(XPoint p1=XPoint(0, 0), XPoint p2=XPoint(0, 0));
	// ���ֱ��
	void DrawLines();
};

//������
class XTriangle :public XShape
{
public:
	//�����ΰ���������
	XTriangle(XPoint p1 = XPoint(0, 0), XPoint p2 = XPoint(0, 0), XPoint p3 = XPoint(0, 0));
	//���������
	void DrawLines();
};

//����
class XRectangle :public XShape
{
private:
	int length;//��
	int width; //��
	XPoint center;//����
public:
	//ȷ��һ��������Ҫ����Ҫ�أ����ĵ�λ�á����Ϳ�
	XRectangle(XPoint p = XPoint(0, 0), int l = 0, int w = 0);
	//�������
	void DrawLines();
	//�ı��С
	void ChangeSize(int n);
};

//Բ
class XCircle :public XShape
{
private:
	//Բ�İ뾶
	int radius;
	//Բ��Բ��
	XPoint center;
public:
	//ȷ��һ��Բ��Ҫ����Ҫ�أ�Բ�ĺͰ뾶
	XCircle(XPoint p1 = XPoint(0, 0), int r = 0);
	//���ͼ��
	void DrawLines();
	//�ı��С
	void ChangeSize(int n);
};

//�����
class XPolygon :public XShape
{
public:
	//ȷ�����������Ҫ����Ҫ�أ����ĵ��λ�á��߳���������
	XPolygon(XPoint p=XPoint(0,0), int l=0, int n=0);
	//��������
	void DrawLines();
	//�ı��С
	void ChangeSize(int n);
	XPoint center;//���ĵ�(�˴��������public����Ϊ����XWindow.h�б��ڷ��ʱ�ʯ���ĵ������λ�ã�
private:
	int length;   //�߳�
	int num;      //������
};

//�������
class XPrince :public XShape
{
private:
	XPoint body1, body2, body3, body4;//����������ĸ�����
	XPoint head;//����ͷ�����ĵ�
	XPoint arm1, arm2;//���Ӹ�۵Ķ���
	XPoint leg1, leg2;//�����ȵĶ���
public:
	XPoint center;//�����������ĵ�
	//ȷ�����ӵ�λ��
	XPrince(XPoint p=XPoint(0,0));
	//�������
	void DrawLines();
	//�������¶����ƶ��������ڸ��������������˼�¼�����������ĵ�λ�õĹ���
	//�����ƶ�
	void MoveUp();
	//�����ƶ�
	void MoveDown();
	//�����ƶ�
	void MoveRight();
	//�����ƶ�
	void MoveLeft();

};

//�������
class XPrincess :public XShape
{
private:
	XPoint body1, body2, body3;//�����������������
	XPoint arm11, arm12,arm21,arm22, leg11, leg12,leg21,leg22;//�����ĸ�ۺ��ȵİ˸�����
public:
	XPoint head;//����ͷ�������ĵ�
	//ȷ��������λ��
	XPrincess(XPoint p=XPoint(0,0));
	//�������
	void DrawLines();
};

//̫��
class XSun :public XShape
{
private:
	int radius;//̫���뾶
	XPoint center;//̫�������ĵ�
	XPoint p1,p2;//̫����â���ߵĶ˵�
public:
	//ȷ��̫����λ��
	XSun(XPoint p=XPoint(0,0),int r=0);
	//���̫��
	void DrawLines();
};

//�˻�
class XWater :public XShape
{
private:
	XPoint p;
public:
	//ȷ���˻���λ��
	XWater(XPoint p=XPoint(0,0));
	//����˻�
	void DrawLines();
};

//ǽ��
class XWall :public XShape
{
private:
	int length;//��
	int width;//��
	XPoint leftp;//�󶥵�
public:
	int x1, x2;//ǽ�ں���ķ�Χ
	int y1, y2;//ǽ������ķ�Χ
	XWall(XPoint p=XPoint(0,0), int l=0, int w=0);//ȷ��ǽ��
	void DrawLines();//���ǽ��

};
#endif