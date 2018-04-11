#include <stdio.h>
#include <cstdlib>
int main(){
	int old_price=0,price=0,i=0;
	printf("请先设置商品的价格");
	scanf("%d",&old_price);
	system("cls");
	printf("enter your guess\n");
	while(old_price!=price){
		i++;
		scanf("%d",&price);
		if(old_price<price){
			printf("你的价格是%d\n",price);
			printf("高了\n");
			printf("try again\n");
		}
		else if(old_price>price){
			printf("你的价格是%d\n",price);
			printf("低了\n"); 
			printf("try again\n");
		}else{
			printf("你的价格是%d\n",price);
			printf("恭喜你答对了\n");
			printf("你一共猜了%d次\n",i);
		} 	 
	}
	return 0;
	
} 
