#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef enum{
	SubTree,
	Thread				//���� 
}NodeFlag;

typedef char DATA;       //����Ԫ������ 

typedef struct ThreadTree{
	DATA data;
	NodeFlag lfalg;
	NodeFlag rflag;
	struct ThreadTree *left;
	struct ThreadTree *right;
}ThreadBinTree;

ThreadBinTree *Previous=NULL;     //ǰ�����ָ�� 




//����������������LDR���� �� 
//�ڱ��������������ӽڵ��ʱ���ҵ�����������ӽڵ��ʱ�򣬴����￪ʼ 
//����ȥ�������������������������ָ��
//���ڼ�������һ����ָ������ô

//1.���ȸ����ýڵ������ָ�����־��Ϊ����������
//	���ǣ���Ϊ��ʹ�����һ�����ӽڵ㣬���ܱ�֤��û�����ӽڵ�
//	���Ҷ����������������жϵ�ʱ�������������������ӽڵ� 
//2. Ȼ��Ͷ�������������������ˣ�����
//	 �����ܣ�����������������Ŀ�Ĳ������ڱ���Ǹ��ڵ���������ָ������������Ҫ�ҳ�ÿ���ڵ��ǰ�������˭
//	 �������������������ʱ�򣬵��˵����ڶ������ӽڵ��ʱ���������ڵ�û�����ӽڵ�Ļ������ʱ��������ӽڵ����Ϊ���нڵ��ǰ����
//	 Ȼ������ڵ���û�����ӽڵ��� 
 
void BinTreeThreading_LDR(ThreadBinTree *bt){
	if(bt){
		BinTreeThreading_LDR(bt->left);					//�ݹ���á���������������
		bt->lfalg=(bt->left)?SubTree:Thread;			//���ڵ����û�����������е㻰�����ö��ڵı�־λΪ������û�еĻ����ñ�־λΪ���� 
		bt->rflag=(bt->rflag)?SubTree:Thread;
		if(Previous){			
			if(Previous->rflag==Thread){
				Previous->right=bt; 					//��previous��������ָ����   Ϊɶһ����������ָ�����أ��� 
			}
			if(bt->lfalg==Thread){
				bt->left=Previous;						//��ǰ�ڵ��������ָ��ǰ�� 
			} 
		}
		Previous=bt; 									//��previous����¼֮ǰ���ʹ��Ľڵ㣬��Ϊ��һ���ڵ��ǰ�� 
		BinTreeThreading_LDR(bt->right);	 
	}
} 


//���Һ�̽ڵ�
//����ýڵ��������Ϊ�գ�Ҳ����������������ֱ�ӷ���node->right() 
//������ǿյĻ�����ô�ýڵ�ĺ�̽ڵ�һ��Ϊ�ýڵ�����������������²��ҵĵ�һ��û���������Ľڵ�Ϊֹ 
ThreadBinTree *BinTreeNext_LDR(ThreadBinTree *bt){
	ThreadBinTree *nextnode;
	if(!bt)	return NULL;
	if(bt->rflag==Thread){
		return bt->right;
	}else{
		nextnode=bt->right;
		while(nextnode->lfalg==SubTree){
			nextnode=nextnode->left;
		}
		return nextnode;
	}
} 


//����ǰ���ڵ�(�ڵ�����ָ��ǰ��)
//�����жϽڵ��������Ƿ�Ϊ�գ�����ǵĻ���ֱ�ӷ���node->right
//�����������Ϊ�� ,�����ýڵ�������������������ҽڵ㿪ʼ�ң�ֱ���ҵ��Ľڵ���ұ�־��Ϊ����Ϊֹ 

ThreadBinTree *BinTreePrevious_LDR(ThreadBinTree *bt){
	ThreadBinTree *prenode;
	if(!bt)	return NULL;
	if(bt->lfalg==Thread){
		return bt->left;
	}else{
		prenode=bt->left;
		while(prenode->rflag==SubTree){
			prenode=prenode->right;
		}
		return prenode;
	}	
} 


