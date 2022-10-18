#include<stdio.h>
#include<stdlib.h>


void nhap(int *bien){
	scanf("%d",bien);
}
void xuat(int *bien){
	printf("%d ",*bien);
}
bedenlon(int* mang,int size){
	int i,j,temp;
     for(i=0;i<size;i++){
     	for(j=i;j<size;j++){
     		if(*(mang+i)>=*(mang+j)){
     			temp=*(mang+i);
     			*(mang+i)=*(mang+j);
     			*(mang+j)=temp;
			 }
		 }
	 }
	for(i=0;i<size;i++){
		xuat(mang+i);
	}
}
londenbe(int* mang,int size){
	int i,j,temp;
     for(i=0;i<size;i++){
     	for(j=i;j<size;j++){
     		if(*(mang+i)<=*(mang+j)){
     			temp=*(mang+i);
     			*(mang+i)=*(mang+j);
     			*(mang+j)=temp;
			 }
		 }
	 }
	for(i=0;i<size;i++){
		xuat(mang+i);
	}
}
lonnhat(int*mang,int size){
	int i,max;
	max=*(mang);
	for(i=0;i<size;i++){
		if(max<=*(mang+i)){
			max=*(mang+i);
		}
	}
	printf("gia tri lon nhat: ");
	xuat(&max);
}
int dieukien(int *bien){
	if(*bien<1||*bien>4){
		printf("lua chon khong hop le");
		return 0;
	}
	return 1;
}
int main(){
	int size,n;
	printf("nhap size: ");
	scanf("%d",&size);
	int* mang = (int*)malloc(size * sizeof(int));
	int i;
	printf("nhap mang:\n");
	for(i=0;i<size;i++){
	    printf("mang[%d]= ",i);
		nhap(mang+i);
	}
		do{
		printf("\n----------MENU----------");
		printf("\nnhan 1 sap xep tu be den lon");
		printf("\nnhan 2 sap xep tu lon den be");
		printf("\nnhan 3 tim so lon nhat");
		printf("\nnhan 4 thoat chuong trinh");
		
		
		
		do{
			printf("\nnhap de lua chon: ");
			nhap(&n);
		}while(dieukien(&n)==0);
		
		switch (n){
			case 1:
				bedenlon(mang,size);
				break;
			case 2:
			    londenbe(mang,size);
			    break;
			case 3:
			     lonnhat(mang,size);
			    break;
			default:
			printf("thoat");			
		}
		
    }while(n!=4);   
}



