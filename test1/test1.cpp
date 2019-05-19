// test1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <iomanip>
#include <string>
#define MAXSIZE 10000  // 最大长度
#define OK 1	//无问题
#define ERROR 0		//有问题

//图书信息结构体
typedef struct
{
	string no;		//图书ISBN号
	string name;	//图书名称
	float price;	//图书价格
}Book;

//顺序表的表示
typedef struct 
{
	Book *elem;		//存储空间的基地址
	int length;		//图书表中的当前图书个数
}SqList;

//顺序表初始化
int InitList_Sq(SqList &L)
{
	//构造一个空的顺序表 L
	L.elem = new Book[MAXSIZE];
	if (!L.elem)
		return ERROR;
	L.length = 0 ;
	return OK;
}

//顺序表的排序
void Sort_Sq(SqList &L)
{
	//SqList L;
	int Cho;
	string string1 = "0";
	while(Cho!=22)
	{
		cout<<"请选择图书信息表的操作【1-10】："<<endl;
		cout<<"1.图书信息表的创建和输出"<<endl;
		cout<<"2.图书信息表的排序"<<endl;
		cout<<"3.图书信息表的修改"<<endl;
		cout<<"4.图书信息表的逆序存储"<<endl;
		cout<<"5.最贵图书的查找"<<endl;
		cout<<"6.最爱图书的查找"<<endl;
		cout<<"7.最佳位置的图书查找"<<endl;
		cout<<"8.新图书入库"<<endl;
		cout<<"9.旧图书出库"<<endl;
		cout<<"10.图书去重"<<endl;
		cin>>Cho;
		switch(Cho)
		{
			case 1:
			{
				int i = 0;
				if(InitList_Sq(L) == 1)
				{
					cout<<"图书信息表创建成功！"<<endl;
					cout<<"请输入图书书目信息："<<endl;
					while(1)
					{
						
						cin>>L.elem[i].no>>L.elem[i].name>>L.elem[i].price;
						if(L.elem[i].no == "0" && L.elem[i].name == string1 && L.elem[i].price == 0)
							break;
						i++;
						L.length = i;
					}
					//输出图书信息
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
				int n=L.length;                 //定义n为整数，书本总数l.length赋值给n
    			for(int i=1;i<=n-1;i++)         //趟数为书本总数减1
			    {
			        for(int j=0;j<=n-i;j++)     //交换次数为书本总数减趟数
			        {
            			if(L.elem[j].price<L.elem[j+1].price)//比较大小
            			{
                		Book B=L.elem[j];   //定义B为Book类型，用于暂时存书价格小的书的信息
                		L.elem[j]=L.elem[j+1];//书价高的放前面
                		L.elem[j+1]=B;      //后面的书从B里取回书价小的信息
            			}		
        			}
   				}
    			for(int k=0;k<L.length;k++)     //顺序输出每本书的信息
    			{
        			cout<<L.elem[k].no<<" "<<L.elem[k].name<<" "<<fixed<<setprecision(2)<<L.elem[k].price<<endl;
    			}
    			//return 0;
			}
		
			case 5:
				{
					
					float max=0;
					for(int i=0;i<L.length;i++)
					{
						if(L.elem[i].price > max)
							max=L.elem[i].price;
					}

					
					for(int k=0;k<L.length;k++)
					{
						if(L.elem[k].price == max)
						{
							cout<<L.elem[k].no<<" "<<L.elem[k].name<<" "<<fixed<<setprecision(2)<<L.elem[k].price<<endl;   
						}
					}
				}
		}
	}
}



int main(int argc, char* argv[])
{
	SqList L;
	InitList_Sq(L);
	Sort_Sq(L);
	return 0;
}

