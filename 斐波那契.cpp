#include <stdio.h>

int main(){
	printf("��0����������\n1��\n");
	int tu[12]={1,1};
	
	for(int i=2;i<=12;i++){
		tu[i]=tu[i-1]+tu[i-2];
	}
	
	for(int i=1;i<=12;i++){
		printf("��%d����������\n%d��\n",i,tu[i]);
	}
	return 0;

	
	
} 
