// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#define MAXSIZE 10000  // ��󳤶�
#define OK 1	//������
#define ERROR 0		//������

//ͼ����Ϣ�ṹ��
typedef struct
{
	string no;		//ͼ��ISBN��
	string name;	//ͼ������
	float price;	//ͼ��۸�
}Book;

//˳���ı�ʾ
typedef struct 
{
	Book *elem;		//�洢�ռ�Ļ���ַ
	int length;		//ͼ����еĵ�ǰͼ�����
}SqList;

//˳����ʼ��
int InitList_Sq(SqList &L)
{
	//����һ���յ�˳��� L
	L.elem; new Book[MAXSIZE];
	if (!L.elem)
		return ERROR;
	L.length = 0 ;
	return OK;
}

//˳��������
void Sort_Sq(SqList &L)
{
	SqList L;
	int Cho = 0;
	string string1 = "0";
	while(Cho!=22)
	{
		cout<<"��ѡ��ͼ����Ϣ��Ĳ�����1-10����"<<endl;
		cout<<"1.ͼ����Ϣ��Ĵ��������"<<endl;
		cout<<"2.ͼ����Ϣ�������"<<endl;
		cout<<"3.ͼ����Ϣ����޸�"<<endl;
		cout<<"4.ͼ����Ϣ�������洢"<<endl;
		cout<<"5.���ͼ��Ĳ���"<<endl;
		cout<<"6.�ͼ��Ĳ���"<<endl;
		cout<<"7.���λ�õ�ͼ�����"<<endl;
		cout<<"8.��ͼ�����"<<endl;
		cout<<"9.��ͼ�����"<<endl;
		cout<<"10.ͼ��ȥ��"<<endl;
		cin>>Cho;
		switch(Cho)
		{
			case 1:
			{
				int i = 0;
				if(InitList_Sq(L) == 1)
				{
					cout<<"ͼ����Ϣ�����ɹ���"<<endl;
					cout<<"������ͼ����Ŀ��Ϣ��"<<endl;
					while(1)
					{
						cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;							
						if(L.elem[i].no == "0" && L.elem[i].name == string1 && L.elem[i].price ==0)
							break;
						i++;
						L.length = i;
					}
					//���ͼ����Ϣ
					cout<<L.length<<endl;
					for(int j = 0;j<L.length;j++)
					{
						cout.setf(ios_base::fixed);
						cout<<L.elem[j].no<<" "<<L.elem[j].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
					}
				}
			}
			case 2:
			{
				int n=L.length;                 //����nΪ�������鱾����l.length��ֵ��n
    			for(int i=1;i<=n-1;i++)         //����Ϊ�鱾������1
			    {
			        for(int j=0;j<=n-i;j++)     //��������Ϊ�鱾����������
			        {
            			if(L.elem[j].price<L.elem[j+1].price)//�Ƚϴ�С
            			{
                		Book B=L.elem[j];   //����BΪBook���ͣ�������ʱ����۸�С�������Ϣ
                		L.elem[j]=L.elem[j+1];//��۸ߵķ�ǰ��
                		L.elem[j+1]=B;      //��������B��ȡ�����С����Ϣ
            			}		
        			}
   				}
    			for(int i=0;i<L.length;i++)     //˳�����ÿ�������Ϣ
    			{
        			cout<<L.elem[i].no<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
    			}
    			//return 0;
			}
			case 3:
				{}
		}
	}
}


int main(){
	Sort_Sq();
	return 0;
}