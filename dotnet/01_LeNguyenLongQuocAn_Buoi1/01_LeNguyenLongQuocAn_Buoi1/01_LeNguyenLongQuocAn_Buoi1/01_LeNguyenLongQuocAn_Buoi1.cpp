/*
STT:01
MSSV: 2001181003	
Ho va Ten: Le Nguyen Long Quoc An
Noi dung: Xu li mang 1 chieu
*/
//----------------------------------
//Khai bao thu vien
#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
int index[10] = {0};


//---------------------
//Khai bao cau truc, hang so (neu co)

//--------------------
//Khai bao ham con - prototype
void menu();
void thucThi();
void Nhap(int a[],int &n);
void NhapBangTay(int a[],int &n);
void NhapMangChan(int a[],int &n);
void NhapMangChanLeXenKe(int a[],int &n);
void Xuat(int a[],int n);
bool Tachs(int n);
void XuatptudauLe(int a[],int n);
void xuatcuctrivatong(int a[],int n);
int Count(int A[],  int n, int x);
int Count(int A[],  int n);
int TraVeSoXuatHienItNhat(int a[],int n);
int SoLanXuatHienptu(int a[],int n,int x);
void MangConGiamDan(int a[], int n);
void change(int &a, int &b);
void ChanTangLeGiam(int a[], int n);
int kiemtrasochant2(int a[], int &n);
void XoaPhanTu(int a[], int &n, int &vt);
bool Kiemtramangcogiam(int a[],int n);
bool KiemtramangcolaCapsoCong(int a[],int n);
void MangConTangDan(int a[], int n);
int tinhTong(int n)
{
	if (n==1)
	{
		return 1;
	}
	else
	{
		return n+tinhTong(n-1);
	}
}
int tinh(int n)
{
	if (n ==1)
	{
		return 1;
	}
	else
	{
		return tinhTong(n)*tinh(n-1);
	}
}
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
	printf("\n\n1. Tao mang toan chan: .");
	printf("\n\n2. Tao mang chan le xen ke, xuat cuc tri va tinh tong: .");
	printf("\n\n3. Viet ham xuat cac chu so dau la le: .");
	printf("\n\n4. Viet ham xuat cac ptu xuat hien nhieu nhat trong mang: .");
	printf("\n\n5. Viet ham xuat cac ptu xuat hien it nhat trong mang: .");
	printf("\n\n6. Viet ham dem cac ptu xuat hien trong mang: .");
	printf("\n\n7. Viet ham tra ve mang con giam dan .");
	printf("\n\n8. Viet ham xuat chan tang le giam .");
	printf("\n\n9. Xoa ptu chan thu 2 trong mang .");
	printf("\n\n10. Kiem tra mang co phai mang giam hay khong.");
	printf("\n\n11. Kiem tra mang co phai mang cap so cong hay khong.");
	printf("\n\n12. Viet ham tra ve mang con tang dan dai nhat .");

}
void thucThi(){
	int M,N,V; //M dong; N cot; V: gia tri lon nhat cua mang
	int A[100];
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
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					printf("%d",tinh(n));
				}break;
			case 2:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapMangChanLeXenKe(A,n);
					Xuat(A,n);
					xuatcuctrivatong (A,n);
				}break;
			case 3:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					Nhap(A,n);
					XuatptudauLe(A,n);
				}break;
			case 4:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					printf("\nPhan tu xuat hien nhieu nhat la: %d",Count(A,n));
				}break;
			case 5:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					printf("\nPhan tu xuat hien it nhat la: %d",TraVeSoXuatHienItNhat(A,n));
				}break;
			case 6:
				{
					int n,x;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					printf("Nhap ptu can dem x = ");
					scanf("%d",&x);
					printf("\nSo lan ptu xuat hien la: %d",SoLanXuatHienptu(A,n,x));
				}break;
			case 7:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					MangConGiamDan(A,n);
				}break;
			case 8:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					Nhap(A,n);
					Xuat(A,n);
					printf("\n Mang sao khi sap xep\n");
					ChanTangLeGiam(A,n);
					Xuat(A,n);
				}break;
			case 9:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					Nhap(A,n);
					Xuat(A,n);
					int k=kiemtrasochant2(A,n);
					XoaPhanTu(A,n,k);
					printf("Mang sau khi xoa\n");
					Xuat(A,n);
					
				}break;
			case 10:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					if(Kiemtramangcogiam(A,n)==true)
						printf("Mang la mang giam");
					else
						printf("Mang khong phai mang giam");
				}break;
				case 11:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					if(KiemtramangcolaCapsoCong(A,n)==true)
						printf("Mang la mang Cap so cong");
					else
						printf("Mang khong phai mang Cap so cong");
				}break;
				case 12:
				{
					int n;
					printf("Nhap so luong mang");
					scanf("%d",&n);
					NhapBangTay(A,n);
					Xuat(A,n);
					MangConTangDan(A,n);
				}break;
			default: printf("Gia tri chon khong phu hop"); 
				break;
		}
	}
}

