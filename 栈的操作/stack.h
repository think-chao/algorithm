/*
	ջ�����ݽṹ��ջ�����ݣ�ջ������ţ� 
*/ 
typedef struct{
	DATA data[SIZE+1]; 
	int top;
}Stack;

//��ʼ��ջ��
//��������һƬ �ڴ汣��ջ������
//����ջ��top=0
Stack *StackInit(){
	Stack *s;
	if(s=(Stack *)malloc(sizeof(Stack))){
		s->top=0;
		return s;
	}else{
		return NULL;
	}
}

void StackFree(Stack *s){
	if(s)
		free(s);
}

//��ջ���� 
// ���������ݣ� 
// top+1
// �ж�ջ�Ƿ����� 
int StackPush(Stack *s,DATA data){
	if(s->top>=SIZE){
		printf("ջ���\n");
		return 0;
	}else{
		s->data[++s->top]=data;
		return 1; 
	}
} 

//�ж�ջ�Ƿ�Ϊ��
//top=0����

int StackIsEmpty(Stack *s){
	return(s->top==0);
}

int StackIsFull(Stack *s){
	return(s->top==SIZE);
}
//���ջ 
void StackClear(Stack *s){
	s->top=0;
} 

//��ջ������top--??
//��ջʱ��ջ���Ƿ���Ԫ�أ��� 
//��������ջ������DATA 
DATA StackPop(Stack *s){
	if(s->top==0){
		printf("ջΪ��\n");
		exit(0);
	}else{
		return(s->data[s->top--]);
	} 
}

//��ȡջ��Ԫ��
//ջ���Ƿ���Ԫ�أ���
//���ص���DATA

DATA StackPeek(Stack *s){
	if(s->top==0){
		printf("ջΪ��\n");
		exit(0);
	}else{
		return(s->data[s->top]);
	}
}
 
