//
//	大学生课程信息小帮手
//	学生类
//
//	Created by 刘仁雄 @ 2015-12
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
	XList m_course_list; // 学生课程信息里的全部课程信息

	// 在后面添加学生类的操作函数
public:
	//学生所修的课程数目
	int Coursenumber();
	//新添加课程
	void AddNewCourse(XCourse course);
	//显示全部课程
	void ShowAllCourse();
	//查找课程记录
	void SearchCourse(int idx,Item &item);
	//删除课程记录
	void DeleteCourse(int idx);
	//修改课程记录
	void ModifyCourse(int idx, const Item &item);
	//读入存储的学生信息
	void Load();
	//写入修改的学生信息
	void Save();
	//对必修课和选修课成绩进行统计分析
	void AnalysisGrade();
	//计算已修课程的累计学分绩
	void GPA_Calculate();
	//遍历生成课程表中的课程();
	void ShowTable();
};

#endif