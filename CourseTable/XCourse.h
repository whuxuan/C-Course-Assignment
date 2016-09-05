//
//	大学生课程信息小帮手
//	课程类
//
//	Created by 王振轩 @ 2015-12
//

#include <iostream>

using namespace std;

#ifndef _XCOURSE_H_
#define _XCOURSE_H_

#define TITLESIZE 256 // 存放标题的数组长度
#define DESCRSIZE 1024 // 存放说明的数组长度


// 课程
class XCourse
{
private:
    int m_id; // 编号（用来唯一标识一个课程）
	int m_kind; // 课程类别(必修为0，选修为1)
	int m_credit;//课程学分
	int m_grade;//课程成绩
	int m_beginweek;//课程开始的周数
	int m_period;//课程学时（总周数）

	// 可以在后面添加操作函数
public:
	int m_day;//上课时间（星期,用1234567表示）
	int m_begintime, m_endtime;//上课的起始节数和终止节数
	char m_title[TITLESIZE]; // 课程名称
	char m_teacher[DESCRSIZE];//授课教师
	char m_place[DESCRSIZE];//上课地点
	//课程读入信息
	void Course_infor(int id,char *title,int kind,char *teacher,int day,int begintime,int endtime,char *place,int credit,int beginweek,int period);
	//显示课程信息
	void ShowCourse();
	//录入成绩
	void AddGrade(int grade);
	//读入课程
	bool Load(istream &is);
	//写入课程
	void Save(ostream &os);
	//改变编号
	void ChangeID(int reduce);
	//返回课程种类，方便调用函数
	int CourseKind();
	//返回课程成绩，方便调用函数
	int CourseGrade();
	//返回课程学分，方便调用函数
	int CourseCredit();
	//返回课程GPA，方便调用函数
	float CourseGPA();
};

#endif