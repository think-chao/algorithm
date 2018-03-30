#define QUEUEMAX 15
typedef struct{
	DATA data[QUEUEMAX];
	int head;
	int tail;
}CycQueue;

//循环队列初始化
CycQueue *CycQueueInit(){
	CycQueue *q;
	if(q=(CycQueue *)malloc(sizeof(CycQueue))){
		q->head=0;
		q->tail=0;
		return q;
	}else{
		return NULL;
	}
}
void CycQueueFree(CycQueue *q) //释放队列
{
    if (q!=NULL)
        free(q);
}  

//队列是否为空
int CycQueueIsEmpty(CycQueue *q){
	return (q->head==q->tail);
}
//队列是否已满 
int CycQueueIsFull(CycQueue *q){
	return ((q->tail+1)%QUEUEMAX==q->head);
}

//入队,从队尾入队 
int CycQueueIn(CycQueue *q,DATA data){
	if((q->tail+1)%QUEUEMAX==q->head){
		printf("队列已经满了\n");
		return 0;
	}else{
		q->tail=(q->tail+1)%QUEUEMAX;
		q->data[q->tail]=data;
		return 1;
	}
} 

//出队,从队首出队 
//出队的时候head会不断的后移,当移到head和tail相等时候,队列的元素就都移走了
//假设head移到了n,tail变成了1 
DATA *CycQueueOut(CycQueue *q){
	if(q->head==q->tail){
		return NULL;
	}else{
		q->head=(q->head+1)%QUEUEMAX;
		return &(q->data[q->head]);
	}
} 

int CycQueueLen(CycQueue *q) //获取队列长度 
{
    int n;
    n=q->tail-q->head;
    if(n<0)
        n=QUEUEMAX+n;
    return n;
}
DATA *CycQueuePeek(CycQueue *q) //获取队定中第1个位置的数据
{
    if(q->head==q->tail)
    {
        printf("队列已经为空!\n");
        return NULL; 
    }else{
        return &(q->data[(q->head+1)%QUEUEMAX]);
    }
} 


