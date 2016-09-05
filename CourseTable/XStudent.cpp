//
//	��ѧ���γ���ϢС����
//	ѧ����
//
//	Created by ������ @ 2015-12
//

#include "XStudent.h"
#include <stdio.h>
#include <fstream>
#include <string>
#include<iomanip>
using namespace std;

fstream StudentCourse_fs;
string StudentCourse_file("F:\\StudentCourse.txt");

void SaveCourse(XCourse &course)
{
	course.Save(StudentCourse_fs);
}

//����Ϊ��XStudent�ĳ�Ա����

int XStudent::Coursenumber()
{
	return m_course_list.ItemCount();
}

void XStudent::AddNewCourse(XCourse course)
{
	if(m_course_list.AppendItem(course))
		printf("�ɹ���ӿγ̣�\n");
}

void XStudent::ShowAllCourse()
{
	m_course_list.ShowItems();
}

void XStudent::SearchCourse(int idx,Item &item)
{
	m_course_list.FetchItem(idx,item);
}

void XStudent::DeleteCourse(int idx)
{
	m_course_list.DeleteItem(idx);
}

void XStudent::ModifyCourse(int idx, const Item &item)
{
	m_course_list.UpdateItem(idx,item);
}

void XStudent::Load()
{
	XCourse course;
   // ��ѧ����Ϣ�ļ��ļ����������ݣ�����ӵ�ѧ����Ϣ�б���
	StudentCourse_fs.open(StudentCourse_file, ios::in|ios::app);
    if (StudentCourse_fs)
     {
        StudentCourse_fs.seekp(0, ios::beg);
		
        while (!StudentCourse_fs.eof())
       {   
           if (!course.Load(StudentCourse_fs))
          {
			   
	         break;
           }
           m_course_list.AppendItem(course);
	    }
		
      StudentCourse_fs.close();
	  }
}
void XStudent::Save()
{   
    StudentCourse_fs.open(StudentCourse_file, ios::out);
	if (StudentCourse_fs)
	{
		m_course_list.Traverse(SaveCourse);
		StudentCourse_fs.close();
		cout<<"�����ѱ��浽�ļ�"<<StudentCourse_file<<"�С�"<<endl;
	}
}
void XStudent::AnalysisGrade()
{
	m_course_list.Calculate_Average();
}
void XStudent::GPA_Calculate()
{
	m_course_list.Calculate_GPA();
}

void XStudent::ShowTable()
{
	for (int i = 0;i < 7;i++) {
		for (int j = 0;j < 13;j++) {
			m_course_list.FillTable(i, j);
		}
	}
	cout << left;
	cout << setw(6) << "����" << setw(6) << "|"
		<< setw(12) << "����һ" << setw(6) << "|" << setw(12) << "���ڶ�" << setw(6) << "|"
		<< setw(12) << "������" << setw(6) << "|" << setw(12) << "������" << setw(6) << "|"
		<< setw(12) << "������" << setw(6) << "|"
		<< setw(12) << "������" << setw(6) << "|" << setw(12) << "������" << setw(6) << "|" << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int j = 0;j < 13;j++) {
		cout << setw(6) << " " << setw(6) << "|" << setw(12) << m_course_list.table[0][j][0] << setw(6) << "|" << setw(12) << m_course_list.table[1][j][0] << setw(6) << "|"
			<< setw(12) << m_course_list.table[2][j][0] << setw(6) << "|" << setw(12) << m_course_list.table[3][j][0] << setw(6) << "|"
			<< setw(12) << m_course_list.table[4][j][0] << setw(6) << "|"
			<< setw(12) << m_course_list.table[5][j][0] << setw(6) << "|" << setw(12) << m_course_list.table[6][j][0] << setw(6) << "|" << endl;
		cout << setw(6) << j + 1 << setw(6) << "|" << setw(12) << m_course_list.table[0][j][1] << setw(6) << "|" << setw(12) << m_course_list.table[1][j][1] << setw(6) << "|"
			<< setw(12) << m_course_list.table[2][j][1] << setw(6) << "|" << setw(12) << m_course_list.table[3][j][1] << setw(6) << "|"
			<< setw(12) << m_course_list.table[4][j][1] << setw(6) << "|"
			<< setw(12) << m_course_list.table[5][j][1] << setw(6) << "|" << setw(12) << m_course_list.table[6][j][1] << setw(6) << "|" << endl;
		cout << setw(6) << " " << setw(6) << "|" << setw(12) << m_course_list.table[0][j][2] << setw(6) << "|" << setw(12) << m_course_list.table[1][j][2] << setw(6) << "|"
			<< setw(12) << m_course_list.table[2][j][2] << setw(6) << "|" << setw(12) << m_course_list.table[3][j][2] << setw(6) << "|"
			<< setw(12) << m_course_list.table[4][j][2] << setw(6) << "|"
			<< setw(12) << m_course_list.table[5][j][2] << setw(6) << "|" << setw(12) << m_course_list.table[6][j][2] << setw(6) << "|" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}