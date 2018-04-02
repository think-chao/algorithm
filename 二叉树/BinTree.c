#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50

typedef char DATA;   //����Ԫ����������
typedef struct ChainTree{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;	
}ChainBinTree;

//��ʼ��������
//�����е�һ���ڵ���Ϊ�������ĸ��ڵ�
ChainBinTree *BinTreeInit(ChainBinTree *node){
	if(node!=NULL){
		return node;
	}else{
		return NULL;
	}
}

//��ӽڵ㵽������ 
//��Ӷ����������ӽڵ㻹�����ӽڵ���Ҫѡ��
//bt�Ǹ��ڵ㣬node����Ҫ��ӵĽڵ㣬n�ж����� 
int BinTreeAdd(ChainBinTree *bt,ChainBinTree *node,int n){
	if(bt==NULL){
		 printf("����㲻���ڣ��������ø����!\n");
        return 0;
	}
	switch(n){
		case 1://��ӵ���ڵ�
			//.........��Ҫ���ӽڵ�Ϊ�ղ������ ����
			if(bt->left){
				printf("��������㲻Ϊ��!\n");
                return 0;
			}else{
				bt->left=node;
			}
		case 2:
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

//��ȡ��������������
ChainBinTree *BinTreeLeft(ChainBinTree *bt){
	if(bt){
		return bt->left;
	}else{
		return NULL;
	}
}

ChainBinTree *BinTreeRight(ChainBinTree *bt) //�������ӽ�� 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}

//������״̬���Ƿ�Ϊ��
int BinTreeIsEmpty(ChainBinTree *bt){
	if(bt){
		return 0;
	}else{
		return 1;
	}
}

//������������
/*
һ�������˼·�������ȣ���ͼ����whileѭ�����ж�bt->left==NULL�������
ʵ���ϲ��У���Ϊ��������Щ�ڵ����ӽڵ㣬��Щû�У���Щ�����ǹ��ɵ�
�����õ��ݹ��ж� 
*/
int BinTreeDepth(ChainBinTree *bt)
{
	int dep1,dep2;
	if(bt==NULL)
        return 0; //���ڿ��������Ϊ0
    else{
    	dep1=BinTreeDepth(bt->left);
		dep2=BinTreeDepth(bt->right);
		if(dep1>dep2){
			return dep1+1;
		}else{
			return dep2+1;
		}
	}
 } 
 
//�ڶ������в�����ؽڵ�
//˼·���ݹ� ***********************************************************************
// 

ChainBinTree *BinTreeFind(ChainBinTree *bt,DATA data){
	ChainBinTree *p;
	if(bt==NULL){
		return NULL;
	}else{
		if(bt->data==data){
			return bt;
		}else{
			if(p=BinTreeFind(bt->left,data)){
				return p;
			}else if(p=BinTreeFind(bt->right,data)){
				return p;
			}else{
				return NULL;
			}
		}
	}
}  
//**************************************************************************************

void BinTreeClear(ChainBinTree *bt) // ��ն�������ʹ֮��Ϊһ�ÿ���
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

//������һ������ڵ�����ָ���һ������ָ�룬�������һ����main��д
//�������һ�������Ա����õ��Ľڵ���в����������ӡ���� 
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
	if(bt){
		oper(bt);
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper); 
	} 
	return;
}

//���� 
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
	if(bt){
		BinTree_LDR(bt->left,oper);
		oper(bt);
		BinTree_LDR(bt->right,oper); 
	} 
	return;
}

void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //�������
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //������������� 
         BinTree_LRD(bt->right,oper); //�������������/
         oper(bt); //����������
     }
     return; 
}

//����������������ʺ��õݹ�
//�Ӹ��ڵ������ 
void BinTree_Level(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){

	ChainBinTree *p;
	ChainBinTree *q[QUEUE_MAXSIZE];
	int head,tail=0;
	
	if(bt){
		tail=(tail+1)%QUEUE_MAXSIZE;
		q[tail]=bt;
	}
	while(head!=tail){
		head=(head+1)%QUEUE_MAXSIZE;
		p=q[head];
		oper(p);
		if(bt->left!=NULL){
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->left;
		}
		
		if(bt->right!=NULL){
			tail=(tail+1)%QUEUE_MAXSIZE;
			q[tail]=p->right;
		}	
	} 
	return;
}


