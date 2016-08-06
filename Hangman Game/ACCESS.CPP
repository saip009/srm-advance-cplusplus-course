#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <iomanip.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
int main()
{       clrscr();
	ifstream indata;
	ofstream outdata;
	char  text[100];
	int row;
	cin>>row;
	outdata.open("Database.csv", ios::app);
//	outdata << text << endl;
//	outdata << "a,b,c" << endl;
	indata.open("Database.csv");
	char  cell1[100];
	for(int i=0;i<row;i++){
	indata>> cell1; }
	cout << cell1 << "\n\n";

	getchar();
   //	system("pause");
	return 0;
}
