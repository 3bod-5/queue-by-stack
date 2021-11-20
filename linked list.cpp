#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};
 

struct Queue {
    struct node *front, *rear;
};
 

struct node* newnode(int k)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));//malloc is a memory location
    temp->key = k;
    temp->next = NULL;
    return temp;
}


struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}
 

void enqueue(struct Queue* q, int k)
{
   
    struct node* temp = newnode(k);
 
    
    if (q->rear == 	NULL) {
        q->front = q->rear = temp;
        return;
    }
 
    
    q->rear->next = temp;
    q->rear = temp;
}
 

void dequeue(struct Queue* q)
{
    if (q->front == NULL)
        return;
    struct node* temp = q->front;
 
    q->front = q->front->next;
 
    
    if (q->front == NULL)
        q->rear = NULL;
 
    free(temp);
}
int main()
{
    struct Queue* q = createQueue();
    enqueue(q,6);
    enqueue(q,19);
    enqueue(q,12);
    enqueue(q,24);
    enqueue(q,10);
    enqueue(q,11);
    dequeue(q);//delete frist element
    dequeue(q);//delete second element
    printf("queue front element is: %d \n", q->front->key);//print frist element
    printf("queue rear elemnt is: %d", q->rear->key);//print last element
    return 0;
}
