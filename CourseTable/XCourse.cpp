//
//	��ѧ���γ���ϢС����
//	�γ���
//
//	Created by ������ @ 2015-12
//

#include "XCourse.h"
#include<stdio.h>
#include <string.h>

void XCourse::ShowCourse()
{
	printf("��ţ�%d\n�γ����ƣ�%s\n�γ����ࣺ%d\n�ον�ʦ��%s\n�Ͽ�ʱ�䣺����%d��%d��%d��\n",m_id,m_title,m_kind,m_teacher,m_day,m_begintime,m_endtime);
	printf("�Ͽεص㣺%s\n�γ�ѧ�֣�%d\nѧʱ��%d\n�γ̷�����%d\n",m_place,m_credit,m_period,m_grade);
	printf("\n");
}

void XCourse::Course_infor(int id, char *title, int kind, char *teacher, int day, int begintime, int endtime, char *place, int credit, int beginweek,int period)
{
	m_grade = 0;
	m_id=id;
	strcpy_s(m_title,title);
	m_kind=kind;
	strcpy_s(m_teacher,teacher);
	m_day = day;
	m_begintime = begintime;
	m_endtime = endtime;
	strcpy_s(m_place, place);
	m_credit = credit;
	m_beginweek = beginweek;
	m_period=period;
}


bool XCourse::Load(istream &is)
{
	is>>m_id;
	is.get();
	is.getline(m_title, TITLESIZE);
	is>>m_kind;
	is.get();
	is.getline(m_teacher, DESCRSIZE);
	is >> m_day;
	is.get();
	is >> m_begintime;
	is.get();
	is >> m_endtime;
	is.get();
	is.getline(m_place, DESCRSIZE);
	is >> m_credit;
	is.get();
	is >> m_beginweek;
	is.get();
	is >> m_period;
	is.get();
	is >> m_grade;
	is.get();
	if (m_title[0]==NULL)
		return false;

	return true;
}

void XCourse::Save(ostream &os)
{
	os<<m_id<<endl<<m_title<<endl<<m_kind<<endl<<m_teacher<<endl<<m_day<<endl<<m_begintime<<endl<<m_endtime<<endl<<m_place<<endl<<m_credit<<endl<<m_beginweek<<endl<<m_period<<endl<<m_grade<<endl;
}

void XCourse::AddGrade(int grade)
{
	m_grade = grade;
}

void XCourse::ChangeID(int reduce)
{
	m_id = m_id - reduce;
}

int XCourse::CourseKind()
{
	return m_kind;
}

int XCourse::CourseGrade()
{
   return m_grade;
}

int XCourse::CourseCredit()
{
	return m_credit;
}

float XCourse::CourseGPA()
{
	
	if(m_grade>=90)
		return 4.0;
	else if((m_grade<90)&&(m_grade>=85))
		return 3.7;
	else if((m_grade<85)&&(m_grade>=82))
		return 3.3;
	else if((m_grade<82)&&(m_grade>=77))
		return 3.0;
	else if((m_grade<77)&&(m_grade>=73))
		return 2.7;
	else if((m_grade<73)&&(m_grade>=70))
		return 2.4;
	else if((m_grade<70)&&(m_grade>=60))
		return 1.0;
	else
		return 0;

}