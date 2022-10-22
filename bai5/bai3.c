/*tìm kiếm chuỗi con trong một chuỗi
Yêu cầu bài tập là tìm kiếm một chuỗi con trong một chuỗi và đếm xem chuỗi con đó xuất hiện bao nhiêu lần.
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct x{
    char *timkiem;
    char *mang;
    int size_tim_kiem;
    int size;
    int chieu_dai_ki_tu_1;
    int chieu_dai_ki_tu_2;

}infor;
void input(int *bien){
     scanf("%d",bien);
     getchar();
}
void output(int *bien){
    printf("%d",*bien);
}
void nhap_van_ban(void(*nhap)(int*),infor *dulieu){
     printf("nhap so ki tu can cho van ban: ");
     nhap(&(dulieu->size));
     dulieu->mang=(char*)malloc((dulieu->size)*sizeof(char));
     printf("nhap van ban:\n");
     fgets(dulieu->mang,dulieu->size,stdin);    
}
void nhap_chu_can_tim(void(*nhap)(int*),infor *dulieu){
     printf("nhap so ki tu can tim: ");
     nhap(&(dulieu->size_tim_kiem));
     dulieu->timkiem=(char*)malloc((dulieu->size_tim_kiem)*sizeof(char));
     printf("nhap doan van can tim:\n");
     fgets(dulieu->timkiem,dulieu->size_tim_kiem,stdin);
}
void chieu_dai(infor *dulieu){
     dulieu->chieu_dai_ki_tu_1=0;
     dulieu->chieu_dai_ki_tu_2=0;
     int co=0;
     
     for(int i=0;i<(dulieu->size);i++){
         if(*(dulieu->mang+i)=='\n' || *(dulieu->mang+i)==' '){
              for(int j =i;j<(dulieu->size);j++){
                  if(*(dulieu->mang+j) != '\n' && *(dulieu->mang+j) != ' '){
                       break;
                  }else if(*(dulieu->mang+j) == 10){
                    co++;
                    break;
                  }
              }
         }
         if(co>0){
            *(dulieu->mang+i)='\0';
              break;
         }
         dulieu->chieu_dai_ki_tu_1++; 
     }

    
          co=0;
     for(int i=0;i<(dulieu->size_tim_kiem);i++){
         if(*(dulieu->timkiem+i)=='\n' ||*(dulieu->timkiem+i)==' '){
              for(int j=i;j<(dulieu->size_tim_kiem);j++){
                  if(*(dulieu->timkiem+j) != '\n' && *(dulieu->timkiem+j) != ' '){
                     break;
                  } else if(*(dulieu->timkiem+j)== 10){
                        co++;
                        break;
                  }
              }
         }
         if(co>0){
                    *(dulieu->timkiem+i)='\0';
                    break;
                  }
         dulieu->chieu_dai_ki_tu_2++;
     }
     
}
void tim_kiem(infor *dulieu){
    int dem=0,dem1=0;
      for(int x=0;x<(dulieu->chieu_dai_ki_tu_1);x++){
          if(*(dulieu->mang+x)==*(dulieu->timkiem+0)){
              int y=x;
              for(int z=0;z<(dulieu->chieu_dai_ki_tu_2);z++){
                  if(*(dulieu->mang+y)==*(dulieu->timkiem+z)){
                      dem++;
                      y++;
                  }else{
                    break;
                  }
              }
              if(dem==(dulieu->chieu_dai_ki_tu_2)){
                   dem1++;
              }
          }
          dem=0;
      }
     if(dem1 ==0 ){
          printf("khong co trong van ban!!");
      }else{
        printf("doan -%s- co trong van ban va xuat hien %d lan",dulieu->timkiem,dem1);
     }
}
int main(){
    infor dulieu;
    char kitu;
    nhap_van_ban(&input,&dulieu);
    do{
    nhap_chu_can_tim(&input,&dulieu);
    chieu_dai(&dulieu);
    tim_kiem(&dulieu);
    printf("\nban co muon tim kiem tiep?\nmuon nhan y\nkhong nhan n\n");
    int n=0;
    do{
        if(n!=0){
            printf("nhap sai vui long nhap lai\n");
        }
    kitu = getchar();
    getchar();
    n++;
    }while(kitu != 'y'&& kitu != 'n');
    }while(kitu == 'y');
    printf("THOAT!!!");
}