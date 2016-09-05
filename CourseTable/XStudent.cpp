//
//	大学生课程信息小帮手
//	学生类
//
//	Created by 刘仁雄 @ 2015-12
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

//以下为类XStudent的成员函数

int XStudent::Coursenumber()
{
	return m_course_list.ItemCount();
}

void XStudent::AddNewCourse(XCourse course)
{
	if(m_course_list.AppendItem(course))
		printf("成功添加课程！\n");
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
   // 打开学生信息文件文件，读出数据，并添加到学生信息列表中
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
		cout<<"数据已保存到文件"<<StudentCourse_file<<"中。"<<endl;
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
	cout << setw(6) << "节数" << setw(6) << "|"
		<< setw(12) << "星期一" << setw(6) << "|" << setw(12) << "星期二" << setw(6) << "|"
		<< setw(12) << "星期三" << setw(6) << "|" << setw(12) << "星期四" << setw(6) << "|"
		<< setw(12) << "星期五" << setw(6) << "|"
		<< setw(12) << "星期六" << setw(6) << "|" << setw(12) << "星期日" << setw(6) << "|" << endl;
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