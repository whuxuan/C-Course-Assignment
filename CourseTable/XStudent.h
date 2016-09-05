//
//	��ѧ���γ���ϢС����
//	ѧ����
//
//	Created by ������ @ 2015-12
//

#ifndef _XSTUDENT_H_
#define _XSTUDENT_H_

#include "XList.h"
#include "XCourse.h"
#include <iostream>


using namespace std;

class XStudent
{
private:
	XList m_course_list; // ѧ���γ���Ϣ���ȫ���γ���Ϣ

	// �ں������ѧ����Ĳ�������
public:
	//ѧ�����޵Ŀγ���Ŀ
	int Coursenumber();
	//����ӿγ�
	void AddNewCourse(XCourse course);
	//��ʾȫ���γ�
	void ShowAllCourse();
	//���ҿγ̼�¼
	void SearchCourse(int idx,Item &item);
	//ɾ���γ̼�¼
	void DeleteCourse(int idx);
	//�޸Ŀγ̼�¼
	void ModifyCourse(int idx, const Item &item);
	//����洢��ѧ����Ϣ
	void Load();
	//д���޸ĵ�ѧ����Ϣ
	void Save();
	//�Ա��޿κ�ѡ�޿γɼ�����ͳ�Ʒ���
	void AnalysisGrade();
	//�������޿γ̵��ۼ�ѧ�ּ�
	void GPA_Calculate();
	//�������ɿγ̱��еĿγ�();
	void ShowTable();
};

#endif