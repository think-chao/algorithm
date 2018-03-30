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
	printf("��ջ������\n");
	printf("�������� ���������ջ����:"); 
    scanf("%s%d",data.name,&data.age);
    StackPush(stack,data);
    printf("�������� ���������ջ����:"); 
    scanf("%s%d",data.name,&data.age);
    StackPush(stack,data);
    printf("\n��ջ������\n����������г�ջ����:");
    getch();
    
    data1=StackPop(stack);
    printf("��ջ��������(%s,%d)\n" ,data1.name,data1.age);        
    printf("�ٰ���������г�ջ����:");
    getch();
    data1=StackPop(stack);
    printf("��ջ��������(%s,%d)\n" ,data1.name,data1.age); 
    StackFree(stack); //�ͷ�ջ��ռ�õĿռ� 
    getch();
    return 0;
}
