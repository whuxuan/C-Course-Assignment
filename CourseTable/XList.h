//
//	�б���
//  �б������ڹ��õĹ����࣬���������ά��һ����Ŀ��
//
//	Created by ������ ������@ 2015-12
//


#ifndef _XLIST_H_
#define _XLIST_H_

#include "XCourse.h"

typedef XCourse Item; // �����б��е���Ŀ����

class XList
{
public:
	const static int LISTSIZE = 100; // �б������
	string table[7][13][3];//�γ̱����飨7ָÿ�ܵ�7�죬13ָÿ����13�ڣ�3ָÿ�ڱ���е�������Ϣ��
private:
	Item m_entries[LISTSIZE]; // �þ�̬���鱣����Ŀ
	int m_items; // ��ǰ��Ŀ������

public:
	// ���캯��
	XList();

	// ��ʼ��
	void Initialize();

	// �ж��б�ǰ�Ƿ�Ϊ��
	bool IsEmpty();

	// �ж��б�ǰ�Ƿ�����
	bool IsFull();

	// ��ȡ�б�����Ŀ��ʵ������
	int ItemCount();

	// ���б��β�����һ����Ŀ
	bool AppendItem(Item &item);

	//��ʾ��̬�����е�ȫ��Ԫ��
	void ShowItems();

	// ���ݸ�����˳���idx����ȡ�б��е���Ŀ����ֵ��item��������true
	// ���idx�����򷵻�false
	bool FetchItem(int idx, Item &item);

	// ���ݸ�����˳���idx��ɾ���б��е���Ŀ��������true
	// ���idx�����򷵻�false
	bool DeleteItem(int idx);

	// ���ݸ�����˳���idx����item��ֵ���б��е���Ŀ��������true
	// ���idx�����򷵻�false
	bool UpdateItem(int idx, const Item &item);

	// ��һ�������������б��е�ÿ����Ŀ
	void Traverse(void (*pFun)(Item &item));

	//�����б���ѡ�޺ͱ��޵�ƽ��ֵ�������
	void Calculate_Average();

	//�����б������޿γ̵�ƽ��ѧ�ּ�
	void Calculate_GPA();

	//��д���
	void FillTable(int day, int num);

};

#endif
