#include<stdio.h>
typedef struct
{
	char key[15];
	char name[20];
	int age;
} DATA;

#include "顺序表.h"
#include "顺序表.cpp"

int SeqListAll(SeqListType *SL)
{
	int i;
	for(i=1;i<SL->ListLen;i++)
	{
		printf("(%s,%s,%d)\n",SL->ListData[i].key,SL->ListData[i].name,SL->ListData[i].age) ;
	} 
 } 
 
int main(){
	int i;
	SeqListType SL;
	DATA data,*data1;
	char key[15];
	
	SeqListInit(&SL);
	do{
		printf("输入需要添加的数据（学号，姓名，年龄）");
		//fflush(stdin);
		scanf("%s%s%d",&data.key,&data.name,&data.age); 
		
		//设置退出条件 
		
		if(data.age)
		{
			if(!SeqListAdd(&SL,data))		//若添加节点失败
				break; 
		}else
		{
			break;
		}
	}while(1);
	
	printf("\n顺序表中的节点有\n");
	SeqList(&SL);//调用函数显示所有节点数据
	
	//fflush(stdin);
	printf("想要取出的节点的序号：");
	scanf("%d",&i);
	data1=SeqListFindByNum(&SL,i);
	if(data1)
	{
		printf("第%d个节点为：(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);
	} 
	return 0;
	
	
}
