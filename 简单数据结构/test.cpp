#include<stdio.h>
typedef struct
{
	char key[15];
	char name[20];
	int age;
} DATA;

#include "˳���.h"
#include "˳���.cpp"

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
		printf("������Ҫ��ӵ����ݣ�ѧ�ţ����������䣩");
		//fflush(stdin);
		scanf("%s%s%d",&data.key,&data.name,&data.age); 
		
		//�����˳����� 
		
		if(data.age)
		{
			if(!SeqListAdd(&SL,data))		//����ӽڵ�ʧ��
				break; 
		}else
		{
			break;
		}
	}while(1);
	
	printf("\n˳����еĽڵ���\n");
	SeqList(&SL);//���ú�����ʾ���нڵ�����
	
	//fflush(stdin);
	printf("��Ҫȡ���Ľڵ����ţ�");
	scanf("%d",&i);
	data1=SeqListFindByNum(&SL,i);
	if(data1)
	{
		printf("��%d���ڵ�Ϊ��(%s,%s,%d)\n",i,data1->key,data1->name,data1->age);
	} 
	return 0;
	
	
}
