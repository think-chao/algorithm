#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50

typedef char DATA;   //定义元素数据类型
typedef struct ChainTree{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;	
}ChainBinTree;

//初始化二叉树
//将已有的一个节点作为二叉树的根节点
ChainBinTree *BinTreeInit(ChainBinTree *node){
	if(node!=NULL){
		return node;
	}else{
		return NULL;
	}
}

//添加节点到二叉树 
//添加二叉树的左子节点还是右子节点需要选择
//bt是父节点，node是需要添加的节点，n判断左右 
int BinTreeAdd(ChainBinTree *bt,ChainBinTree *node,int n){
	if(bt==NULL){
		 printf("父结点不存在，请先设置父结点!\n");
        return 0;
	}
	switch(n){
		case 1://添加到左节点
			//.........需要左子节点为空才能添加 ，坑
			if(bt->left){
				printf("左子树结点不为空!\n");
                return 0;
			}else{
				bt->left=node;
			}
		case 2:
			if( bt->right) //右子树不为空 
            {
                printf("右子树结点不为空!\n"); 
                return 0;
            }else
                bt->right=node;
            break;
        default:
            printf("参数错误!\n");
            return 0;
	}
	return 1; 
} 

//获取二叉树左右子树
ChainBinTree *BinTreeLeft(ChainBinTree *bt){
	if(bt){
		return bt->left;
	}else{
		return NULL;
	}
}

ChainBinTree *BinTreeRight(ChainBinTree *bt) //返回右子结点 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}

//二叉树状态：是否为空
int BinTreeIsEmpty(ChainBinTree *bt){
	if(bt){
		return 0;
	}else{
		return 1;
	}
}

//计算二叉树深度
/*
一个错误的思路来求解深度，企图利用while循环来判断bt->left==NULL这个条件
实际上不行，因为二叉树有些节点有子节点，有些没有，这些都不是规律的
所以用到递归判断 
*/
int BinTreeDepth(ChainBinTree *bt)
{
	int dep1,dep2;
	if(bt==NULL)
        return 0; //对于空树，深度为0
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
 
//在二叉树中查找相关节点
//思路：递归 ***********************************************************************
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

void BinTreeClear(ChainBinTree *bt) // 清空二叉树，使之变为一棵空树
{
     if(bt)
     {
         BinTreeClear(bt->left); //清空左子树 
         BinTreeClear(bt->right);//清空右子树 
         free(bt);//释放当前结点所占内存 
         bt=NULL;
     }
     return; 
}

//参数是一个二叉节点类型指针和一个函数指针，这个函数一般在main里写
//这个函数一般用来对遍历得到的节点进行操作，比如打印数据 
void BinTree_DLR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
	if(bt){
		oper(bt);
		BinTree_DLR(bt->left,oper);
		BinTree_DLR(bt->right,oper); 
	} 
	return;
}

//中序 
void BinTree_LDR(ChainBinTree *bt,void (*oper)(ChainBinTree *p)){
	if(bt){
		BinTree_LDR(bt->left,oper);
		oper(bt);
		BinTree_LDR(bt->right,oper); 
	} 
	return;
}

void BinTree_LRD(ChainBinTree *bt,void (*oper)(ChainBinTree *p)) //后序遍历
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //后序遍历左子树 
         BinTree_LRD(bt->right,oper); //后序遍历右子树/
         oper(bt); //处理结点数据
     }
     return; 
}

//二叉树按层遍历不适合用递归
//从根节点出发， 
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


