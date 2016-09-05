//
//	��ѧ���γ���ϢС����
//	�γ���
//
//	Created by ������ @ 2015-12
//

#include <iostream>

using namespace std;

#ifndef _XCOURSE_H_
#define _XCOURSE_H_

#define TITLESIZE 256 // ��ű�������鳤��
#define DESCRSIZE 1024 // ���˵�������鳤��


// �γ�
class XCourse
{
private:
    int m_id; // ��ţ�����Ψһ��ʶһ���γ̣�
	int m_kind; // �γ����(����Ϊ0��ѡ��Ϊ1)
	int m_credit;//�γ�ѧ��
	int m_grade;//�γ̳ɼ�
	int m_beginweek;//�γ̿�ʼ������
	int m_period;//�γ�ѧʱ����������

	// �����ں�����Ӳ�������
public:
	int m_day;//�Ͽ�ʱ�䣨����,��1234567��ʾ��
	int m_begintime, m_endtime;//�Ͽε���ʼ��������ֹ����
	char m_title[TITLESIZE]; // �γ�����
	char m_teacher[DESCRSIZE];//�ڿν�ʦ
	char m_place[DESCRSIZE];//�Ͽεص�
	//�γ̶�����Ϣ
	void Course_infor(int id,char *title,int kind,char *teacher,int day,int begintime,int endtime,char *place,int credit,int beginweek,int period);
	//��ʾ�γ���Ϣ
	void ShowCourse();
	//¼��ɼ�
	void AddGrade(int grade);
	//����γ�
	bool Load(istream &is);
	//д��γ�
	void Save(ostream &os);
	//�ı���
	void ChangeID(int reduce);
	//���ؿγ����࣬������ú���
	int CourseKind();
	//���ؿγ̳ɼ���������ú���
	int CourseGrade();
	//���ؿγ�ѧ�֣�������ú���
	int CourseCredit();
	//���ؿγ�GPA��������ú���
	float CourseGPA();
};

#endif