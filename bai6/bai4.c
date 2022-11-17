//bai tap danh sach lien ket
// quy uoc phan tu dau tien la 1, phan tu tiep theo la 2,....

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* makenode(int value){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=NULL;
    return newnode;
}
void print(node *head){
    while(head!=NULL){
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}

//Để thêm một phần tử vào vị trí sau cùng của vector:
void name_of_vector_push_back(node **head,int value){
    node *temp=*head;
    node *newnode=makenode(value);
    if((*head)==NULL){
        (*head)=newnode;
    }else{
        while((temp->next)!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
//Để bỏ đi phần tử cuối cùng của vector:
void name_of_vector_pop_back(node **head){
    node *temp=*head;
    if((*head)==NULL){
        printf("khong co node\n");
        exit(0);
    }else if((*head)->next==NULL){
        printf("co 1 node\n");
        free(*head);
        exit(0);
    }else{
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}
//Để bỏ đi tất cả các phần tử của vector:
void name_of_vector_clear(node **head){
    if(*head==NULL){
        printf("khong co node\n");
        exit(0);
    }else{
        node *temp=*head;
        while(1){
            if((*head)->next==NULL){
                free(*head);
                (*head)=NULL;
                break;
            }
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            free(temp->next);
            temp->next=NULL;
            temp=*head;
        }
    }
}
//Để lấy ra phần tử đầu tiên của vector:
void name_of_vector_front(node *head){
    printf("%d\n",head->data);
}
//Để lấy ra phần tử cuối cùng của vector:
void name_of_vector_back(node *head){
    while(head->next!=NULL){
        head=head->next;
    }
    printf("%d\n",head->data);
}
//Để lấy ra phần tử vị trí thứ n của vector (đếm từ 1):
void name_of_vector_at(node* head,int place){
    if(head==NULL){
        printf("khong co phan tu de in\n");
    }else{
        for(int i=1;i<place;i++){
            head=head->next;
        }
        printf("%d\n",head->data);
    }
}
//Để biết số lượng phần tử của vector:
void name_of_vector_size(node *head){
    int count=0;
    while(head!=NULL){
        count++;
        head=head->next;
    }
    printf("%d\n",count);
}
//Để biết vector có phần tử hay không:
void name_of_vector_empty(node *head){
    if(head==NULL){
        printf("vecto nay khong co phan tu nao\n");
    }else{
        printf("vecto nay co phan tu\n");
    }
}

int main(){
    node* node1=NULL;
    int n,value;
    while(1){
        printf("----------MENU----------\n");
        printf("1. them mot phan tu vao vi tri sau cung cua vector\n");
        printf("2. bo di phan tu cuoi cung cua vector\n");
        printf("3. bo di tat ca cac phan tu cua vecto\n");
        printf("4. lay ra phan tu dau tien cua vector\n");
        printf("5. lay ra phan tu cuoi cung cua vector\n");
        printf("6. lay ra phan tu thu n cua vector\n");
        printf("7. so luong phan tu cua vector\n");
        printf("8. vecto co phan tu hay khong\n");
        printf("9. in phan tu\n");
        printf("10. THOAT\n");
        printf("-------------------------\n");
        printf("nhap lua chon: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1: 
            printf("nhap phan tu: ");
            scanf("%d",&value);
            name_of_vector_push_back(&node1,value);
            break;
        case 2:
            name_of_vector_pop_back(&node1);
            break;
        case 3:
            name_of_vector_clear(&node1);
            break;
        case 4:
            name_of_vector_front(node1);
            break;
        case 5:
            name_of_vector_back(node1);
            break;
        case 6:
            printf("nhap vi tri: ");
            scanf("%d",&value);
            name_of_vector_at(node1,value);
            break;
        case 7:
            name_of_vector_size(node1);
            break;
        case 8:
            name_of_vector_empty(node1);
            break;
        case 9:
            print(node1);
        default:
            break;
    }
        if(n>=10){
            printf("THOAT!!!");
            break;
        }
    }
    
}