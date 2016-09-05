//
//	大学生课程信息小帮手
//
//	Created by 张家威，王振轩，刘仁雄 @ 2015-12
//


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XStudent.h"


// 显示大学生课程信息小帮手程序的功能菜单，并获取用户的功能选择
int menu()
{
	system("cls");
	std::cout<<"====================\n";
	std::cout<<"   大学生课程信息小帮手\n";
	std::cout<<"      ver  1.5\n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]读取学生信息\n";
	std::cout<<"[2]保存新输入学生信息\n";
	std::cout<<"[3]显示已修课程信息\n";
	std::cout<<"[4]添加新修课程信息\n";
	std::cout<<"[5]查找已修课程信息\n";
	std::cout<<"[6]删除课程信息\n";
	std::cout<<"[7]修改课程信息\n";
	std::cout<<"[8]显示学生成绩信息\n";
	std::cout<<"[9]显示学生综合评价信息\n";
	std::cout<<"[10]显示课表（请最大化窗口查看）\n";
	std::cout<<"[0]退出\n";
	std::cout<<"====================\n";
	
	std::cout<<"请选择要执行的功能：\n";
	int choice;
	std::cin>>choice;
	while (choice<0 || choice>10)
	{
		std::cout<<"输入错误。请重新选择要执行的功能（1~10），输入0退出：\n";
		std::cin>>choice;
	}

	return choice;
}

// 大学生课程信息小帮手程序的主控函数
void main()
{
	XStudent MyStudent;
	int choice;
	do
	{
		choice = menu();
		printf("\n");
		switch (choice)
		{
		case 1:
			{   
				//初次使用该程序时，在F盘创建txt文件；若已存在该文件，则进行读取
				MyStudent.Load();
				printf("已读入txt文件数据\n");
				break;
			}
		case 2:
			{   
				//将输入的数据写入txt文件中
				MyStudent.Save();
				break;
			}
		case 3:
			{
				//展示文件中所有数据
				MyStudent.ShowAllCourse();
				break;
			}
		case 4:
			{   
				 //数据的输入
				 XCourse course;
				 printf("请输入相关信息:\n ");
				 printf("编号，课程名称，课程类别,授课教师,上课时间（星期,用1234567表示)\n");
				 printf("上课的起始节数和终止节数,上课地点,课程学分,课程成绩\n");
				 printf("课程开始的周数,课程学时（总周数）\n");
			     int id; // 编号（用来唯一标识一个课程）
	             char title[TITLESIZE]; // 课程名称
	             int kind; // 课程类别
	             char teacher[DESCRSIZE];//授课教师
	             int day;//上课时间（星期,用1234567表示）
	             int begintime;//上课的起始节数
			     int endtime;//上课的终止节数
	             char place[DESCRSIZE];//上课地点
	             int credit;//课程学分
	             int grade;//课程成绩
	             int beginweek;//课程开始的周数
	             int period;//课程学时（总周数）
				 cin>>id;
				 cin>>title;
				 cin>>kind;
				 cin>>teacher;
				 cin>>day;
				 cin>>begintime;
				 cin>>endtime;
				 cin>>place;
				 cin>>credit;
				 cin>>grade;
				 cin>>beginweek;
				 cin>>period;
				 course.Course_infor(id,title,kind,teacher,day,begintime,endtime,place,credit,beginweek,period);
				 course.AddGrade(grade);
				 MyStudent.AddNewCourse(course);
				 break; 
			}
		case 5:
			{   
				//根据输入的课程编号查询图片课程信息
				printf("请输入你想查询的课程编号\n");
				XCourse course;
				int id;
				cin>>id;
				MyStudent.SearchCourse(id,course);
				break;
			}
		case 6:
			{   
				//根据编号删除课程
				printf("请输入你想删除的课程编号\n");
				int id;
				cin>>id;
				MyStudent.DeleteCourse(id);
				break;
			}
		case 7:
			{
				//修改课程信息
				XCourse course;
				printf("请输入你想修改的课程编号\n");
				int num;
				cin>>num;
				if(MyStudent.Coursenumber()<num)
				{
					printf("请检查你输入的编号\n");
					break;
				}
			     printf("请输入相关信息:\n ");
				 printf("编号，课程名称，课程类别(必修输入0，选修输入1）,授课教师,上课时间（星期,用1234567表示)\n");
				 printf("上课的起始节数和终止节数,上课地点,课程学分,课程成绩\n");
				 printf("课程开始的周数,课程学时（总周数）\n");
				 int id; // 编号（用来唯一标识一个课程）
	             char title[TITLESIZE]; // 课程名称
	             int kind; // 课程类别
	             char teacher[DESCRSIZE];//授课教师
	             int day;//上课时间（星期,用1234567表示）
	             int begintime, endtime;//上课的起始节数和终止节数
	             char place[DESCRSIZE];//上课地点
	             int credit;//课程学分
	             int grade;//课程成绩
	             int beginweek;//课程开始的周数
	             int period;//课程学时（总周数）
				 cin>>id;
				 cin>>title;
				 cin>>kind;
				 cin>>teacher;
				 cin>>day;
				 cin>>begintime;
				 cin>>endtime;
				 cin>>place;
				 cin>>credit;
				 cin>>grade;
				 cin>>beginweek;
				 cin>>period;
				course.Course_infor(id,title,kind,teacher,day,begintime,endtime,place,credit,beginweek,period);
				course.AddGrade(grade);
				MyStudent.ModifyCourse(id,course);
				break;
			}	
		case 8:
			{
			  //显示平均成绩
				MyStudent.AnalysisGrade();
				break;			
			}
		case 9:
			{		  
			  //显示GPA
				MyStudent.GPA_Calculate();
			    break;			
			}
		case 10:
		{
			MyStudent.ShowTable();
			break;
		}
		case 0: std::cout<<"已退出\n"; break;
		}

		system("pause");
	} while (choice != 0);
}