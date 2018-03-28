/*
	����˳���.h�������ĺ�����ʵ�֣�Ҳ����˵����һ�����������ļ� 
*/ 

//1.��ʼ�����ݽṹ��˳�����Ϊ0 
void SeqListInit(SeqListType *SL)
{
	SL->ListLen=0;	//SL�������ݽṹ��һ�����������Է������ݽṹ���Ԫ�� 
}

//2.��ȡ˳���Ԫ�صĸ��� 
int SeqListLength(SeqListType *SL)
{
	return (SL->ListLen);
}

//3.��ӽڵ� 
int  SeqListAdd(SeqListType *SL,DATA data)
{
	if(SL->ListLen>=MAXSIZE)
	{
		printf("˳����Ѿ�����");
		return 0; 
	}
	SL->ListData[++SL->ListLen]=data;          //������ݵ�˳����ĩβ 
	return 1; 
}

//4.����ڵ㵽��n��λ�� 
//�����жϲ����λ���Ƿ����Ҫ��
//�ټ��˳����Ƿ��Լ����� 
//����n�ڵ�֮ǰ�����ݲ��ñ䶯
//���µ�������ӵ�N�ڵ�֮��ԭ��N�ڵ�����������Ӧ�ĺ��� 
int SeqListInsert(SeqListType *SL,int n,DATA data)
{
	int i;
	if(SL->ListLen>=MAXSIZE)
	{
		printf("���ݱ��Ѿ����ˣ����ܲ���");
		return 0;
	}
	if(n<1||n>SL->ListLen-1)
	{
		printf("����ڵ����Ŵ���\n");
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

//5.ɾ���ڵ㣨����ӽڵ�Ͳ���ڵ����ƣ�
int SeqListDelet(SeqListType *SL,int n)
{
	int i;
	if(SL->ListLen==0)
	{
		printf("���ݱ�Ϊ�գ��޷�ɾ��\n");
		return 0; 
	}
	if(n<1||n>SL->ListLen+1)
	{
		printf("Ҫɾ���Ľڵ����Ŵ���\n");
		return 0;
	}
	for(i=n;i<SL->ListLen;i++)
	{
		SL->ListData[i]=SL->ListData[i+1];
	}
	SL->ListLen--;
	return 1;
} 

//6.���Ҷ�Ӧ�ڵ� 
DATA *SeqListFindByNum(SeqListType *SL,int n)
{
	if(n<1||n>SL->ListLen+1)
	{
		printf("Ҫ���ҵĽڵ����Ŵ���\n");
		return 0;
	}
	return &(SL->ListData[n]);
}


