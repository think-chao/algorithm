#include<stdlib.h>
#include<stdio.h>
#define SIZE 50

typedef struct{
	char name[15];
	int age;
}DATA;

#include "stack.h"

int main(){
	Stack *stack;
	DATA data,data1;
	stack=StackInit();
	printf("入栈操作：\n");
	printf("输入姓名 年龄进行入栈操作:"); 
    scanf("%s%d",data.name,&data.age);
    StackPush(stack,data);
    printf("输入姓名 年龄进行入栈操作:"); 
    scanf("%s%d",data.name,&data.age);
    StackPush(stack,data);
    printf("\n出栈操作：\n按任意键进行出栈操作:");
    getch();
    
    data1=StackPop(stack);
    printf("出栈的数据是(%s,%d)\n" ,data1.name,data1.age);        
    printf("再按任意键进行出栈操作:");
    getch();
    data1=StackPop(stack);
    printf("出栈的数据是(%s,%d)\n" ,data1.name,data1.age); 
    StackFree(stack); //释放栈所占用的空间 
    getch();
    return 0;
}
