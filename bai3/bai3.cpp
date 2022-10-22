/*
dem xem co bao nhieu doi tat trong ro

*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum {
      tatdo=101,
      tatvang=154,
      tatxanh=197,
      tattim=200,
      tatden=255

}tat;

typedef struct x{
      tat *soluong ;
      int size;

}mang;


void nhap(mang *sotat,char*name){
    char*c= (char*)malloc(100*sizeof(char));
    //printf("dia chi c %d",c);
    sotat->soluong=(tat*)malloc((sotat->size)*sizeof(tat));
	printf("nhap size:");
    scanf("%d",&sotat->size);
    getchar();
    int i;
    for(i=0;i<(sotat->size);){
    	printf("nhap mau tat: ");
    	gets(c);
    	
    	
    	if(strcmp("tat do",c)==0){
    		*(sotat->soluong+i)=tatdo;
    		strcpy(name+i*10,c);
    		i++;
		}else if(strcmp("tat vang",c)==0){
    		*(sotat->soluong+i)=tatvang;
			strcpy(name+i*10,c);
			    		i++;
		}else if(strcmp("tat xanh",c)==0){
    		*(sotat->soluong+i)=tatxanh;
    		strcpy(name+i*10,c);
    		i++;
		}else if(strcmp("tat tim",c)==0){
    		*(sotat->soluong+i)=tattim;
    		strcpy(name+i*10,c);
    		i++;
			}else if(strcmp("tat den",c)==0){
    		*(sotat->soluong+i)=tatden;
    		strcpy(name+i*10,c);
    		i++;
			}else{
			printf("loi\n");
	}
		}
		
	}
	
void xuat(mang*sotat,char*name){
	int i;
	for(i=0;i<(sotat->size);i++){
		puts(name+i*10);
		printf("co %d doi va du %d chiec\n",*(sotat->soluong+i)/2,*(sotat->soluong+i)%2);
	}
}
	


int main(){
mang sotat;
char *name = (char*)malloc(100*sizeof(char));
nhap(&sotat,name);
xuat(&sotat,name);
 
	                                                                                                                                                                                   
}
