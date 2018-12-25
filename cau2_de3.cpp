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
int Month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
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
int CalculateDay(NGAYTHANG n)
{
	int order=0;
	for(int i=0;i<n.month;i++)
		order+=Month[i];
	order+=n.day;
	if(CheckYear(n)&&n.month>2)
		order++;
	return order;
}
void PrintRs(int n,int sum)
{
	int i=0;
	while(sum>Month[i])
	{
		sum=sum-Month[i];
		i++;
	}
	cout<<sum<<" day "<<i<<" month "<<n<<" year "<<endl;
}
void Add(NGAYTHANG n,int t)
{
	int sum=0;
	sum=CalculateDay(n)+t;
	if(CheckYear(n))
		{
			if(sum<=366)
				{
					Month[2]=29;
					PrintRs(n.year,sum);
					Month[2]=28;
				}	
			else
				PrintRs(n.year+1,sum-366);		
		}
	else
		{
			if(sum<=365)
				PrintRs(n.year,sum);
			else
				{
					n.year++;
					if(CheckYear(n))
						{
							Month[2]=29;
							PrintRs(n.year,sum-365);
							Month[2]=28;
						}
					else
						{
							PrintRs(n.year,sum-365);	
						}
				}
		}
}
void Sub(NGAYTHANG n,int t)
{
	int sum = CalculateDay(n);
	if(sum>t)
		{
			sum-=t;
			if(CheckYear(n))
				{
					Month[2]=29;
					PrintRs(n.year,sum);
					Month[2]=28;
				}
			else
				{
					PrintRs(n.year,sum);	
				}
		}
	else
		{
			if(CheckYear(n))
				{
					sum=sum-t+366;
					n.year--;
					PrintRs(n.year,sum);
				}
			else
				{
					sum=sum-t+365;
					n.year--;
					if(CheckYear(n))
						{
							Month[2]=29;
							PrintRs(n.year,sum);
							Month[2]=28;
						}
					else
						{
							PrintRs(n.year,sum);
						}
				}
		}
}
int main()
{
	fflush(stdin);
	NGAYTHANG x;
	string st;
	cout<<endl;
	Create(x,st);
	if(CheckYear(x)) cout<<"nam nhuan "<<endl;
	else	
		cout<<"nam khong nhuan "<<endl;
	cout<<CalculateDay(x)<<endl;
	Add(x,2);
	Sub(x,365);
}
