/*
功能：：哈夫曼编码的实现： 
首先根据n个带权值的节点构建n个二叉树，每一个节点作为一个二叉树，其权值保存在节点中，左右子树都是空。
	在这n个二叉树中找到权值最小的两棵树，用这两课树作为左右子树构造新的二叉树，将原来两个数的权值相加作为新的二叉树根节点的权值
	将上步找到的权值最小的两颗二叉树排除在下一次查找范围，重复2,3直到只有一颗树为止，这样就可以得到一颗哈夫曼树
*/ 


//思路：
// 在内存中分配一片连续的区域，用来保存哈夫曼二叉树，可以将这部分内存区域作为一个一维数组
// 然后通过数组的下表序号访问不同的二叉树节点
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int weight;
	int parent;			//父节点序号 
	int left;			//左子树序号	 
	int right;			//右子树序号 
}HuffmanTree;

typedef char *HufumanCode;		//哈夫曼编码指针，用HufmanCode来代替char字符指针


void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2){
	
	
}

//ht是一个指向哈夫曼树的指针，n代表创建的哈夫曼树的叶节点个数，w是个指针，指向了一个存放所有节点权重的数组 
//所以叶节点书目为n，总结点个数为2n-1
 
void CreatTree(HufmanTree *ht,int n,int *w){
	int i,m=2*n-1;			//根据哈夫曼树的叶子节点确定总结点的数目 
	int bt1,bt2;			//二叉树节点的序号 
	if(n<1)	return NULL;
	
	for(i=1;i<=n;++i){
		ht[i].weight=w[i-1];
		ht[i].parent=0;
		ht[i].left=0;
		ht[i].right=0;
	}
	
	//哈夫曼树除了叶节点其他节点的权值都是0 
	
	for(;i<=m;++i){
		ht[i].weight=0;
		ht[i].parent=0;
		ht[i].left=0;
		ht[i].right=0;
	} 
	
	//现在ht[i]表示每一个节点了 

	for(i=n+1;i<=m;i++){
		//首先找到两个权重最小的节点，因为最开始大家都是只有一个根节点的二叉树 
		// 找两个权值最小的节点必须从有有权值的n个节点中选择 
		//  
		SelcetNode(ht,i-1,&bt1,&bt2);
	}
} 
