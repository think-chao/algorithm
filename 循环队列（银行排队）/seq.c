#define QUEMAX 15
typedef struct
{
	DATA data[QUEMAX];
	int head;
	int tail; //�����ͷβ��� 
}SeqQueue;

//����һ��ָ������ĺ���,˵����ָ�����һ����ŵ�ַ�ı�������
//����Ȼ,��������˿ռ�,��ô�ͷ�����һƬ�ռ����ʼ��ַ�� 
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

//��� 
int SeqQueueIn(SeqQueue *q,DATA data)
{
	if(q->tail==QUEMAX){
		printf("�����Ѿ�����\n");
		return(0);
	}else{
		q->data[q->tail++]=data;
		return(1);
	}
}
DATA *SeqQueueOut(SeqQueue *q){
	if(q->head==0){
		pritnf("�����ǿյ�\n");
		return NULL;
	}else{
		return &(q->data[q->head++]);
	}
}

//��ȡ��ͷ���� 
DATA *SeqQueuePeek(SeqQueue *q){
	if(SeqQueueIsEmpty(q)){
		pritnf("���п�\n");
		return NULL;
	}else{
		return &(q->data[q->head]);
	}
	
} 
 
