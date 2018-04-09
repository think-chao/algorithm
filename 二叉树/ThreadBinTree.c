#include <stdio.h> 
#include <stdlib.h> 
#define QUEUE_MAXSIZE 50
typedef enum{
	SubTree,
	Thread				//线索 
}NodeFlag;

typedef char DATA;       //定义元素类型 

typedef struct ThreadTree{
	DATA data;
	NodeFlag lfalg;
	NodeFlag rflag;
	struct ThreadTree *left;
	struct ThreadTree *right;
}ThreadBinTree;

ThreadBinTree *Previous=NULL;     //前驱结点指针 




//创建线索二叉树（LDR中序 ） 
//在遍历左子树的左子节点的时候，找到最下面的左子节点的时候，从这里开始 
//就是去遍历二叉树，用线索来代替空指针
//现在假设遇到一个空指针了那么

//1.首先给定该节点的左右指针域标志都为线索？？？
//	不是，因为即使是最后一个左子节点，不能保证其没有右子节点
//	而且对右子树进行中序判断的时候，右子树可能又有左子节点 
//2. 然后就对右子树进行中序遍历了？？？
//	 还不能，创建线索二叉树的目的不仅在于标记那个节点的左或者又指针是线索，还要找出每个节点的前驱后继是谁
//	 假设中序遍历左子树的时候，到了倒数第二个左子节点的时候，如果这个节点没有左子节点的话，这个时候这个左子节点就作为所有节点的前驱了
//	 然后看这个节点有没有右子节点了 
 
void BinTreeThreading_LDR(ThreadBinTree *bt){
	if(bt){
		BinTreeThreading_LDR(bt->left);					//递归调用。将左子树线索化
		bt->lfalg=(bt->left)?SubTree:Thread;			//看节点的有没有左子树，有点话就设置对于的标志位为子树，没有的话设置标志位为线索 
		bt->rflag=(bt->rflag)?SubTree:Thread;
		if(Previous){			
			if(Previous->rflag==Thread){
				Previous->right=bt; 					//将previous的右线索指向后继   为啥一定是右线索指向后继呢？？ 
			}
			if(bt->lfalg==Thread){
				bt->left=Previous;						//当前节点的左线索指向前驱 
			} 
		}
		Previous=bt; 									//用previous来记录之前访问过的节点，作为下一个节点的前驱 
		BinTreeThreading_LDR(bt->right);	 
	}
} 


//查找后继节点
//如果该节点的右子树为空，也就是他就是线索，直接返回node->right() 
//如果不是空的话，那么该节点的后继节点一定为该节点的右子树沿左链往下查找的第一个没有左子树的节点为止 
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


//查找前驱节点(节点的左边指向前驱)
//首先判断节点左子树是否为空，如果是的话，直接返回node->right
//如果左子树不为空 ,则进入该节点的左子树，该子树的右节点开始找，直到找到的节点的右标志不为子树为止 

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


//遍历线索二叉树
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

ThreadBinTree *BinTreeInit(ThreadBinTree *node) //初始化二叉树根结点 
{
     if(node!=NULL) //若二叉树根结点不为空 
         return node;
     else
         return NULL;
}

int BinTreeAddNode(ThreadBinTree *bt,ThreadBinTree *node,int n) //添加数据到二叉树 
//bt为父结点，node为子结点,n=1表示添加左子树，n=2表示添加右子树 
{
    if(bt==NULL)
    {
        printf("父结点不存在，请先设置父结点!\n");
        return 0;
    } 
    switch(n)
    {
        case 1: //添加到左结点 
            if(bt->left) //左子树不为空 
            {
                printf("左子树结点不为空!\n");
                return 0;
            }else
                bt->left=node;
            break;
        case 2://添加到右结点
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

ThreadBinTree *BinTreeLeft(ThreadBinTree *bt) //返回左子结点 
{
    if(bt)
        return bt->left;
    else
        return NULL;
}
ThreadBinTree *BinTreeRight(ThreadBinTree *bt) //返回右子结点 
{
    if(bt)
        return bt->right;
    else
        return NULL;
}
int BinTreeIsEmpty(ThreadBinTree *bt) //检查二叉树是否为空，为空则返回1,否则返回0 
{
    if(bt)
        return 0;
    else
        return 1;
} 
int BinTreeDepth(ThreadBinTree *bt) //求二叉树深度
{
    int dep1,dep2;
    if(bt==NULL)
        return 0; //对于空树，深度为0
    else
    {
        dep1 = BinTreeDepth(bt->left); //左子树深度 (递归调用)
        dep2 = BinTreeDepth(bt->right); //右子树深度 (递归调用)
        if(dep1>dep2)
           return dep1 + 1; 
        else
            return dep2 + 1; 
    } 
} 
ThreadBinTree *BinTreeFind(ThreadBinTree *bt,DATA data) //在二叉树中查找值为data的结点 
{
    ThreadBinTree *p;
    if(bt==NULL)
        return NULL;
    else
    {
        if(bt->data==data)
            return bt; 
        else{ // 分别向左右子树递归查找 
            if(p=BinTreeFind(bt->left,data))
                return p;
            else if(p=BinTreeFind(bt->right, data)) 
                return p;
            else
                return NULL; 
        } 
    } 
} 
void BinTreeClear(ThreadBinTree *bt) // 清空二叉树，使之变为一棵空树
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
void BinTree_DLR(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p))  //先序遍历 
{     
     if(bt)//树不为空，则执行如下操作 
     {
         oper(bt); //处理结点的数据 
         BinTree_DLR(bt->left,oper);
         BinTree_DLR(bt->right,oper);
     }
     return; 
} 
void BinTree_LDR(ThreadBinTree *bt,void(*oper)(ThreadBinTree *p))  //中序遍历 
{
     if(bt)//树不为空，则执行如下操作 
     {
         BinTree_LDR(bt->left,oper); //中序遍历左子树
         oper(bt);//处理结点数据 
         BinTree_LDR(bt->right,oper); //中序遍历右子树/
     }
     return; 
} 
void BinTree_LRD(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //后序遍历
{
     if(bt)
     {
         BinTree_LRD(bt->left,oper); //后序遍历左子树 
         BinTree_LRD(bt->right,oper); //后序遍历右子树/
         oper(bt); //处理结点数据
     }
     return; 
} 
void BinTree_Level(ThreadBinTree *bt,void (*oper)(ThreadBinTree *p)) //按层遍历 
{
     ThreadBinTree *p;
     ThreadBinTree *q[QUEUE_MAXSIZE]; //定义一个顺序栈 
     int head=0,tail=0;//队首、队尾序号 
     if(bt)//若队首指针不为空     
     {
         tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列队尾序号 
         q[tail] = bt;//将二叉树根指针进队
     }
     while(head!=tail) //队列不为空，进行循环 
     {
         head=(head+1)%QUEUE_MAXSIZE; //计算循环队列的队首序号 
         p=q[head]; //获取队首元素 
         oper(p);//处理队首元素 
         if(p->left!=NULL) //若结点存在左子树，则左子树指针进队 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列的队尾序号 
             q[tail]=p->left;//将左子树指针进队 
         }
                 
         if(p->right!=NULL)//若结点存在右孩子，则右孩子结点指针进队 
         {
             tail=(tail+1)%QUEUE_MAXSIZE;//计算循环队列的队尾序号 
             q[tail]=p->right;//将右子树指针进队 
         }
     }
     return; 
}




 


 
