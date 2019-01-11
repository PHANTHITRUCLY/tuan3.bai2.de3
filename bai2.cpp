#include <iostream>
using namespace std;
#include <fstream>
void Nhap2MT(int a[][100], int b[][100], int n)
{
	cout<<endl<<"Nhap ma tran thu nhat: ";
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			{
				cout<<endl<<"a["<<i<<"]["<<j<<"]: ";
				cin>>a[i][j];
					}		
	}
	cout<<endl<<"Nhap ma tran thu hai: ";
	for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++){
				cout<<endl<<"b["<<i<<"]["<<j<<"]: ";
				cin>>b[i][j];
			}
		}
}

void Xuat2MT(int a[][100], int b[][100], int n){
	fstream ghi;
	ghi.open("input2.txt",ios::out);
	cout<<endl<<"Ma tran thu nhat: "<<endl;
	ghi<<endl<<"Ma tran thu nhat: "<<endl;	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<a[i][j]<<" ";
			ghi<<a[i][j]<<" ";	
		}
			cout<<endl;	
			ghi<<endl;		
	}
	
	cout<<endl<<"Ma tran thu hai: "<<endl;
	ghi<<endl<<"Ma tran thu hai: "<<endl;	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cout<<b[i][j]<<" ";
			ghi<<b[i][j]<<" ";	
		}
			cout<<endl;	
			ghi<<endl;		
	}	
	ghi.close();
	
}

void Xuat(int c[][100], int n){
	fstream tinh;
	tinh.open("output2.txt",ios::out | ios::app);
	for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				{
					cout<<c[i][j]<<" ";
					tinh<<c[i][j]<<" ";
				}
			cout<<endl;
			tinh<<endl;
		}
	tinh.close();
}


void Tinh(int a[][100], int b[][100], int c[][100], int n){
	fstream tinh;
	tinh.open("output2.txt",ios::out | ios::app);
	cout<<endl<<"Cong hai ma tran ";
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n; j++)
			c[i][j]= a[i][j] + b[i][j];
	cout<<endl<<"Ma tran sau khi cong la: "<<endl;
	tinh<<endl<<"Ma tran sau khi cong la: "<<endl;
	Xuat(c,n);
	cout<<endl<<"Tru hai ma tran ";
	for(int i = 0; i < n;i++)
		for(int j = 0; j < n; j++)
			c[i][j]= a[i][j] - b[i][j];
	cout<<endl<<"Ma tran sau khi Tru la: "<<endl;
	tinh<<endl<<"Ma tran sau khi Tru la: "<<endl;
	Xuat(c,n);
	cout<<endl<<"Nhan hai ma tran ";
	for(int i = 0; i < n ; i++)
		for(int k = 0;  k < n; k++){
			c[i][k] = 0;
			for(int j = 0; j < n; j++)
				c[i][k] += a[i][j] * b[j][k]; 
		}
	cout<<endl<<"Ma tran sau khi nhan la: "<<endl;
	tinh<<endl<<"Ma tran sau khi nhan la: "<<endl;
	Xuat(c,n);
	tinh.close();
}


int main(){
	int a[100][100], b[100][100], c[100][100] , n;
	fstream tinh;
	tinh.open("output2.txt",ios::out);
	tinh<"";
	tinh.close();
	cout<<endl<<"Nhap hang va cot cua ma tran: ";
	cin>>n;
	Nhap2MT(a,b,n);
	Xuat2MT(a,b,n);
	Tinh(a,b,c,n);
	system("pause");
}
