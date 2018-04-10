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

typedef char *HuffmanCode;		//哈夫曼编码指针，用HufmanCode来代替char字符指针

//从n个节点中选取权值最小的两个 ,而且要求父节点为空 
void SelectNode(HuffmanTree *ht,int n,int *bt1,int *bt2){
	int i; 
	HuffmanTree *ht1,*ht2,*t;
	ht1=NULL;
	ht2=NULL;
	for(i=1;i<=n;i++){
		if(!ht[i].parent){
			if(ht1==NULL){
				ht1=ht+i;
				continue;
			}
			if(ht2==NULL){
				ht2=ht+i;
				if(ht1->weight>ht2->weight){			//时钟保证ht1的 权值最小 
					t=ht2;
					ht2=ht1;
					ht1=t;							//这个时候就得让ht1指向ht2了 
				}
			}
			
			if(ht1&&ht2){
				if(ht[i].weight<=ht1->weight){		//这个时候说明ht1指向的不是最小权值的节点了 
													//这个时候和ht1指向的就是权值第二小的节点了
					ht2=ht1;
					ht1=ht+i; 	
				}else if(ht[i].weight<ht2->weight){
					ht2=ht+i;
				}
			}
		}
	}
	
	
	//获取最小节点的序号以及第二小节点的序号 
	if(ht1>ht2){
		*bt2=ht1-ht;
		*bt1=ht2-ht;
	}else{
		*bt1=ht1-ht;
		*bt2=ht2-ht;
	}
	
	
}

//ht是一个指向哈夫曼树的指针，n代表创建的哈夫曼树的叶节点个数，w是个指针，指向了一个存放所有节点权重的数组 
//所以叶节点书目为n，总结点个数为2n-1
 
void CreatTree(HuffmanTree *ht,int n,int *w){
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
	
	
	//此时需要计算非叶节点的权重了，因为选取两个权重最小的节点之后
	//需要根据这两个节点的权重之和组成一个二叉树，而这个二叉树的根节点也就是其中一个非叶节点 

	for(i=n+1;i<=m;++i){
		//首先找到两个权重最小的节点，因为最开始大家都是只有一个根节点的二叉树 
		// 找两个权值最小的节点必须从有有权值的n个节点中选择 
		//  
		//希望通过这个函数把找到的最小值的两个节点的序号的值赋值给bt1和bt2
		 
		SelcetNode(ht,i-1,&bt1,&bt2);
		ht[bt1].parent=i;
		ht[bt2].parent=i; 
		ht[i].left=bt1;
        ht[i].right=bt2;
	}
} 


void HuffmanCoding(HuffmanTree *ht,int n,HuffmanCode *hc)//,char *letters)
{
     char *cd;
     int start,i;
     int current,parent;    
     cd=(char*)malloc(sizeof(char)*n);//用来临时存放一个字符的编码结果  
     cd[n-1]='\0'; //设置字符串结束标志 
     for(i=1;i<=n;i++)
     {
         start=n-1;
         current=i;
         parent=ht[current].parent;//获取当前结点的父结点 
         while(parent) //父结点不为空 
         {
             if(current==ht[parent].left)//若该结点是父结点的左子树  
               cd[--start]='0'; //编码为0 
             else //若结点是父结点的右子树 
               cd[--start]='1'; //编码为1 
             current=parent; //设置当前结点指向父结点 
             parent=ht[parent].parent; //获取当前结点的父结点序号    
         }
         hc[i-1]=(char*)malloc(sizeof(char)*(n-start));//分配保存编码的内存 
         strcpy(hc[i-1],&cd[start]); //复制生成的编码           
     }
     free(cd); //释放编码占用的内存 
}

void Encode(HuffmanCode *hc,char *alphabet,char *str,char *code)
//将一个字符串转换为Huffman编码
//hc为Huffman编码表 ,alphabet为对应的字母表,str为需要转换的字符串,code返回转换的结果 
{
     
     int len=0,i=0,j;
     code[0]='\0';
     while(str[i])
     {
         j=0;
         while(alphabet[j]!=str[i])
             j++;         
         strcpy(code+len,hc[j]); //将对应字母的Huffman编码复制到code指定位置 
         len=len+strlen(hc[j]); //累加字符串长度 
         i++;
     }
     code[len]='\0';
}

void Decode(HuffmanTree *ht,int m,char *code,char *alphabet,char *decode)
//将一个Huffman编码组成的字符串转换为明文字符串 
//ht为Huffman二叉树,m为字符数量,alphabet为对应的字母表,str为需要转换的字符串,decode返回转换的结果 
{
     int position=0,i,j=0;
     m=2*m-1;
     while(code[position]) //字符串未结束 
     {
          for(i=m;ht[i].left && ht[i].right; position++) //在Huffman树中查找左右子树为空 ，以构造一个Huffman编码 
          {
              if(code[position]=='0') //编码位为0 
                  i=ht[i].left; //处理左子树 
              else //编译位为 1 
                  i=ht[i].right; //处理右子树 
          }
          decode[j]=alphabet[i-1]; //得到一个字母
          j++;//处理下一字符 
     }  
     decode[j]='\0'; //字符串结尾 
}
int main()
{
    int i,n=4,m; 
    char test[]="DBDBDABDCDADBDADBDADACDBDBD";
    char code[100],code1[100];
    char alphabet[]={'A','B','C','D'}; //4个字符
    int w[]={5,7,2,13} ;//4个字符的权重 
    HuffmanTree *ht;
    HuffmanCode *hc;    
    m=2*n-1;    
    ht=(HuffmanTree *)malloc((m+1)*sizeof(HuffmanTree)); //申请内存，保存赫夫曼树 
    if(!ht)
    {
        printf("内存分配失败！\n");
        exit(0);    
    }
    hc=(HuffmanCode *)malloc(n*sizeof(char*));
    if(!hc)
    {
        printf("内存分配失败！\n");
        exit(0);    
    }
    
    CreateTree(ht,n,w); //创建赫夫曼树 
    HuffmanCoding(ht,n,hc); //根据赫夫曼树生成赫夫曼编码 
    for(i=1;i<=n;i++) //循环输出赫夫曼编码 
        printf("字母:%c,权重:%d,编码为 %s\n",alphabet[i-1],ht[i].weight,hc[i-1]);
    
    Encode(hc,alphabet,test,code); //根据赫夫曼编码生成编码字符串 
    printf("\n字符串:\n%s\n转换后为:\n%s\n",test,code); 
    
    Decode(ht,n,code,alphabet,code1); //根据编码字符串生成解码后的字符串 
    printf("\n编码:\n%s\n转换后为:\n%s\n",code,code1); 
    getch();
    return 0;
}

