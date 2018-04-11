#include <stdio.h>

int main(){
	printf("第0个月兔子数\n1对\n");
	int tu[12]={1,1};
	
	for(int i=2;i<=12;i++){
		tu[i]=tu[i-1]+tu[i-2];
	}
	
	for(int i=1;i<=12;i++){
		printf("第%d个月兔子有\n%d对\n",i,tu[i]);
	}
	return 0;

	
	
} 
