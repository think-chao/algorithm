#include <stdio.h>
#include <cstdlib>
int main(){
	int old_price=0,price=0,i=0;
	printf("����������Ʒ�ļ۸�");
	scanf("%d",&old_price);
	system("cls");
	printf("enter your guess\n");
	while(old_price!=price){
		i++;
		scanf("%d",&price);
		if(old_price<price){
			printf("��ļ۸���%d\n",price);
			printf("����\n");
			printf("try again\n");
		}
		else if(old_price>price){
			printf("��ļ۸���%d\n",price);
			printf("����\n"); 
			printf("try again\n");
		}else{
			printf("��ļ۸���%d\n",price);
			printf("��ϲ������\n");
			printf("��һ������%d��\n",i);
		} 	 
	}
	return 0;
	
} 
