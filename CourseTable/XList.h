//
//	列表类
//  列表类属于公用的工具类，用来保存和维护一组项目。
//
//	Created by 刘仁雄 王振轩@ 2015-12
//


#ifndef _XLIST_H_
#define _XLIST_H_

#include "XCourse.h"

typedef XCourse Item; // 定义列表中的项目类型

class XList
{
public:
	const static int LISTSIZE = 100; // 列表的容量
	string table[7][13][3];//课程表数组（7指每周的7天，13指每天有13节，3指每节表格中的三行信息）
private:
	Item m_entries[LISTSIZE]; // 用静态数组保存项目
	int m_items; // 当前项目的数量

public:
	// 构造函数
	XList();

	// 初始化
	void Initialize();

	// 判断列表当前是否为空
	bool IsEmpty();

	// 判断列表当前是否已满
	bool IsFull();

	// 获取列表中项目的实际数量
	int ItemCount();

	// 在列表的尾部添加一个项目
	bool AppendItem(Item &item);

	//显示静态数组中的全部元素
	void ShowItems();

	// 根据给定的顺序号idx，获取列表中的项目，赋值给item，并返回true
	// 如果idx有误，则返回false
	bool FetchItem(int idx, Item &item);

	// 根据给定的顺序号idx，删除列表中的项目，并返回true
	// 如果idx有误，则返回false
	bool DeleteItem(int idx);

	// 根据给定的顺序号idx，把item赋值给列表中的项目，并返回true
	// 如果idx有误，则返回false
	bool UpdateItem(int idx, const Item &item);

	// 把一个函数作用于列表中的每个项目
	void Traverse(void (*pFun)(Item &item));

	//计算列表里选修和必修的平均值，并输出
	void Calculate_Average();

	//计算列表里已修课程的平均学分绩
	void Calculate_GPA();

	//填写表格
	void FillTable(int day, int num);

};

#endif
