/*typedef struct ChainTree{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;	
}ChainTreeType;
ChainTreeType *root=NULL;   //定义二叉树根节点指针*/

typedef struct ChainTree{
	DATA data;
	struct ChainTree *right;
	struct ChainTree *left;
	struct ChainTree *parent;
};
ChainTreeType *root=NULL;




