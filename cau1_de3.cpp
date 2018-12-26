#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
using namespace std;
struct Contact {
		char ten[20];
		bool gioitinh;
		char sdt[11],email[20],diachi[50];
};
vector <Contact> DanhBa;
vector <Contact> DB;
void GhiFile()
{
	FILE *f = fopen("input.dat","wb");
	for(int i=0;i<DanhBa.size();i++)
		fwrite(&DanhBa[i],sizeof(Contact),1,f);
	fclose(f);
}
void Xuat(Contact c)
{
	cout<<c.ten<<"\t"<<c.gioitinh<<endl;
}
void Them() 
{
  char str1[]="Sample string";
	Contact ct;
	strcpy(ct.ten,str1);
	ct.gioitinh=0;
	strcpy(ct.email,str1);
	strcpy(ct.diachi,str1);
	strcpy(ct.sdt,str1);
	DanhBa.push_back(ct);
	strcpy(ct.ten,str1);
	ct.gioitinh=0;
	strcpy(ct.email,str1);
	strcpy(ct.diachi,str1);
	strcpy(ct.sdt,"035");
	DanhBa.push_back(ct);
	strcpy(ct.ten,"quan");
	ct.gioitinh=1;
	strcpy(ct.email,"quandtr@");
	strcpy(ct.diachi,str1);
	strcpy(ct.sdt,"033");
	DanhBa.push_back(ct);	
}
void DocFile()
{
	FILE *f = fopen("input.dat","rb");
	for(int i=0;i<DanhBa.size();i++)
		{
			Contact c;
			fread(&c,sizeof(c),1,f);
			DB.push_back(c);
		}
	fclose(f);
}
void LietKe()
{
	for(int i=0;i<DB.size();i++)
		{
			Xuat(DB[i]);
		}
}
void ChinhSua(char tt[])
{
	for(int i=0;i<DanhBa.size();i++)
		if(strcmp(DB[i].sdt,tt)==0)
			strcpy(DB[i].ten,"thaodeptrai");
}
void Xoa(char t[])
{
	for(int i=0;i<DB.size();i++)
		{
			if(strcmp(DB[i].ten,t)==0)
				DB.erase(DB.begin()+i);
		}
}
Contact TimKiem(char t[])
{
	for(int i=0;i<DB.size();i++)
			if(strcmp(DB[i].ten,t)==0)
				return DB[i];
}
int main ()
{
	Them();
	GhiFile();
	DocFile();
	ChinhSua("035");
	cout<<"sau khi chinh sua "<<endl;
		for(int i=0;i<DB.size();i++)
		{
			Xuat(DB[i]);
		}
	Xoa("thaodeptrai");
	cout<<"sau khi xoa "<<endl;
		for(int i=0;i<DB.size();i++)
		{
			Xuat(DB[i]);
		}
	Contact c=	TimKiem("quan");
	cout<<"hien thi Contact sau khi tiem kiem "<<endl;
	Xuat(c);	

}
