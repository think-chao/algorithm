#include <stdlib.h>
typedef struct Node
{
    DATA data;				//数据域
    struct Node *next;
}ChainListType;
//在定义该结构体变量的时候,就要ChainListType head;
//如果定义的是指针变量？啥事指针变量?首先指针其实 就是一个用来存放地址的容器，指针指向哪其实就是这个变量里面的内容就是那的地址

ChainListType *ChainListAddEnd(ChainListType *head,DATA data);  //添加结点到链表末尾 
ChainListType *ChainListAddFirst(ChainListType *head,DATA data);  //添加结点到链表首部 
ChainListType *ChainListFind(ChainListType *head,char *key); //按关键字在链表中查找内容 
ChainListType *ChainListInsert(ChainListType *head,char *findkey,DATA data);  //插入结点到链表指定位置 
int ChainListDelete(ChainListType *head,char *key);//删除指定关键字的结点 
int ChainListLength(ChainListType *head);//获取链表结点数量 

