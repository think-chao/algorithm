#define QUEMAX 15
typedef struct
{
	DATA data[QUEMAX];
	int head;
	int tail; //保存队头尾序号 
}SeqQueue;

//返回一个指针变量的函数,说到底指针就是一个存放地址的变量而已
//很显然,如果分配了空间,那么就返回这一片空间的起始地址了 
SeqQueue *SeqQueueInit(){
	SeqQueue *q;
	if(q=((SeqQueue *)malloc(SeqQueue))){
		q->head=0;
		q->tail=0;
		return q;
	}else
	{
		return NULL;
	}
} 

int SeqQueueIsEmpty(SeqQueue *q){
	return (q->head==q->tail);
}

void SeqQueueFree(SeqQueue *q)
{
	if(q!=NULL){
		free(q);
	}
} 

//入队 
int SeqQueueIn(SeqQueue *q,DATA data)
{
	if(q->tail==QUEMAX){
		printf("队列已经满了\n");
		return(0);
	}else{
		q->data[q->tail++]=data;
		return(1);
	}
}
DATA *SeqQueueOut(SeqQueue *q){
	if(q->head==0){
		pritnf("队列是空的\n");
		return NULL;
	}else{
		return &(q->data[q->head++]);
	}
}

//获取队头数据 
DATA *SeqQueuePeek(SeqQueue *q){
	if(SeqQueueIsEmpty(q)){
		pritnf("队列空\n");
		return NULL;
	}else{
		return &(q->data[q->head]);
	}
	
} 
 
