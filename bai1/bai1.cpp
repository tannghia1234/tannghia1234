/*
nhap nam sinh va tinh so tuoi hien tai
*/

#include<stdio.h>

typedef struct dateofbirth{
	int ngay;
	int thang;
	int nam;
}date;



void nhap(int *bien){
	scanf("%d",bien);
}
void xuat(int *bien){
	printf("%d",*bien);
}
int dieukien(int *ngay,int *thang,int *nam){
	int a=0;
	if(*ngay<1 || *ngay >31 ){
		printf("\nngay khong hop le\n");
		a++;
	} 
	if(*thang<1||*thang>12){
	   printf("\nthang khong hop le\n");
	   a++;
	}
	 if(*nam>2022){
		printf("\nnam khong hop le\n");
		a++;
	}
	 if (*thang==4||*thang==6||*thang==9||*thang==11){
		if(*ngay==31){
			printf("\nngay khong hop le voi thang %d\n",*thang);
			a++;
		}
	}
	if(*thang==2){
		if(*ngay>28){
			printf("\nngay khong hop le voi thang 2\n");
			a++ ;
		}
	}
	return a;
}
int tinhtuoi(int *ngay,int *thang,int *nam,int *ngayht,int *thanght,int *namht){
	if(*thanght<*thang){
		return *namht-*nam-1;
	} else if(*thanght>*thang){
		return *namht-*nam;
	}else {
		if(*ngayht<*ngay){
			return *namht-*nam-1;
		}else{
			return *namht-*nam;
		}
	}
}

int main(){
	date *datesinh,*datenow,date1,date2;
	datesinh=&date1;
	datenow=&date2;
    
        do{
        	printf("\nnhap ngay hien tai: ");
        	nhap(&(datenow->ngay));
        	printf("nhap thang hien tai: ");
        	nhap(&datenow->thang);
        	printf("nhap nam hien tai: ");
        	nhap(&datenow->nam);
		}while(dieukien(&datenow->ngay,&datenow->thang,&datenow->nam)>0);
        
		do{
        	printf("\nnhap ngay sinh: ");
        	nhap(&datesinh->ngay);
        	printf("nhap thang sinh: ");
        	nhap(&datesinh->thang);
        	printf("nhap nam sinh: ");
        	nhap(&datesinh->nam);
		}while(dieukien(&datesinh->ngay,&datesinh->thang,&datesinh->nam)>0);
		
		printf("ngay hien tai: ");
		xuat(&datenow->ngay);
		printf("/");
		xuat(&datenow->thang);
		printf("/");
		xuat(&datenow->nam);
		
		printf("\nngay sinh: ");
		xuat(&datesinh->ngay);
        printf("/");
        xuat(&datesinh->thang);
        printf("/");
        xuat(&datesinh->nam);
		
		printf("\nso tuoi = %d",tinhtuoi(&datesinh->ngay,&datesinh->thang,&datesinh->nam,
		                                  &datenow->ngay,&datenow->thang,&datenow->nam));
	 
	
	
}
