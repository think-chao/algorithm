#include <stdio.h>
int main(){
	int a[4]={1,2,3,4};
	int b[4]={5,2,3,4};
	int *i;
	int s,j;
	i=a;
	int c;
	c=a-b;
	printf("%d",c);
	printf("%d",*i);
	printf("0000000000000000000000000000000000000\n");
	for(j=0;j<3;j++)
	{
		printf("%d\n",a[j++]);   //Êä³ö1,3 
	}
	printf("0000000000000000000000000000000000000\n");
	for(j=0;j<3;++j)
	{
		printf("%d\n",a[++j]);  //Êä³ö2,4 
	}
}


