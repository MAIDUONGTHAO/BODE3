#include<iostream>
#include<fstream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;
struct NguoiChoi{
	string Ten;
	int diem;
};
struct de{
	string cauhoi;
	string phuongan1,phuongan2,phuongan3,dapan;
};
vector <NguoiChoi> DanhSach;
vector <de> DsDe;
void Nhap()
{
	NguoiChoi n1;
	fflush(stdin);
	cout<<" nhap ten nguoi choi " ; getline(cin,n1.Ten);
	n1.diem=0;
	DanhSach.push_back(n1);
}
void LamBai(de de1,int &diem)
{
	string ans;
	cout<<de1.cauhoi<<endl;
	cout<<de1.phuongan1<<endl;
	cout<<de1.phuongan2<<endl;
	cout<<de1.phuongan3<<endl;
	cout<<"nhap dap an ban chon "; cin>>ans;
	fflush(stdin);
	if(ans==de1.dapan) 
		{
			diem+=2;
			cout<<" ban da chon dung "<<endl;
		}
	else	{
			diem+=0;
				cout<<"chon sai "<<endl;
				cout<<"dap an la"<<"\t"<<de1.dapan<<endl;
		}
}
void DocDe()
{
	int diem=0;
	for(int i=0;i<DsDe.size();i++)
	{
		LamBai(DsDe[i],diem);
	}
	DanhSach[DanhSach.size()-1].diem=diem;
	cout<<"------------ket thuc phan choi-------------- "<<endl;
}
void LayDe(ifstream &f)
{
	string s;
							de c1;
							int sl;
							getline(f,s); sl=atoi(s.c_str());
							for(int i=0;i<sl;i++)
							{
								getline(f,s);  c1.cauhoi=s;
								getline(f,s); c1.phuongan1=s;
								getline(f,s); c1.phuongan2=s;
								getline(f,s); c1.phuongan3=s;
								getline(f,s); c1.dapan=s;
								DsDe.push_back(c1);		
							}
							DsDe.resize(sl);
}
void XuatDiem( NguoiChoi ng1)
{
	cout<<ng1.Ten<<"\t"<<ng1.diem<<endl;
}
void XuatDanhSach()
{
	for(int i=0;i<DanhSach.size();i++)
		XuatDiem(DanhSach[i]);
}
void Menu()
{
	cout<<" hay lua chon "<<endl; 
	cout<<"1 ---- bat dau choi---- "<<endl;
	cout<<"2 ----xem diem danh sach nguoi choi---- "<<endl;
	cout<<"3 ----ket thuc----"<<endl;
}
int main()
{
	Menu();
		int n;
		cout<<" moi ban chon lua "; cin>>n;
		while(n!=3) 
	{
			if(n==1) 
				{
					system("cls");
					Nhap();
					int de;
					cout<<"lua chon bo de "; cin>>de;
					switch (de)
					{
					
						case 1:
							{	
								ifstream f("de1.txt");
								LayDe(f);
								DocDe();
								break;
							}
						case 2:
							{
								ifstream g("de2.txt");	
								LayDe(g);
								DocDe();
								break;	
							}
					}
				}
			else 
				{
					if(n==2)
					{
						cout<<"lua chon xuat danh sach "<<endl;	
						XuatDanhSach();
						getch();
					}
					else
						{
							cout<<"ket thuc chuong trinh ";
							break;
						}
				}
			system("cls");
			Menu();
			cout<<"moi ban lua chon "; cin>>n;
				
		}
}
