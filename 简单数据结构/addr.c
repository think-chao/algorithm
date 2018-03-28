//代码功能：实现通讯录
//添加联系人，删除联系人，显示联系人，查找联系人
//数据结构：
typedef struct
{
	char key[20];
	char mobile[11];
}DATA;

#include <stdio.h>
#include "ll.h"
#include "ll.c"

//显示所有联系人 
void ChainListAll(ChainListType *head)
{
	ChainListType *h;
	DATA data;
	h=head;
	while(h)
	{
		data=h->data;
		printf("%s电话号码是%s",data.key,data.mobile);
		h=h->next;
	} 
	return;
}
//添加联系人
ChainListType *input(ChainListType *head)
{
	DATA data;
	printf("请输入联系人信息\n");
    printf("姓名:");
    scanf("%s",data.key);
    printf("手机:");
    scanf("%s",data.mobile);
    return ChainListAddFirst(head,data);
}
//删除联系人
void del(ChainListType *head)
{
	ChainListType *h;
	h=head;
	printf("你想删除谁？\n");
	char name[15];
	scanf("%s",name);
	ChainListDelet(head,name); 
} 

//查找联系人
void find(ChainListType *head)
{
	ChainListType *h;
	h=head;
	char name[15];
	DATA data;
	printf("你想查找的联系人是？\n");
	scanf("%s",name);
	h=ChainListFind(head,name);
	if(h)
	{
		data=h->data;//获取结点数据 
        printf("姓名:%s\n",data.key);
        printf("手机:%s\n",data.mobile);
	}
} 
int main()
{
    ChainListType *node, *head=NULL;
    int select;//选择菜单的序号 
    do{
        printf("\n_____________________\n");
        printf("1.添加联系人\n");
        printf("2.查找联系人\n");
        printf("3.删除联系人\n"); 
        printf("4.显示所有联系人\n"); 
        printf("0.退出\n");
        printf("_____________________\n");
        select=getch();
        switch(select) 
        {
            case '1':
                printf("\n添加联系人\n"); 
                head=input(head);
                break;
            case '2':
                 printf("\n查找联系人\n"); 
                 find(head);
                 break;
           case '3':
                printf("\n删除联系人\n"); 
                del(head);
                break;
           case '4':
                printf("\n显示联系人\n"); 
                ChainListAll(head);
                break;
           case '0':
                return 0;
        }
    }while(select != '0');
}
