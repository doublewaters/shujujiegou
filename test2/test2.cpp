// test2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<cstring>
#include<string>
#include<fstream>
using namespace std;

int Index(string S , string T , int pos)
{
	int i,j,SS,TT;

	 i = 0;
	 j = 0;
	 SS = S.size();
	 TT = T.size();
	while(i<= SS&&j<= TT)
	{
		if (S[i] == T[j])
		{
			++i;
			++j;
		}
		else
		{
			i = i-j+2;
			j = 1;
		}
	}
	if (j>TT-1)
		return i-TT-1;
	else 
		return 0 ;
}

int main()
{
	int pos = 0;
	string str1;
	string str2;
	while(cin>>str2>>str1)
    {
        if(str1=="0"&&str2=="0")break;
	    int result=Index(str2,str1,pos);
		cout<<result<<endl;
	
    }
    return 0;

}

