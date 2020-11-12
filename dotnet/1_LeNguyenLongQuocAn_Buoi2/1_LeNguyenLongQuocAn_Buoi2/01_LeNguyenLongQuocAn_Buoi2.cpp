/*
STT:01
MSSV: 2001181003	
Ho va Ten: Le Nguyen Long Quoc An
Noi dung: Xu li mang 2 chieu
*/
//----------------------------------
//Khai bao thu vien
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#define MAX 100


//---------------------
//Khai bao cau truc, hang so (neu co)

//--------------------
//Khai bao ham con - prototype
void menu();
void thucThi();
void NhapDongvaCot(int &d,int &c);
void NhapMang2C(int a[][MAX], int &d,int &c);
void XuatMang2C(int a[][MAX], int d,int c);
int Tongtren1Dong(int a[][MAX],int d, int c,int &k);
bool Kiemtracoptu2Xuathien(int &n);
int DemCobnhiuPtuCoso2(int a[][MAX],int d, int c);
bool KtraMangcoToanDuong(int a[][MAX],int d,int c);
void change(int &a, int &b);
void SapxepCCtang(int a[][MAX],int d,int c);
int TimPtuLonNhatoBIen(int a[][MAX], int d,int c);
bool KiemtraKcotangdan(int a[][MAX],int d,int c,int &k);
bool KiemtraCotCogiamdan(int a[][MAX],int d,int c, int l);
bool kiemTraCoPTLeKhong(int &n);
int DemsoPtudaulaLe(int a[][MAX],int d,int c);

//Than chuong trinh
void main(){
	menu();
	thucThi();
	getch();
}
//Menu chuong trinh
void menu(){
	int n = 0;
	printf("\n\n=============Chuong Trinh thuc Thi buoi 1===========");
	
	printf("\n\n0. Thoat chuong trinh: .");
	printf("\n\n1. Nhap Xuat Mang 2 Chieu .");
	printf("\n\n2. Tinh tong cua 1 dong k .");
	printf("\n\n3. Dem so ptu co chua chu so 2 .");
	printf("\n\n4. Kiem tra mang co toan duong hay khong .");
	printf("\n\n5. Sap xep duong cheo chinh tang .");
	printf("\n\n6. Tim ptu lon nhat o vi tri bien cua mang A .");
	printf("\n\n7. Kiem tra cac ptu tren dong k co tang dan");
	printf("\n\n8. Kiem tra cac ptu tren cot l co giam dan");
	printf("\n\n9. Dem co bao nhieu ptu co chu so dau la le");
}
void thucThi(){
	int d,c; //d dong; c cot; V: gia tri lon nhat cua mang
	int A[MAX][MAX];
	int chon = -1;
	while (chon!=0)
	{
		printf("\nMoi nhap so can thuc thi: ");
		scanf("%d", &chon);
		switch(chon)
		{
			case 0: exit(1);
				break;
			case 1:
				{				
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
				}break;
			case 2:
				{
					int k;					
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					do
					{
						printf("Nhap so dong can tinh");
						scanf("%d",&k);
					}while(k<0||k>d);
					printf("tong dong cua ban muon tinh la:%d",Tongtren1Dong(A,d,c,k));
					
				}break;
			case 3:
				{					
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					printf("So luong ptu co chua so 2 la: %d",DemCobnhiuPtuCoso2(A,d,c));

				}break;
			case 4:
				{					
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					if(KtraMangcoToanDuong(A,d,c)==true)
						printf("Mang toan duong");
					else
						printf("Khong la mang toan duong");					
				}break;
			case 5:
				{				
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					SapxepCCtang(A,d,c);
					printf("Mang sau khi sap xep\n");
					XuatMang2C(A,d,c);
				}break;
			case 6:
				{				
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					printf("So lon nhat tronf bien A la: %d",TimPtuLonNhatoBIen(A,d,c));
				}break;
			case 7:
				{
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					int k;
					printf("Nhap vao dong can kiem tra k= ");
					scanf("%d",&k);
					if(KiemtraKcotangdan(A,d,c,k)==true)
						printf("Dong la dong tang");
					else
						printf("Dong ko tang");
				}break;
			case 8:
				{
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					int l;
					printf("Nhap vao dong can kiem tra l= ");
					scanf("%d",&l);
					if(KiemtraKcotangdan(A,d,c,l)==true)
						printf("cot la cot giam");
					else
						printf("cot ko giam");
				}break;
			case 9:
				{
					NhapMang2C(A,d,c);
					XuatMang2C(A,d,c);
					printf("So ptu co so dau tien la le la: %d",DemsoPtudaulaLe(A,d,c));
				}break;
			default: printf("Gia tri chon khong phu hop"); 
				break;
		}
	}
}

