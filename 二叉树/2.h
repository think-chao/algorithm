/*typedef struct ChainTree{
	DATA data;
	struct ChainTree *left;
	struct ChainTree *right;	
}ChainTreeType;
ChainTreeType *root=NULL;   //������������ڵ�ָ��*/

typedef struct ChainTree{
	DATA data;
	struct ChainTree *right;
	struct ChainTree *left;
	struct ChainTree *parent;
};
ChainTreeType *root=NULL;




