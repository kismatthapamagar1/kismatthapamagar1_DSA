#include<stdio.h>
#include<stdlib.h>


struct circularQueue{
    int size;
    int f;
    int r;
    int *arr;

};
int isFull(struct circularQueue *q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }

}

void enqueue(struct circularQueue *q, int value)
{
    if(isFull(q))
    {
        printf("This queue is full and no space for the enque:");

    }
    else{
        q->r++;
        q->arr[q->r]=value;
        printf("Enqueued element is %d",value);
      }
}
int isEmpty(struct circularQueue *q) 
{
    if(q->f==-1||q->f>q->r){
    return 1;}

}
return 0;


int dequeue(struct circularQueue *q,int value)
{
    int a =-1;
    if(isEmpty(q))
    {
        printf("The queue is empty");


    }
    else{
        q->f++;
        a=q->arr[q->f];

    }
return a;
}



int main()
{
    struct circularQueue q;
    q.size=4;
    q.f=q.r=-1;
    q.arr=(int*)malloc(q.size*sizeof(int));

    // enqueueing the elements


    enqueue(&q,12);
     enqueue(&q,13);
      enqueue(&q,14);
       enqueue(&q,12);

    //    dequeung the elements
    dequeue(&q);


}