//Xay dung cac ham

void NhapDongvaCot(int &d,int &c)
{
	do
	{
		printf("Nhap vao so dong d= ");
		scanf("%d",&d);
		printf("Nhap vao so dong c= ");
		scanf("%d",&c);
	}while(c<5||d<5);

}
void NhapMang2C(int a[][MAX], int &d,int &c)
{
	NhapDongvaCot(d,c);
	srand(int(time(NULL)));
	int dau = rand() ?  -1 : 1;
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
		{
			int dau = rand()&1 ?  -1 : 1;
			a[i][j]= dau* rand()%100;
		}
}
void XuatMang2C(int a[][MAX], int d,int c)
{
	for(int i=0;i<d;i++)
	{
		for(int j=0;j<c;j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
		
}
int Tongtren1Dong(int a[][MAX],int d, int c,int &k)
{
	int tong=0;
	for(int j=0;j<c;j++)
		tong+=a[k][j];
	return tong;
}
bool Kiemtracoptu2Xuathien(int &n)
{
	int temp=abs(n);
	int b;
	do{
		b = temp%10;
		temp /= 10;
		if(b==2)
		return true;
	}while(temp > 0);
	if(b==2)
		return true;
	return false;
}
int DemCobnhiuPtuCoso2(int a[][MAX],int d, int c)
{
	int dem=0;
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			if(Kiemtracoptu2Xuathien(a[i][j])==true)
				dem++;
	return dem;
}
bool KtraMangcoToanDuong(int a[][MAX],int d,int c)
{
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			if(a[i][j]<0)
				return false;
	return true;
}
void change(int &a, int &b)
{
   int c=a;
       a=b;
       b=c;
}
void SapxepCCtang(int a[][MAX],int d,int c)
{
	for(int i=0;i<d--;i++)
		if(a[i][i]>a[i+1][i+1])
			change(a[i][i],a[i+1][i+1]);
}
int TimPtuLonNhatoBIen(int a[][MAX], int d,int c)
{
	int max=0;
	for(int i=0;i<d;i++)
	{
		if(max<a[0][i])
			max=a[0][i];
	}
	for(int i=0;i<c;i++)
	{
		if(max<a[i][0])
			max=a[i][0];
	}
	for(int i=1;i<d;i++)
	{
		if(max<a[c-1][i])
			max=a[c-1][i];
	}
	for(int i=1;i<c;i++)
	{
		if(max<a[i][d-1])
			max=a[i][d-1];
	}
	return max;
}
bool KiemtraKcotangdan(int a[][MAX],int d,int c,int &k)
{
	for(int i=0;i<c-1;i++)
		if(a[k][i]>a[k][i+1])
			return false;
	return true;
}

bool KiemtraCotCogiamdan(int a[][MAX],int d,int c, int l)
{
	for(int i=0;i<d-1;i++)
		if(a[i][l]<a[i+1][l])
			return false;
	return true;
}
bool kiemTraCoPTLeKhong(int &n)
{
	int temp = abs(n);
	int x;
	do
	{
		x = temp % 10;
		temp /= 10;
	} while (temp > 0);
	if (x % 2 != 0)
	{
		return true;
	}
	return false;
}
int DemsoPtudaulaLe(int a[][MAX],int d,int c)
{
	int dem=0;
	for(int i=0;i<d;i++)
		for(int j=0;j<c;j++)
			if(kiemTraCoPTLeKhong(a[i][j])==true)
				dem++;
	return dem;
}
