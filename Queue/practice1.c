#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10
typedef struct {
    int data;
    int priority;
    
}Element;
typedef struct{
    Element elements[MAX_SIZE];
    int size;

}PriorityQueue;

void initializeQueue(PriorityQueue *pq)
{
    pq->size=0;
}
int isEmpty(PriorityQueue *pq)
{
    return pq->size==0;
}
int isFull(PriorityQueue *pq)
{
    return pq->size==MAX_SIZE;
}


void enqueue(PriorityQueue *pq,int value, int priority)
{
    if(isEmpty(pq))
    {
        printf("Queue is full.");
        return;
    }
    int i;
    for(i=pq->size-1;i>=0;i--)
    {
        if(pq->elements[i].priority>priority)
        {
            pq->elements[i+1]=pq->elements[i];
        }
        else{
            break;
        }
    }
    pq->elements[i+1].data=value;
    pq->elements[i+1].priority=priority;
    pq->size++;
    printf("enqueued %d with the priority of %d.",value,priority);

}
int dequeue(PriorityQueue *pq)
{
    if(isEmpty(pq))
    {
        printf("Queue is empty and emptyy queue cannot be dequed:");
        return -1;
    }
    int value=pq->elements[0].data;
    for(int i=1;i<pq->size;i++)
    {
        pq->elements[i-1]=pq->elements[i];
    }
    pq->size--;
    printf("dequed %d.",value);

}
void display(PriorityQueue *pq)
{
    if(isEmpty(pq))
    {
        printf("Queue is Emoty.");
        return;
    }
    printf("Priority Queue:");
    for(int i=0;i<pq->size;i++)
    
    {
        printf("value:%d\n and priority:%d\n",pq->elements[i].data,pq->elements[i].priority );
        

    }
}
int main()
{
    PriorityQueue pq;
    initializeQueue (&pq);
    enqueue(&pq,10,2);
    enqueue(&pq,20,1);
    enqueue(&pq,30,3);
    display(&pq);
    dequeue(&pq);
    enqueue(&pq,2,0);
    display(&pq);

    return 0;

}
