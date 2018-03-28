#include<stdio.h>
#include<string.h>

#define MAXSIZE 100

typedef struct					//定义了一个顺序表结构 
{
	DATA ListData[MAXSIZE+1];   //在这里不用数组的第0项目 
	int ListLen;				//数据结构中的元素 
}SeqListType;					//该数据结构的名字

void SeqListInit(SeqListType *SL);			//一个函数，初始化顺序表
int SeqListLength(SeqListType *SL);			//返回顺序表的元素数量
int SeqListAdd(SeqListType *SL,DATA data);	//往顺序表中添加元素
int SeqListInsert(SeqListType *SL,int n,DATA data) ;
int SeqListDelet(SeqListType *SL,int n);	//删除顺序表中的元素
DATA *SeqListFindByNum(SeqListType *SL,int n);
int SeqListFindByCont(SeqListType *SL,char *key);
int SeqListAll(SeqListType *SL);				//遍历顺序表中所有元素

 

 
