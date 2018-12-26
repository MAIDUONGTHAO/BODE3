#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void ghi(string);

int main(){

	ghi("output.dat");
	system("pause");
	return 0;
}

void ghi(string name){
	int mang[] = { 1, 2, 3, 4, 5 };
	ofstream ghi(name, ios::binary);
	cout << sizeof(mang);
	ghi.write((char *)mang, sizeof(mang));
	cout << sizeof(mang);
	//ghi.write((char *)&mang, sizeof(int) * 5);
	//	ghi.write((char *)&mang, sizeof(mang));
	cout << "Write data finished" << endl;
	ghi.close();
}