//Xay dung cac ham
void Nhap(int a[],int &n)
{
	srand(int (time(NULL)));
	for(int i=0;i<n;i++)
	{
		a[i]= rand() % 100;
	}
}
void NhapBangTay(int a[],int &n)
{
	
	for(int i=0;i<n;i++)
	{
		printf("Nhap Gia tri cho phan tu A[%d]=",i);
		scanf("%d",&a[i]);
	}
}
void NhapMangChan(int a[],int &n)
{
	for(int i=0;i<n;i++)
	{
		a[i]=(rand()%100)*2;
	}
}
void NhapMangChanLeXenKe(int a[], int &n)
{
	a[0]=rand()%100;
	for(int i=0;i<n;i++)
	{
		if(a[i-1]%2==0)
		{
			a[i+1]=(rand()%100)*2;
		}
		else
		{
			a[i+1]=(2*rand()%100)+1;
		}
	}
}
void Xuat(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		printf("%d  ",a[i]);
	}
}
void XuatptudauLe(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(Tachs(a[i])==true)
			printf("%d   ",a[i]);
	}
}
void xuatcuctrivatong(int a[],int n)
{
	int tong=0;
	for(int i=0;i<n;i++)
	{
		if((a[i]<a[i+1]&&a[i+1]>a[i+2])||(a[i]>a[i+1]&&a[i+1]<a[i+2]))
		{
			printf("\n%d  ",a[i]);
			tong+=a[i];
		}
	}
	printf("\nTong la: %d",tong);
}
bool Tachs(int n)
{
	int tam=0;
	while(n>0)
	{
		tam=n%10;
		n/=10;
	}
	if(tam%2!=0)
		return true;
	return false;
}
//dem so lan xuat hien cua x trong A
 int Count(int A[],  int n, int x)
 {
     int temp = 0;
    for(int i = 0; i<n; i++)
        if(A[i]==x)
            temp++;
    return temp;
}
//tim phan tu xuat hien nhat lan nhat trong A
 int Count(int A[],  int n) 
 {
     int temp1, temp = Count(A,n,A[0]), index = 0;
    for(int i = 1; i<n; i++)
    {
        temp1 = Count(A,n,A[i]);
        if(temp<temp1)
        {
            temp = temp1;
            index = i;
        }
    }
    return A[index];
}
 int TraVeSoXuatHienItNhat(int a[],int n){
    for(int i=0;i<n;i++){
        int temp = abs(a[i]);
        do{
            int b = temp%10;
            index[b]++;
            temp /= 10;
            
        }while(temp > 0);                
    }
    int min = 1000, x_min = 0;
    for(int i=0;i<9;i++){
        if(index[i] > 0){
            if(index[i] < min){
                min = index[i];
                x_min = i;
            }
        }
    }
    return x_min;
}
int SoLanXuatHienptu(int a[],int n,int x)
{
	int d=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			d++;
		}
	}
	return d;
}
void MangConGiamDan(int a[], int n)
{
	int dem=0;
	for (int i = 0; i < n; i++)
	{
		
		while (a[i] > a[i + 1])
		{
			if (dem == 0)
				printf("Mang con giam dan la:\n %d  %d ", a[i], a[i + 1]);
			else
				printf(" %d ", a[i]);
			i++; dem++;
		}
		printf("\n");
	}
}
void MangConTangDan(int a[], int n)
{
	int dem=0;
	for (int i = 0; i < n; i++)
	{
		
		while (a[i] < a[i + 1])
		{
			if (dem == 0)
				printf("Mang con tang dan la:\n %d  %d ", a[i], a[i + 1]);
			else
				printf(" %d ", a[i+1]);
			i++; dem++;
		}
		printf("\n");
	}
}
void change(int &a, int &b)
{
   int c=a;
       a=b;
       b=c;
}
void ChanTangLeGiam(int a[], int n)
{
   int i, j;
   for(i=0; i<n; i++)
       for(j=i+1; j<n; j++)
           if((a[i]%2!=0)&&(a[j]%2==0)||(a[i]==0&&a[j]%2==0))
                change(a[i],a[j]);
   for(i=0; i<n; i++)
       for(j=i+1; j<n; j++)
           if(a[i]>a[j])
              if(a[j]==0)
                 break;
              else
                 change(a[i],a[j]);
   for(int i=n-1; i>0; i--)
       for(int j=i-1; j>0; j--)
           if((a[i]>a[j])&&a[j]%2!=0)
                change(a[i],a[j]);
}


int kiemtrasochant2(int a[], int &n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]%2==0&&a[j]%2==0)
				return j;
}
void XoaPhanTu(int a[], int &n, int &vt)
{
    if(n <= 0){
        return;
    }
    if(vt < 0){
        vt = 0;
    }
    else if(vt >= n){
        vt = n-1;
    }
    for(int i = vt; i < n - 1; i++){
        a[i] = a[i+1];
    }
    --n;
}
bool Kiemtramangcogiam(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]<a[i+1])
			return false;
	}
	return true;
}
bool KiemtramangcolaCapsoCong(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]+a[i+1]==a[i+2])
			return true;
	}
	return false;
}
