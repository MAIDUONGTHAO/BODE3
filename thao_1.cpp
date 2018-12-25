#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
using namespace std;
ifstream fi("input.txt");
struct NGAYTHANG{
		int day;
		int  month;
		int year;
};
int CheckYear(NGAYTHANG x)
{
	if(x.year%400==0||(x.year%4==0&&x.year%100!=0))
		return 1;
	return 0;
}
void Create(NGAYTHANG &x,string &st)
{
	char c[4];
		fi>>st;
		fi.close();	
	c[0]= st[0];
	c[1] = st[1];
	x.day=atoi(c);
	c[0]= st[3];
	c[1] = st[4];
	x.month=atoi(c);
	c[0]= st[6];
	c[1] =st[7];
	c[2]= st[8];
	c[3] = st[9];
	x.year=atoi(c);
}
int main()
{
	NGAYTHANG x;
	string st;
	cout<<endl;
	Create(x,st);
	if(CheckYear(x)) cout<<"nam nhuan "<<endl;
	else	
		cout<<"nam khong nhuan "<<endl;
}
