//
//	��ѧ���γ���ϢС����
//
//	Created by �ż������������������� @ 2015-12
//


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XStudent.h"


// ��ʾ��ѧ���γ���ϢС���ֳ���Ĺ��ܲ˵�������ȡ�û��Ĺ���ѡ��
int menu()
{
	system("cls");
	std::cout<<"====================\n";
	std::cout<<"   ��ѧ���γ���ϢС����\n";
	std::cout<<"      ver  1.5\n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]��ȡѧ����Ϣ\n";
	std::cout<<"[2]����������ѧ����Ϣ\n";
	std::cout<<"[3]��ʾ���޿γ���Ϣ\n";
	std::cout<<"[4]������޿γ���Ϣ\n";
	std::cout<<"[5]�������޿γ���Ϣ\n";
	std::cout<<"[6]ɾ���γ���Ϣ\n";
	std::cout<<"[7]�޸Ŀγ���Ϣ\n";
	std::cout<<"[8]��ʾѧ���ɼ���Ϣ\n";
	std::cout<<"[9]��ʾѧ���ۺ�������Ϣ\n";
	std::cout<<"[10]��ʾ�α�����󻯴��ڲ鿴��\n";
	std::cout<<"[0]�˳�\n";
	std::cout<<"====================\n";
	
	std::cout<<"��ѡ��Ҫִ�еĹ��ܣ�\n";
	int choice;
	std::cin>>choice;
	while (choice<0 || choice>10)
	{
		std::cout<<"�������������ѡ��Ҫִ�еĹ��ܣ�1~10��������0�˳���\n";
		std::cin>>choice;
	}

	return choice;
}

// ��ѧ���γ���ϢС���ֳ�������غ���
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
				//����ʹ�øó���ʱ����F�̴���txt�ļ������Ѵ��ڸ��ļ�������ж�ȡ
				MyStudent.Load();
				printf("�Ѷ���txt�ļ�����\n");
				break;
			}
		case 2:
			{   
				//�����������д��txt�ļ���
				MyStudent.Save();
				break;
			}
		case 3:
			{
				//չʾ�ļ�����������
				MyStudent.ShowAllCourse();
				break;
			}
		case 4:
			{   
				 //���ݵ�����
				 XCourse course;
				 printf("�����������Ϣ:\n ");
				 printf("��ţ��γ����ƣ��γ����,�ڿν�ʦ,�Ͽ�ʱ�䣨����,��1234567��ʾ)\n");
				 printf("�Ͽε���ʼ��������ֹ����,�Ͽεص�,�γ�ѧ��,�γ̳ɼ�\n");
				 printf("�γ̿�ʼ������,�γ�ѧʱ����������\n");
			     int id; // ��ţ�����Ψһ��ʶһ���γ̣�
	             char title[TITLESIZE]; // �γ�����
	             int kind; // �γ����
	             char teacher[DESCRSIZE];//�ڿν�ʦ
	             int day;//�Ͽ�ʱ�䣨����,��1234567��ʾ��
	             int begintime;//�Ͽε���ʼ����
			     int endtime;//�Ͽε���ֹ����
	             char place[DESCRSIZE];//�Ͽεص�
	             int credit;//�γ�ѧ��
	             int grade;//�γ̳ɼ�
	             int beginweek;//�γ̿�ʼ������
	             int period;//�γ�ѧʱ����������
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
				//��������Ŀγ̱�Ų�ѯͼƬ�γ���Ϣ
				printf("�����������ѯ�Ŀγ̱��\n");
				XCourse course;
				int id;
				cin>>id;
				MyStudent.SearchCourse(id,course);
				break;
			}
		case 6:
			{   
				//���ݱ��ɾ���γ�
				printf("����������ɾ���Ŀγ̱��\n");
				int id;
				cin>>id;
				MyStudent.DeleteCourse(id);
				break;
			}
		case 7:
			{
				//�޸Ŀγ���Ϣ
				XCourse course;
				printf("�����������޸ĵĿγ̱��\n");
				int num;
				cin>>num;
				if(MyStudent.Coursenumber()<num)
				{
					printf("����������ı��\n");
					break;
				}
			     printf("�����������Ϣ:\n ");
				 printf("��ţ��γ����ƣ��γ����(��������0��ѡ������1��,�ڿν�ʦ,�Ͽ�ʱ�䣨����,��1234567��ʾ)\n");
				 printf("�Ͽε���ʼ��������ֹ����,�Ͽεص�,�γ�ѧ��,�γ̳ɼ�\n");
				 printf("�γ̿�ʼ������,�γ�ѧʱ����������\n");
				 int id; // ��ţ�����Ψһ��ʶһ���γ̣�
	             char title[TITLESIZE]; // �γ�����
	             int kind; // �γ����
	             char teacher[DESCRSIZE];//�ڿν�ʦ
	             int day;//�Ͽ�ʱ�䣨����,��1234567��ʾ��
	             int begintime, endtime;//�Ͽε���ʼ��������ֹ����
	             char place[DESCRSIZE];//�Ͽεص�
	             int credit;//�γ�ѧ��
	             int grade;//�γ̳ɼ�
	             int beginweek;//�γ̿�ʼ������
	             int period;//�γ�ѧʱ����������
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
			  //��ʾƽ���ɼ�
				MyStudent.AnalysisGrade();
				break;			
			}
		case 9:
			{		  
			  //��ʾGPA
				MyStudent.GPA_Calculate();
			    break;			
			}
		case 10:
		{
			MyStudent.ShowTable();
			break;
		}
		case 0: std::cout<<"���˳�\n"; break;
		}

		system("pause");
	} while (choice != 0);
}