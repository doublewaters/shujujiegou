// test4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string.h>
using namespace std;
#define maxvex 100


void main(int argc, char* argv[])
{
 int vex ,arc;  //城市数目，弧长
 cout<<"输入数目，弧长："<<endl;
 cin>>vex>>arc;

 int i,j;
 int cost[maxvex][maxvex];

 for(i = 0; i < vex; i++)  //初始化
  for(j = 0; j < arc; j++)
   cost[i][j]=0;

 cout<<"输入顶点和边："<<endl;
 int a,b,c;
 for(i = 0; i < vex; i++){  //建立
   
   cin>>a>>b>>c;
   cost[a][b] = c;
 }
   
 cout<<"邻接矩阵："<<endl;
 for(i = 0; i < vex; i++){  //输出
  for(j = 0; j < arc; j++){
   printf("%3d",cost[i][j]);
   }
  printf("\n");
 }

}

 
