/*
STT:01
MSSV: 2001181003	
Ho va Ten: Le Nguyen Long Quoc An
Noi dung: Xu li mang 2 chieu (tiep theo) va de quy
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
void change(int &a, int &b);
void SapxepDongtang(int a[][MAX], int d, int c);
void SapXepCotgiam(int a[][MAX], int d, int c);
int Nhapn();
int Tinhgiathua(int n);
float TinhcanBac2(int n);
float Tinhtongnchianc1(int n);
float Tinhtong1chia2nc1(int n);
double TinhtongS10(int n);
void SapxepDongletangChanGiam(int a[][MAX], int d, int c);
void SapXepCotlegiamchantang(int a[][MAX], int d, int c);
float Sc16(int n);
int Sc17(int n);
float S19(int n);
int tinhS18(int n);
float tinhS20(int n);
float tinhS21(int n);


//Than chuong trinh
void main(){
	menu();
	thucThi();
	getch();
}
//Menu chuong trinh
void menu(){
	int n = 0;
	printf("\n\n=============Chuong Trinh thuc Thi buoi 3===========");
	
	printf("\n\n0. Thoat chuong trinh: .");
	printf("\n\n1.Sap xep tang dan theo dong");
	printf("\n\n2.Sap xep giam dan theo cot");
	printf("\n\n3.Tinh giai thua n");
	printf("\n\n5.tinh tong S8");
	printf("\n\n6.tinh tong S9");
	printf("\n\n7.tinh tong S10");
	printf("\n\n8.Sap xep dong le tang chan giam");
	printf("\n\n9.Sap xep cot le giam chan tang");
	printf("\n\n10.tinh tong S16");
	printf("\n\n11.tinh tong S17");
	printf("\n\n12.tinh tong S19");
	printf("\n\n13.tinh tong S18");
	printf("\n\n14.tinh tong S20");
	printf("\n\n15.tinh tong S21");
	

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
					SapxepDongtang(A,d,c);
					XuatMang2C(A,d,c);
				}break;
			case 2:
				{
					NhapMang2C(A,d,c);
					SapXepCotgiam(A,d,c);
					XuatMang2C(A,d,c);
				}break;
			case 3:
				{
					int x=Nhapn();
					printf("Gia tri giai thua cua n=%d la %d ",x,Tinhgiathua(x));

				}break;
			case 4:
				{
					int x=Nhapn();
					printf("Gia tri can bac 2 cua n=%d la %f ",x,TinhcanBac2(x));
				}break;
			case 5:
				{
					int x=Nhapn();
					printf("Gia tri phan so cua n=%d la %f ",x,Tinhtongnchianc1(x));
				}break;
			case 6:
				{	int x=Nhapn();
					printf("Gia tri phan so cua n=%d la %f ",x,Tinhtong1chia2nc1(x));
				}break;
			case 7:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %f ",x,TinhtongS10(x));
				}break;
			case 8:
				{
					NhapMang2C(A,d,c);
					SapxepDongletangChanGiam(A,d,c);
					XuatMang2C(A,d,c);
				}break;
			case 9:
				{
					NhapMang2C(A,d,c);
					SapXepCotlegiamchantang(A,d,c);
					XuatMang2C(A,d,c);
				}break;
			case 10:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %f ",x,Sc16(x));
				}break;
			case 11:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %d ",x,Sc17(x));
				}break;
			case 12:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %f ",x,S19(x));
				}break;
			case 13:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %d ",x,tinhS18(x));
				}break;
			case 14:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %f ",x,tinhS20(x));
				}break;
			case 15:
				{
					int x=Nhapn();
					printf("Gia tri s10 cua n=%d la %f ",x,tinhS21(x));
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

void change(int &a, int &b)
{
   int c=a;
       a=b;
       b=c;
}
void SapxepDongtang(int a[][MAX], int d, int c)
{
	for(int i=0;i<d;i++)
		for(int j=0;j<c-1;j++)
			for(int k=j+1;k<c;k++)
				if(a[i][j]>a[i][k])
					change(a[i][j],a[i][k]);
}
void SapXepCotgiam(int a[][MAX], int d, int c)
{
	for(int i=0;i<c;i++)
		for(int j=0;j<d;j++)
			for(int k=i+1;k<c;k++)
				if(a[i][j]<a[k][j])
					change(a[i][j],a[k][j]);
}

int  Nhapn()
{
	int n;
	do
	{
		
		printf("nHAP GIA TRI n=");
		scanf("%d",&n);
		return n;
	}while(n>0);
}
int Tinhgiathua(int n)
{
	if(n==1)
		return 1;
	else
		return n*Tinhgiathua(n-1);
}
float TinhcanBac2(int n)
{
	if(n==1)
		return sqrt(float(2));
	else
		return sqrt(float(2)+ float(TinhcanBac2(n-1)));
}
float Tinhtongnchianc1(int n)
{
	if(n==1)
		return (float)1/2;
	else
		return float(n)/float(n+1)+Tinhtongnchianc1(n-1);
}
float Tinhtong1chia2nc1(int n)
{
	if(n==0)
		return 1;
	else
		return float(1)/float(2*n+1)+Tinhtong1chia2nc1(n-1);
}
double TinhtongS10(int n)
{
	if(n==1)
		return 2;
	else
		return n*(n+1)+TinhtongS10(n-1);
}
void SapxepDongletangChanGiam(int a[][MAX], int d, int c)
{
	for(int i=0;i<d;i++)
		for(int j=0;j<c-1;j++)
			for(int k=j+1;k<c;k++)
			{
				if(i%2!=0)
					if(a[i][j]>a[i][k])
						change(a[i][j],a[i][k]);
			}
	for(int i=0;i<d;i++)
		for(int j=0;j<c-1;j++)
			for(int k=j+1;k<c;k++)
			{
				if(i%2==0)
					if(a[i][j]<a[i][k])
						change(a[i][j],a[i][k]);
			}
				
					
}
void SapXepCotlegiamchantang(int a[][MAX], int d, int c)
{
	for(int i=0;i<c;i++)
		for(int j=0;j<d;j++)
			for(int k=i+1;k<c;k++)
			{
				if(j%2!=0)
					if(a[i][j]<a[k][j])
						change(a[i][j],a[k][j]);
			}
	for(int i=0;i<c;i++)
		for(int j=0;j<d;j++)
			for(int k=i+1;k<c;k++)
			{
				if(j%2==0)
					if(a[i][j]>a[k][j])
						change(a[i][j],a[k][j]);
			}			
}
float Sc16(int n)
{
	if(n==1)
		return (float)1/6;
	else
		return ((float)1/(n*(n+1)*(n+2)))+Sc16(n-1);

}
int Sc17(int n)
{
	if(n==1)
		return 1;
	else
		return n*n+Sc17(n-1);

}

float S19(int n)
{
	if(n==1)
		return (float)-3/2;
	else
	{
		float a = pow((float)-1,n);
		float b = (float)(2*n-1+2*n)/Tinhgiathua(2*n);
		return  a * b+S19(n-1);
	}
	
}
int tinhS18(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n+tinhS18((n-1));
	}
	
}

float tinhS20(int n)
{
	if (n == 1)
	{
		return (float)2/ (2 + sqrt((float)3));
	}
	else
	{
		float a = n*Tinhgiathua(n+1);
		float b = (n+1)+ sqrt((float)n+2);
		return (float)a / b + tinhS20(n-1);
	}
}
// 21 
float tinhS21(int n)
{
	if (n == 1)
	{
		return (float)(1+sqrt((float)3))/(2+sqrt((float)6));
	}
	else
	{
		return (float)(n+sqrt((float)n+n+1))/((n+1)+sqrt((float)Tinhgiathua(n+2))) + tinhS21(n-1);
	}
}