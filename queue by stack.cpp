#include<stdio.h>
int top=-1;
int maxsize=6;
int queue[6];
int isempty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
int isfull(){
	if(top==maxsize-1){
		return 1;
	}
	else{
		return 0;
	}
}
int peek(){
	return queue[top];
}
int push(int data){
	if(!isfull()){
		top++;
		queue[top]=data;	
	}else{
		printf("the queue is full \n");
	}
}
int pop(){
	int data;
	if(top>-1){
		data=queue[top];
		top=top-1;
		return data;
	}
	else{
		printf("the queue is empty");
	}
}
int dequeue(){
	pop();
}
int enqueue(int data){
	push(data);
}
int display(){
	int data;
	for(int i=0;i<=top;i++){
		data=queue[i];
		printf("the element in index %d is : %d \n",i,data);
	}
}
int getrear(){
	if(isempty()){
		printf("the stack is empty");
	}
	else{
		return queue[0];
	}
}
int main(){
	enqueue(5);
	enqueue(6);
	enqueue(8);
	enqueue(10);
	enqueue(5);
	enqueue(3);
	printf("the frist element is :%d\n",peek());
	printf("the last element is:%d\n",getrear());
	display();
	while(!isempty()){
		int data=dequeue();
		printf("%d\n",data);
	}
	printf("the queue is empty :%s\n",isempty()?"true":"false");
	printf("the queue is full :%s",isfull()?"true":"false");
}























