# include<stdio.h>
# include<stdlib.h>
# define size 5

int count = 0;

struct node {
    int data;
    struct node *addr;
};

typedef struct node *NODE;

NODE push(NODE start,int item){
    NODE temp;
    if(count==size){
        printf("Stack overflow");
        return start;
    }
    temp=(NODE)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("memory allocation failed ");
        return start;
    }
    temp->data=item;
    temp->addr=start;
    count++;
    return temp;
}


NODE pop(NODE start){
    NODE temp;
    if(start == NULL){
        printf("Stck underflow");
        return NULL;
    }
    temp = start;
    start = start->addr;
    printf("Element popped is %d",temp->data);
    free(temp);
    count--;
    return start;
}


void display(NODE start)
{
    NODE temp;
    if(start ==NULL)
    {
        printf("Stack is empty");
    }else{
        printf("Stack contents are");
        temp=start;
        while(temp!=NULL){
            printf("%d",temp->data);
            temp=temp->addr;
        }
    }
}

int main(){
    NODE start = NULL;
    int choice, item;

    while(1){
        printf("\n1: Push \n2: Pop \n3: Display \n4: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Corrected format specifier

        switch (choice){
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &item);
                start = push(start, item);
                break;

            case 2: 
                start = pop(start);
                break;

            case 3: 
                display(start);
                break;
            
            case 4: 
                exit(0);
            
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