//��������������
void ThreadBinTree_LDR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)){
	if(bt){
		while(bt->lfalg==SubTree){
			bt=bt->left;
		}
		do{
			oper(bt);
			bt=BinTreeNext_LDR(bt);
		}while(bt);
	}
} 
//*************************************************************************
//*************************************************************************
//*************************************************************************
//*************************************************************************
//*************************************************************************
//*************************************************************************
//*************************************************************************
//*************************************************************************

ThreadBinTree *BinTreeInit(ThreadBinTree *node) //��ʼ������������� 
{
     if(node!=NULL) //������������㲻Ϊ�� 
         return node;
     else
         return NULL;
}

int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //������ݵ������� 
//btΪ����㣬nodeΪ�ӽ��,n=1��ʾ�����������n=2��ʾ��������� 
{
    if(bt==NULL)
    {
        printf("����㲻���ڣ��������ø����!\n");
        return 0;
    } 
    switch(n)
    {
        case 1: //��ӵ����� 
            if(bt->left) //��������Ϊ�� 
            {
                printf("��������㲻Ϊ��!\n");
                return 0;
            }else
                bt->left=node;
            break;
        case 2://��ӵ��ҽ��
            if( bt->right) //��������Ϊ�� 
            {
                printf("��������㲻Ϊ��!\n"); 
                return 0;
            }else
                bt->right=node;
            break;
        default:
            printf("��������!\n");
            return 0;
    }
    return 1;
}

ThreadBinTree *BinTreeLeft(ThreadBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ThreadBinTree *bt) //���������Ƿ�Ϊ�գ�Ϊ���򷵻�1,���򷵻�0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ThreadBinTree *bt) //����������
{
    int dep1,dep2;
    if(bt==NULL)
        return 0; //���ڿ��������Ϊ0
    else
    {
        dep1 = BinTreeDepth(bt->left); //��������� (�ݹ����)
        dep2 = BinTreeDepth(bt->right); //��������� (�ݹ����)
        if(dep1>dep2)
           return dep1 + 1; 
        else
            return dep2 + 1; 
    } 
} 
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data) //�ڶ������в���ֵΪdata�Ľ�� 
{
    ThreadBinTree *p;
    if(bt==NULL)
        return NULL;
    else
    {
        if(bt->data==data)
            return bt; 
        else{ // �ֱ������������ݹ���� 
            if(p=BinTreeFind(bt->left,data))
                return p;
            else if(p=BinTreeFind(bt->right, data)) 
                return p;
            else
                return NULL; 
        } 
    } 
} 
void BinTreeClear(ThreadBinTree *bt) // ��ն�������ʹ֮��Ϊһ�ÿ���
{
     if(bt)
     {
         BinTreeClear(bt->left); //��������� 
         BinTreeClear(bt->right);//��������� 
         free(bt);//�ͷŵ�ǰ�����ռ�ڴ� 
         bt=NULL;
     }
     return; 
}
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))  //������� 
{     
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         oper(bt); //����������� 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p))  //������� 
{
     if(bt)//����Ϊ�գ���ִ�����²��� 
     {
         BinTree_LDR(bt->left,oper); //�������������
         oper(bt);//���������� 
         BinTree_LDR(bt->right,oper); //�������������/
     }
     return; 
} 
void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //�������
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //������������� 
         BinTree_LRD(bt->right,oper); //�������������/
         oper(bt); //����������
     }
     return; 
} 
void BinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //������� 
{
     ThreadBinTree *p;
     ThreadBinTree *q[QUEUE_MAXSIZE]; //����һ��˳��ջ 
     int head=0,tail=0;//���ס���β��� 
     if(bt)//������ָ�벻Ϊ��     
     {
         tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����ж�β��� 
         q[tail] = bt;//����������ָ�����
     }
     while(head!=tail) //���в�Ϊ�գ�����ѭ�� 
     {
         head=(head+1)%QUEUE_MAXSIZE; //����ѭ�����еĶ������ 
         p=q[head]; //��ȡ����Ԫ�� 
         oper(p);//�������Ԫ�� 
         if(p->left!=NULL) //������������������������ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->left;//��������ָ����� 
         }
                 
         if(p->right!=NULL)//���������Һ��ӣ����Һ��ӽ��ָ����� 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//����ѭ�����еĶ�β��� 
             q[tail]=p->right;//��������ָ����� 
         }
     }
     return; 
}




 


 
