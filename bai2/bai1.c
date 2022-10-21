#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct x{
    int *mang;
    int size;
}infor;
void nhap(int* bien){
      scanf("%d",bien);
      getchar();
}
void xuat(int* bien){
      printf("%d\n",*bien);
}
void nhapdulieu(infor *dulieu){
     printf("nhap size: ");
     nhap(&(dulieu->size));
     dulieu->mang=(int*)malloc((dulieu->size)*sizeof(int));
    printf("nhap mang\n");
    for(int i=0;i<(dulieu->size);i++){
        printf("mang[%d] = ",i);
        nhap(&*(dulieu->mang+i));
    }    
}
int kiemtra(int* bien){
    if(*bien<1||*bien>4){
        printf("lua chon khong hop le");
        return 0;
    }
return 1;
}
void chonmenu(int *n){
    printf("\n----------MENU----------");
    printf("\nnhap 1 de xep tu be den lon");
    printf("\nnhap 2 de xep tu lon den be");
    printf("\nnhap 3 de tim so lon nhat");
    printf("\nnhap 4 de thoat chuong trinh");
    do{
    printf("\nnhan de chon: ");
    nhap(n);
    }while(kiemtra(n)==0);
}
char checkkt1(char *kt1){
    if(*kt1=='y'||*kt1=='n'){
        return 'y';
    }
    printf("nhap sai vui long nhap lai: ");
    return 'n';
}
void bedenlon(infor *dulieu){
    int temp;
    for(int i =0;i<(dulieu->size);i++){
       for(int j=i;j<(dulieu->size);j++){
          if(*(dulieu->mang+i)>=*(dulieu->mang+j)){
             temp = *(dulieu->mang+i);
             *(dulieu->mang+i)=*(dulieu->mang+j);
             *(dulieu->mang+j)=temp;
          }
       }
    }
    for(int i=0;i<(dulieu->size);i++){
       printf("mang[%d] = ",i);
       xuat(&*(dulieu->mang+i));
    }

}
void londenbe(infor *dulieu){
    int temp;
    for(int i =0;i<(dulieu->size);i++){
       for(int j=i;j<(dulieu->size);j++){
          if(*(dulieu->mang+i)<=*(dulieu->mang+j)){
             temp = *(dulieu->mang+i);
             *(dulieu->mang+i)=*(dulieu->mang+j);
             *(dulieu->mang+j)=temp;
          }
       }
    }
    for(int i=0;i<(dulieu->size);i++){
       printf("mang[%d] = ",i);
       xuat(&*(dulieu->mang+i));
    }


}

void solonnhat(infor *dulieu){
    int max = *(dulieu->mang+0);
    for(int i=0;i<(dulieu->size);i++){
       if(max<=*(dulieu->mang+i)){
          max = *(dulieu->mang+i);
       }
    }
    printf("so lon nhat la: %d\n",max);
}



void luachon(int *n,infor *dulieu){
    char kt1,kt2;
    switch (*n)
    {
    case 1: bedenlon(dulieu);
        break;
    case 2: londenbe(dulieu);
        break;
    case 3: solonnhat(dulieu);
        break;
    default: printf("THOAT!!!");
        break;
    }
    if(*n!=4){
    printf("ban co muon nhap lai du lieu\nco nhan y\nkhong nhan n\n");
    do{
    kt1=getchar();
    kt2=getchar();
    }while(checkkt1(&kt1)=='n');
       if(kt1=='y'){
       nhapdulieu(dulieu);
       }
    }
    
}




int main(){
infor *dulieu,abc;
dulieu=&abc;
int *n;
n=(int*)malloc(1*sizeof(int));
nhapdulieu(dulieu);
    do{
    chonmenu(n);
    luachon(n,dulieu);
}while(*n!=4);
}