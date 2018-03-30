#define QUEUEMAX 15
typedef struct{
	DATA data[QUEUEMAX];
	int head;
	int tail;
}CycQueue;

//ѭ�����г�ʼ��
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
void CycQueueFree(CycQueue *q) //�ͷŶ���
{
    if (q!=NULL)
        free(q);
}  

//�����Ƿ�Ϊ��
int CycQueueIsEmpty(CycQueue *q){
	return (q->head==q->tail);
}
//�����Ƿ����� 
int CycQueueIsFull(CycQueue *q){
	return ((q->tail+1)%QUEUEMAX==q->head);
}

//���,�Ӷ�β��� 
int CycQueueIn(CycQueue *q,DATA data){
	if((q->tail+1)%QUEUEMAX==q->head){
		printf("�����Ѿ�����\n");
		return 0;
	}else{
		q->tail=(q->tail+1)%QUEUEMAX;
		q->data[q->tail]=data;
		return 1;
	}
} 

//����,�Ӷ��׳��� 
//���ӵ�ʱ��head�᲻�ϵĺ���,���Ƶ�head��tail���ʱ��,���е�Ԫ�ؾͶ�������
//����head�Ƶ���n,tail�����1 
DATA *CycQueueOut(CycQueue *q){
	if(q->head==q->tail){
		return NULL;
	}else{
		q->head=(q->head+1)%QUEUEMAX;
		return &(q->data[q->head]);
	}
} 

int CycQueueLen(CycQueue *q) //��ȡ���г��� 
{
    int n;
    n=q->tail-q->head;
    if(n<0)
        n=QUEUEMAX+n;
    return n;
}
DATA *CycQueuePeek(CycQueue *q) //��ȡ�Ӷ��е�1��λ�õ�����
{
    if(q->head==q->tail)
    {
        printf("�����Ѿ�Ϊ��!\n");
        return NULL; 
    }else{
        return &(q->data[(q->head+1)%QUEUEMAX]);
    }
} 


