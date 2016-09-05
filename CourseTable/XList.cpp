//
//	列表类
//
//	Created by 刘仁雄&王振轩 @ 2015-12


#include "XList.h"
#include <stdio.h>

// 构造函数
XList::XList()
{
	Initialize();
}

// 初始化
void XList::Initialize()
{
	m_items = 0;
	for (unsigned i = 0;i < 7;i++) {
		for (unsigned j = 0;j < 13;j++) {
			for (unsigned k = 0;k < 3;k++) {
				table[i][j][k] = " ";
			}
		}
	}
}

// 判断列表当前是否为空
bool XList::IsEmpty()
{
	if(m_items>0)
	  return true;
	else
	  return false;
}

// 判断列表当前是否已满
bool XList::IsFull()
{
   if(m_items>=LISTSIZE)
	   return true;
   else 
	   return false;
}

// 获取列表中项目的实际数量
int XList::ItemCount()
{
	return m_items;
}

// 在列表的尾部添加一个项目
bool XList::AppendItem(Item &item)
{
	if(!IsFull())
	{
	  m_entries[m_items]=item;
	  m_items++;
	  return true;
	}
    else
    {
	  printf("错误：课程列表已满！添加失败！\n");
	  return false;
	}
}

//显示静态数组中的全部元素
void XList::ShowItems()
{
	  for(int i=0;i<ItemCount();i++)
	  {
		  m_entries[i].ShowCourse();
	  }
}

// 根据给定的顺序号idx，获取列表中的项目，赋值给item，并返回true
// 如果idx有误，则返回false
bool XList::FetchItem(int idx, Item &item)
{
	if(idx<=ItemCount())
	{ 
	  item=m_entries[idx-1];
	  item.ShowCourse();
      return true;
	}
	else 
	{  
		printf("请检查项目编号是否正确\n");
		return false;
	}
}

// 根据给定的顺序号idx，删除列表中的项目，并返回true
// 如果idx有误，则返回false
bool XList::DeleteItem(int idx)
{
	if(idx<=ItemCount())
	{ 
		for(int i=idx;i<=ItemCount()-1;i++)
		{ 
		   m_entries[i].ChangeID(1);
		   m_entries[i-1]=m_entries[i];
		}
		m_items--;

		for(int j=0;j<ItemCount();j++)
			m_entries[j].ShowCourse();
        return true;
	}
	else 
	{  
		printf("请检查项目编号是否正确\n");
		return false;
	}
}

// 根据给定的顺序号idx，把item赋值给列表中的项目，并返回true
// 如果idx有误，则返回false
bool XList::UpdateItem(int idx, const Item &item)
{
	if(idx<=ItemCount())
	{ 
	  m_entries[idx-1]=item;
      return true;
	}
	else 
	{  
		printf("请检查项目编号是否正确\n");
		return false;
	}

}

// 把一个函数作用于列表中的每个项目
void XList::Traverse(void (*pFun)(Item &item))
{
	for(int i=0;i<ItemCount();i++)
	{
	    pFun(m_entries[i]);
	}
}

//计算列表里选修和必修的平均值，并输出
void XList::Calculate_Average()
{
	int required_course[LISTSIZE];
	int required_credit[LISTSIZE];
	int optional_course[LISTSIZE];
	int optional_credit[LISTSIZE];
	int required_num=0;
	int optional_num=0;
	int required_average;
	int optional_average;
	for(int i=0;i<m_items;i++)
	{
		if(m_entries[i].CourseKind()==0)
		{
			required_course[required_num]=m_entries[i].CourseGrade();
			required_credit[required_num]=m_entries[i].CourseCredit();
			required_num++;
		}
		else
		{
			optional_course[optional_num]=m_entries[i].CourseGrade();
			optional_credit[optional_num]=m_entries[i].CourseCredit();
			optional_num++;
		}
	}

	int assist_sumGrade=0;
	int assist_sumCredit=0;
	for(int i=0;i<required_num;i++)
	{
		assist_sumGrade=required_course[i]*required_credit[i]+assist_sumGrade;
		assist_sumCredit=assist_sumCredit+required_credit[i];
	}
	if(assist_sumCredit==0)
	{
		printf("尚未修习任何必修课程！\n");
	    printf("\n");
	}
	else
	  {
		required_average=assist_sumGrade/assist_sumCredit;
	    printf("已修课程中必修课平均分为：%d\n",required_average);
	   }

	int assist_sumGrade2=0;
	int assist_sumCredit2=0;
	for(int i=0;i<optional_num;i++)
	{
		assist_sumGrade2=optional_course[i]*optional_credit[i]+assist_sumGrade2;
		assist_sumCredit2=assist_sumCredit2+optional_credit[i];
	}
	if(assist_sumCredit2==0)
	{
	   printf("尚未修习任何选修课程！\n");
	   printf("\n");
	}
	else
	  {
		 optional_average=assist_sumGrade2/assist_sumCredit2;
	     printf("已修课程中选修课平均分为：%d\n",optional_average);
	  }
}

void XList::Calculate_GPA()
{
	float assist_sumGPA=0;
	float assist_sumCredit=0;
	for(int i=0;i<m_items;i++)
	{
		assist_sumGPA=assist_sumGPA+m_entries[i].CourseGPA()*m_entries[i].CourseCredit();
		assist_sumCredit=assist_sumCredit+m_entries[i].CourseCredit();
	}
	if(assist_sumCredit==0)
	{
	  printf("尚未修习任何课程！\n");
	  return;
	}
	float average_GPA=assist_sumGPA/assist_sumCredit;
	printf("已修课程平均学分绩为:%.2f\n",average_GPA);
	return;
}

void XList::FillTable(int day, int num)
{
	for (unsigned n = 0;n < m_items;n++) {
		if ((m_entries[n].m_day - 1) == day && (m_entries[n].m_begintime - 1) <= num && (m_entries[n].m_endtime - 1) >= num) {
			table[day][num][0] = m_entries[n].m_title;
			table[day][num][1] = m_entries[n].m_teacher;
			table[day][num][2] = m_entries[n].m_place;
		}
	}
}