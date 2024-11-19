#include<stdio.h>
#include<stdlib.h>
#define size 5

int count = 0;
struct node{
    int data;
    struct node *addr;
};
typedef struct node *NODE;

NODE enqueue(NODE start ,int item){
    NODE cur ,temp;
    if(count>=size){
        printf("Queue is full");
        return start;
    }
    temp=(NODE)malloc(sizeof(struct node));
    temp->data=item;
    temp->addr=NULL;
    cur = start;
    while(cur->addr!=NULL)
        cur = cur->addr;
    cur->addr = temp;
    count = count + 1;
    return start;
}

NODE dequeue(NODE start)
{
    NODE temp;
    if(start==NULL){
        printf("queue is empty ");
        return NULL;
    }
    temp=start;
    start=start->addr;
    printf("node deleted is %d",temp->data);
    free(temp);
    count=count-1;
    return start;
}

void display(NODE start){
    NODE temp;
    if(start==NULL){
        printf("node is empty");
    }else{
        printf("contents of the queue ");
        temp=start;
        while(temp!=NULL)
        {
            printf("%d",temp->data);
            temp=temp->addr;
        }
    }
}

int main(){
    NODE start=NULL;
    int ch,item;
    for(;;)
    {
        printf("1 enqueue");
        printf("2. dequeue");
        printf("3. display");
        printf("4. exit");
        printf("read choice");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("read eleent to be printed");
                    scanf("%d", &item);
                    start=enqueue(start,item);
                    break;

            case 2 : start=dequeue(start);
                    break;
            
            case 3 : display(start);
                    break;
            default: exit(0);
        }
    }
    return 0 ;
}