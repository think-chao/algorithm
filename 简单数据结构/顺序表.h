#include<stdio.h>
#include<string.h>

#define MAXSIZE 100

typedef struct					//������һ��˳���ṹ 
{
	DATA ListData[MAXSIZE+1];   //�����ﲻ������ĵ�0��Ŀ 
	int ListLen;				//���ݽṹ�е�Ԫ�� 
}SeqListType;					//�����ݽṹ������

void SeqListInit(SeqListType *SL);			//һ����������ʼ��˳���
int SeqListLength(SeqListType *SL);			//����˳����Ԫ������
int SeqListAdd(SeqListType *SL,DATA data);	//��˳��������Ԫ��
int SeqListInsert(SeqListType *SL,int n,DATA data) ;
int SeqListDelet(SeqListType *SL,int n);	//ɾ��˳����е�Ԫ��
DATA *SeqListFindByNum(SeqListType *SL,int n);
int SeqListFindByCont(SeqListType *SL,char *key);
int SeqListAll(SeqListType *SL);				//����˳���������Ԫ��

 

 
