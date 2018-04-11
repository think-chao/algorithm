#include <stdio.h>
#define fetch 1000
#define rate 0.0171

int main(){
	double money[48]={};
	money[48]=double(fetch);
	
	for(int i=47;i>0;i--){
		money[i]=(money[i+1]+fetch)/(1+rate/12);
		printf("第%d个月存款还剩%f\n",i,money[i]);a
	}
	return 0;
}
