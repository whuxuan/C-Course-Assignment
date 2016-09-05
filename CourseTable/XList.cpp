//
//	�б���
//
//	Created by ������&������ @ 2015-12


#include "XList.h"
#include <stdio.h>

// ���캯��
XList::XList()
{
	Initialize();
}

// ��ʼ��
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

// �ж��б�ǰ�Ƿ�Ϊ��
bool XList::IsEmpty()
{
	if(m_items>0)
	  return true;
	else
	  return false;
}

// �ж��б�ǰ�Ƿ�����
bool XList::IsFull()
{
   if(m_items>=LISTSIZE)
	   return true;
   else 
	   return false;
}

// ��ȡ�б�����Ŀ��ʵ������
int XList::ItemCount()
{
	return m_items;
}

// ���б��β�����һ����Ŀ
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
	  printf("���󣺿γ��б����������ʧ�ܣ�\n");
	  return false;
	}
}

//��ʾ��̬�����е�ȫ��Ԫ��
void XList::ShowItems()
{
	  for(int i=0;i<ItemCount();i++)
	  {
		  m_entries[i].ShowCourse();
	  }
}

// ���ݸ�����˳���idx����ȡ�б��е���Ŀ����ֵ��item��������true
// ���idx�����򷵻�false
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
		printf("������Ŀ����Ƿ���ȷ\n");
		return false;
	}
}

// ���ݸ�����˳���idx��ɾ���б��е���Ŀ��������true
// ���idx�����򷵻�false
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
		printf("������Ŀ����Ƿ���ȷ\n");
		return false;
	}
}

// ���ݸ�����˳���idx����item��ֵ���б��е���Ŀ��������true
// ���idx�����򷵻�false
bool XList::UpdateItem(int idx, const Item &item)
{
	if(idx<=ItemCount())
	{ 
	  m_entries[idx-1]=item;
      return true;
	}
	else 
	{  
		printf("������Ŀ����Ƿ���ȷ\n");
		return false;
	}

}

// ��һ�������������б��е�ÿ����Ŀ
void XList::Traverse(void (*pFun)(Item &item))
{
	for(int i=0;i<ItemCount();i++)
	{
	    pFun(m_entries[i]);
	}
}

//�����б���ѡ�޺ͱ��޵�ƽ��ֵ�������
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
		printf("��δ��ϰ�κα��޿γ̣�\n");
	    printf("\n");
	}
	else
	  {
		required_average=assist_sumGrade/assist_sumCredit;
	    printf("���޿γ��б��޿�ƽ����Ϊ��%d\n",required_average);
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
	   printf("��δ��ϰ�κ�ѡ�޿γ̣�\n");
	   printf("\n");
	}
	else
	  {
		 optional_average=assist_sumGrade2/assist_sumCredit2;
	     printf("���޿γ���ѡ�޿�ƽ����Ϊ��%d\n",optional_average);
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
	  printf("��δ��ϰ�κογ̣�\n");
	  return;
	}
	float average_GPA=assist_sumGPA/assist_sumCredit;
	printf("���޿γ�ƽ��ѧ�ּ�Ϊ:%.2f\n",average_GPA);
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