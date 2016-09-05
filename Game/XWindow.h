//
// ����FLTK 1.1.10��ͼ����������
// ������
// XWindow(��ͼ����)
//   XInteractiveWindow����һ����ť�Ľ������ڣ�
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
//
// ����������¹��ܣ��Ͳ����޸Ĵ��ļ��еĴ��롣

#ifndef _XWINDOW_H_
#define _XWINDOW_H_

#include <vector>
using namespace std;

#include <windows.h>

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include "XGraph.h"

// ��ͼ����
//   �������ͼ�ζ��󣬲�������Щͼ�ζ���
class XWindow : public Fl_Window
{
private:
	vector<XShape*> shapes; // ��״��

public:
	XWindow(int w, int h, char* c=0) : Fl_Window(w, h, c) {}

protected:
	// ��д�����еĶ�Ӧ���������ͼ�εĻ���
	void draw();

public:
	// �����״��ע���������������
	void Add(XShape& shape);
	// ��մ���
	void Clear();
};


#include <FL/Fl_Button.H>

// ����ʽ��ͼ����
//   ����һ����ť��Ϊ�����ṩ�򵥵Ľ�������
class XInteractiveWindow : public XWindow
{
private:
	const static int wallnum = 9;
	Fl_Button button; // ����һ������ť
	Fl_Button buttonup;//�����ϡ���ť
	Fl_Button buttondown;//�����¡���ť
	Fl_Button buttonleft;//�����󡱰�ť
	Fl_Button buttonright;//�����ҡ���ť
	Fl_Button buttonget;//����ȡ��ʯ����ť
	Fl_Button buttonsave;//���ȹ���
	bool buttonClicked; // ����һ������ť�Ƿ񱻵���
	XPrince prince;//����
	XPrincess princess;//����
	XWall walls[wallnum];//ǽ��
	XCircle cc;//ԲȦ

public:
	XPolygon diamond;//��ʯ
	//��ʼ��ͼ�δ���
	XInteractiveWindow(int w, int h, char* c = 0) : XWindow(w, h, c),
		button(w - 70, 0, 70, 20, "��һ��"), buttonClicked(false), buttonsave(w-70,200,90,20,"���ȹ���"), buttonget(w - 70, 180, 90, 20, "��ȡ��ʯ"), buttonup(w - 105, 100, 70, 20, "����"), buttondown(w - 105, 140, 70, 20, "����"),
		buttonleft(w - 140, 120, 70, 20, "����"), buttonright(w - 70, 120, 70, 20, "����"), prince(XPoint(60, 350)), princess(XPoint(600, 60)), diamond(XPoint(300, 200), 10, 8),cc(XPoint(600,60),10)
	{   
		//��������ӽ�������
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

		// ������Ӧ��������һ������ť�¼��Ļص�����
		button.callback(CbNext);
		//���÷���ť�¼��Ļص�����
		buttonup.callback(CMoveUp);
		buttondown.callback(CMoveDown);
		buttonleft.callback(CMoveLeft);
		buttonright.callback(CMoveRight);
		buttonget.callback(CGet);
		buttonsave.callback(CSave);
	}

	// �ڵ�������һ������ť֮ǰ���ִ��ڣ���ͣ������ǿ���ػ�����
	void WaitForClick();

	// ��ʱms����
	void Delay(unsigned ms);

	// �Ե�������һ������ť�¼��Ĵ���
	void Next()
	{
		buttonClicked = true;
	}

	//�ж��ϰ���
	bool UpIsClear();
	bool RightIsClear();
	bool LeftIsClear();
	bool DownIsClear();

	//�Ե��������򡱰�ť�¼��Ĵ���
	void CCMoveUp();
	void CCMoveDown();
	void CCMoveRight();
	void CCMoveLeft();

	//�Ե�������ȡ��ʯ����ť�¼��Ĵ���
	void CCGet();

	//�Ե��������ȹ�������ť�¼��Ĵ���
	void CCSave();
	
	// ����һ������ť�¼��Ļص�����
	static void CbNext(Fl_Widget* pWidget, void*);

	//����ť�¼��Ļص�����
	static void CMoveUp(Fl_Widget* pWidget, void*);
	static void CMoveDown(Fl_Widget* pWidget, void*);
	static void CMoveRight(Fl_Widget* pWidget, void*);
	static void CMoveLeft(Fl_Widget* pWidget, void*);
	
	//����ȡ��ʯ���¼��Ļص�����
	static void CGet(Fl_Widget* pWidget, void*);

	//�����ȹ������¼��Ļص�����
	static void CSave(Fl_Widget* pWidget, void*);
};

#endif