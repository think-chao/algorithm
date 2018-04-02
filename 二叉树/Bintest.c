#include<stdio.h>
#include "BinTree.c"

void oper(ChainBinTree *p){
	printf("%c" ,p->data);
	return;
}

//��ʼ�������� 
ChainBinTree *InitRoot() 
{
	ChainBinTree *node;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))){
		printf("\n������ڵ�����:");
		scanf("%s",&node->data);
		node->left=NULL;
		node->right=NULL;
	}
	return node;
}

//��������ָ���ڵ��������
void AddNode(ChainBinTree *bt){
	ChainBinTree *node,*parent;
	DATA data;
	int select;
	if(node=(ChainBinTree *)malloc(sizeof(ChainBinTree))){
		printf("\n����������������:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&node->data);
        node->left=NULL; //������������Ϊ�� 
        node->right=NULL;
        
        printf("���븸�������:");
        fflush(stdin);//������뻺���� 
        scanf("%s",&data);
        parent=BinTreeFind(bt,data);             //���ҹؼ��ֶ�Ӧ�Ľڵ�
		if(!parent)//��δ�ҵ�ָ�����ݵĽ�� 
        {
            printf("δ�ҵ������!\n");
            free(node); //�ͷŴ����Ľ���ڴ� 
            return;
         }
         printf("1.��ӵ�������\n2.��ӵ�������\n"); 
         do{
            select=getch();
            select-='0';
            if(select==1 || select==2)
                BinTreeAdd(parent,node,select); //��ӽ�㵽������ 
         }while(select!=1 && select!=2);
	}
	return; 
} 


int main(){
	int select;
	ChainBinTree *root=NULL; //rootΪָ�������������ָ�� 
	
	//********����ָ��ʹ��ǰ����******************************************************
	void (*oper1)();
	oper1=oper;  
	//*********����ָ��ָ��oper����*********************************************************************
	do{
		printf("\n1.���ö�������Ԫ��    2.��Ӷ��������\n");
        printf("3.�������            4.�������\n");
        printf("5.�������            6.�������\n");
        printf("7.���������          0.�˳�\n");
        select=getch();
        switch(select){
        	case '1':
        		root=InitRoot();
             	break;
            case '2':
            	AddNode(root);
            	break;
            case '3':
            	printf("\n��������Ľ����");
            	BinTree_DLR(root,oper1);
            	break;
            case '4'://������� 
	             printf("\n��������Ľ����");
	             BinTree_LDR(root,oper1);
	             printf("\n");
	             break;
	        case '5'://������� 
	             printf("\n��������Ľ����");
	             BinTree_LRD(root,oper1);
	             printf("\n");
	             break;
	        case '6'://�������
	             printf("\n��������Ľ����");
	             BinTree_Level(root,oper1);
	             printf("\n");
	             break;
	        case '7'://�����������
	            printf("\n���������Ϊ:%d\n",BinTreeDepth(root));
	            break; 
	        case '0':
	             break;
		}
	}while(select!='0');
	BinTreeClear(root);//��ն����� 
    root=NULL;
    getch();
    return 0;
}
