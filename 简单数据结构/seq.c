/*
	这是顺序表.h中申明的函数的实现，也就是说这是一个操作函数文件 
*/ 

//1.初始化数据结构，顺序表长度为0 
void SeqListInit(SeqListType *SL)
{
	SL->ListLen=0;	//SL就是数据结构的一个对象，它可以访问数据结构里的元素 
}

//2.获取顺序表元素的个数 
int SeqListLength(SeqListType *SL)
{
	return (SL->ListLen);
}

//3.添加节点 
int  SeqListAdd(SeqListType *SL,DATA data)
{
	if(SL->ListLen>=MAXSIZE)
	{
		printf("顺序表已经满了");
		return 0; 
	}
	SL->ListData[++SL->ListLen]=data;          //添加数据到顺序表的末尾 
	return 1; 
}

//4.插入节点到第n个位置 
//首先判断插入的位置是否符合要求
//再检查顺序表是否以及满了 
//对于n节点之前的数据不用变动
//将新的数据添加到N节点之后，原来N节点后面的数据相应的后移 
int SeqListInsert(SeqListType *SL,int n,DATA data)
{
	int i;
	if(SL->ListLen>=MAXSIZE)
	{
		printf("数据表已经满了，不能插入");
		return 0;
	}
	if(n<1||n>SL->ListLen-1)
	{
		printf("插入节点的序号错误\n");
		return 0;
	}
	for(i=SL->ListLen;i>=n;i--)
	{
		SL->ListData[i+1]=SL->ListData[i]; 		
	}
	SL->ListData[n]=data;
	SL->ListLen++;
	return 1;	
} 

//5.删除节点（和添加节点和插入节点相似）
int SeqListDelet(SeqListType *SL,int n)
{
	int i;
	if(SL->ListLen==0)
	{
		printf("数据表为空，无法删除\n");
		return 0; 
	}
	if(n<1||n>SL->ListLen+1)
	{
		printf("要删除的节点的序号错误\n");
		return 0;
	}
	for(i=n;i<SL->ListLen;i++)
	{
		SL->ListData[i]=SL->ListData[i+1];
	}
	SL->ListLen--;
	return 1;
} 

//6.查找对应节点 
DATA *SeqListFindByNum(SeqListType *SL,int n)
{
	if(n<1||n>SL->ListLen+1)
	{
		printf("要查找的节点的序号错误\n");
		return 0;
	}
	return &(SL->ListData[n]);
}


