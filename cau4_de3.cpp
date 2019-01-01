#include<iostream>
#include<string.h>
#include<fstream>
#include<vector>
using namespace std;
fstream f;
struct Cap
{
	int Dinh;
	int Tong;
};
int n,bd,kt;
vector <Cap> DS;
Cap chon;
int k=0;
void DocFile(int a[10][10])
{
	f.open("dothi.txt", ios::in); //ios::in dung de mo file dothi.txt de doc
	f >> n;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			f >> a[i][j];
	f.close();
}
void XuatDoThi(int a[10][10])
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
			cout << endl;
	}	
}
int dachon[10]={100};
int KiemTra(int t)
{

	for(int i=0;i<k;i++)
		if(dachon[i]==t)
	return 0;
	return 1;
}
int KetThuc()
{
	for(int i=0;i<k;i++)
		if(dachon[i]==kt)
					return 0;
	return 1;
}
void TimDinhChon() // tim ra dinh moi chua duoc chon de chon 
{
	int min=1000;
	int vt;
	for(int i=0;i<DS.size();i++)
		if(DS[i].Tong<min&&KiemTra(i)) // kiem tra dinh da duoc chon chua 
			{
				vt=i;
				min=DS[i].Tong;
			}	
	chon=DS[vt];
	chon.Dinh=vt;
	k++;
	dachon[k]=vt;
}
void KhoiTao(int A[10][10])
{
	Cap c;
	chon.Dinh=bd;
	chon.Tong=0;
	dachon[k]=bd;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(A[i][j]==0)
				A[i][j]=1000;
	for(int i=0;i<n;i++)
		{
			c.Dinh=chon.Dinh;
			c.Tong=A[chon.Dinh][i];
			DS.push_back(c);	
		}
	cout<<"dinh da chon "<<dachon[k]<<endl;			
}
void XuatDS()
{
	for(int i=0;i<DS.size();i++)
		cout<<i<<"\t"<<DS[i].Dinh<<"\t"<<DS[i].Tong<<endl;
}
void XuLi(int A[10][10])
{
	while(KetThuc()==1)
	{
	for(int i=0;i<DS.size();i++)
		{
			if(DS[i].Tong>A[i][chon.Dinh]+chon.Tong&&KiemTra(i))
				{
					DS[i].Tong= A[i][chon.Dinh]+chon.Tong;
					DS[i].Dinh= chon.Dinh;
				}
		}
	TimDinhChon();			
	}	
}
int main()
{
	int A[10][10];
//	TaoMoi(A, n);
	DocFile(A);
	XuatDoThi(A);	
	cout<<" nhap dinh ma bat dau "; cin>>bd;
	cout<<" nhap dinh ket thuc "; cin>>kt;
	KhoiTao(A);
	XuatDS();
	XuLi(A);
	cout<<chon.Tong;
}
//void TaoMoi(int a[10][10], int &n)
//{
//	cout << "Nhap n : ";
//	cin >> n;
//	f.open("dothi.txt", ios::out); //ios::out dung de mo file dothi.txt de ghi
//	f << n << endl;
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			cout << "trong so tu " << i << " den " << j << " : ";
//			cin >> a[i][j];
//			f << a[i][j] << " ";
//		}
//		f << endl;
//	}
//	f.close();
//}
//
