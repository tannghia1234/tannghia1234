/*chia mot mang cac so tu 0 toi 9 thanh hai mang chan va mang le
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct x{
        int *odd;
        int *even;
        int *mang;
        int size;
}infor;
void input(int * bien){
      scanf("%d",bien);
      getchar();
}
void output(int *bien){
      printf("%d ",*bien);
}

void nhap_mang(void(*nhap)(int*),infor *dulieu){
        printf("nhap size: ");
        nhap(&(dulieu->size));
        dulieu->mang = (int*)malloc((dulieu->size)*sizeof(int));
        for(int i=0;i<(dulieu->size);i++){
            printf("mang[%d] = ",i);
            nhap(&*(dulieu->mang+i));
            }
}
void dem(infor *dulieu,int *chan,int*le){
     *chan =0;
     *le = 0;
     
     for(int i=0;i<(dulieu->size);i++){
        if(*(dulieu->mang+i)%2==0){
           (*chan)++;
        }else{
            (*le)++;
        }
     }  
}
void chia_mang(infor *dulieu,int *chan,int *le ){
          int y=0,z=0;
          dulieu->even=(int*)malloc(*chan*sizeof(int));
          dulieu->odd=(int*)malloc(*le*sizeof(int));
          for(int x=0;x<(dulieu->size);x++){
             if(*(dulieu->mang+x)%2==0){
                *(dulieu->even+y)=*(dulieu->mang+x);
                y++;
            }else{
                *(dulieu->odd+z)=*(dulieu->mang+x);
                z++;
        }
          }       
}
void xuat_mang(void(*xuat)(int*),infor *dulieu,int *chan,int* le){
              printf("mang chan: \n");
              for(int i=0;i<(*chan);i++){
                  xuat(&*(dulieu->even+i));
              }
              printf("\n");
              printf("mang le: \n");
              for(int i=0;i<(*le);i++){
                  xuat(&*(dulieu->odd+i));
              }
}
int main(){
    infor *dulieu,abc;
    int chan,le;
    char kitu;
    dulieu=&abc;
    do{
    nhap_mang(&input,dulieu);
    dem(dulieu,&chan,&le);
    chia_mang(dulieu,&chan,&le);
    xuat_mang(&output,dulieu,&chan,&le);
    printf("\nban co muon tiep tuc\nco nhan y\nkhong nhan n\n");
    int n=0;
    do{
        if(n!=0){
          printf("nhap khong dung, vui long nhap lai\n");
        }
    kitu=getchar();
    getchar();
    n++;
    }while((kitu)!='y'&&(kitu)!='n');
    }while(kitu=='y');
    printf("THOAT!!!");
}