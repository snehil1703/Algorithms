//
//  simple_queue.cpp
//  Algos - Sem 2
//
//  Created by Snehil Vishwakarma on 1/16/16.
//  Copyright © 2016 Indiana University Bloomington. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int data;
    struct nodetype *next;
}node;

node *start;

void push(int k)
{
    if(start==NULL)
    {
        start=(node *)malloc(sizeof(node));
        (*start).data=k;
        (*start).next=NULL;
    }
    else
    {
        node *temp=(node *)malloc(sizeof(node));
        if(temp==NULL)
            printf("\n BUFFER FULL! Cannot add any more!");
        else
        {
            (*temp).data=k;
            (*temp).next=NULL;
            node *use=start;
            while((*use).next!=NULL)
                use=(*use).next;
            (*use).next=temp;
            use=NULL;
            free(use);
        }
        temp=NULL;
        free(temp);
    }
}

void pop()
{
    if(start==NULL)
        printf("\n No element in the Queue!");
    else if((*start).next==NULL)
    {
        printf("\n Element popped: %d",(*start).data);
        start=NULL;
    }
    else
    {
        node *use=start;
        node *use1=start;
        while((*use).next!=NULL)
        {
            use1=use;
            use=(*use).next;
        }
        printf("\n Element popped: %d",(*use).data);
        (*use1).next=NULL;
        use=NULL;
        use1=NULL;
        free(use);
        free(use1);
    }
}

void peak()
{
    if(start==NULL)
        printf("\n No element in the Queue!");
    else
    {
        node *use=start;
        while((*use).next!=NULL)
            use=(*use).next;
        printf("\n Element at the PEAK: %d",(*use).data);
        use=(*use).next;
        free(use);
    }
}

void print()
{
    while(start!=NULL)
        pop();
    free(start);
}

int main()
{
    int k;
    do
    {
        printf("\n Select: \n 1. Push \n 2. Pop \n 3. Peak \n 4. Exit \n");
        scanf("%d",&k);
        if(k==1)
        {
            printf("\n Enter a number: ");
            scanf("%d",&k);
            push(k);
        }
        else if(k==2)
            pop();
        else if(k==3)
            peak();
        else if(k==4)
            break;
        else
            printf("\n Invalid Entry! Re-Enter! \n");
    }while(1);
    printf("\n Final Queue: ");
    print();
    printf("\n\n");
    return 0;
}