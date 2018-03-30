/*
	栈的数据结构：栈内数据，栈顶（标号） 
*/ 
typedef struct{
	DATA data[SIZE+1]; 
	int top;
}Stack;

//初始化栈：
//首先申请一片 内存保存栈中数据
//设置栈顶top=0
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

//入栈操作 
// 参数：数据， 
// top+1
// 判断栈是否已满 
int StackPush(Stack *s,DATA data){
	if(s->top>=SIZE){
		printf("栈溢出\n");
		return 0;
	}else{
		s->data[++s->top]=data;
		return 1; 
	}
} 

//判断栈是否为空
//top=0？？

int StackIsEmpty(Stack *s){
	return(s->top==0);
}

int StackIsFull(Stack *s){
	return(s->top==SIZE);
}
//清空栈 
void StackClear(Stack *s){
	s->top=0;
} 

//出栈操作：top--??
//出栈时候栈内是否还有元素？？ 
//返回所出栈的内容DATA 
DATA StackPop(Stack *s){
	if(s->top==0){
		printf("栈为空\n");
		exit(0);
	}else{
		return(s->data[s->top--]);
	} 
}

//获取栈顶元素
//栈内是否有元素？？
//返回的是DATA

DATA StackPeek(Stack *s){
	if(s->top==0){
		printf("栈为空\n");
		exit(0);
	}else{
		return(s->data[s->top]);
	}
}
 
