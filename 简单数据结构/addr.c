//���빦�ܣ�ʵ��ͨѶ¼
//�����ϵ�ˣ�ɾ����ϵ�ˣ���ʾ��ϵ�ˣ�������ϵ��
//���ݽṹ��
typedef struct
{
	char key[20];
	char mobile[11];
}DATA;

#include <stdio.h>
#include "ll.h"
#include "ll.c"

//��ʾ������ϵ�� 
void ChainListAll(ChainListType *head)
{
	ChainListType *h;
	DATA data;
	h=head;
	while(h)
	{
		data=h->data;
		printf("%s�绰������%s",data.key,data.mobile);
		h=h->next;
	} 
	return;
}
//�����ϵ��
ChainListType *input(ChainListType *head)
{
	DATA data;
	printf("��������ϵ����Ϣ\n");
    printf("����:");
    scanf("%s",data.key);
    printf("�ֻ�:");
    scanf("%s",data.mobile);
    return ChainListAddFirst(head,data);
}
//ɾ����ϵ��
void del(ChainListType *head)
{
	ChainListType *h;
	h=head;
	printf("����ɾ��˭��\n");
	char name[15];
	scanf("%s",name);
	ChainListDelet(head,name); 
} 

//������ϵ��
void find(ChainListType *head)
{
	ChainListType *h;
	h=head;
	char name[15];
	DATA data;
	printf("������ҵ���ϵ���ǣ�\n");
	scanf("%s",name);
	h=ChainListFind(head,name);
	if(h)
	{
		data=h->data;//��ȡ������� 
        printf("����:%s\n",data.key);
        printf("�ֻ�:%s\n",data.mobile);
	}
} 
int main()
{
    ChainListType *node, *head=NULL;
    int select;//ѡ��˵������ 
    do{
        printf("\n_____________________\n");
        printf("1.�����ϵ��\n");
        printf("2.������ϵ��\n");
        printf("3.ɾ����ϵ��\n"); 
        printf("4.��ʾ������ϵ��\n"); 
        printf("0.�˳�\n");
        printf("_____________________\n");
        select=getch();
        switch(select) 
        {
            case '1':
                printf("\n�����ϵ��\n"); 
                head=input(head);
                break;
            case '2':
                 printf("\n������ϵ��\n"); 
                 find(head);
                 break;
           case '3':
                printf("\nɾ����ϵ��\n"); 
                del(head);
                break;
           case '4':
                printf("\n��ʾ��ϵ��\n"); 
                ChainListAll(head);
                break;
           case '0':
                return 0;
        }
    }while(select != '0');
}
