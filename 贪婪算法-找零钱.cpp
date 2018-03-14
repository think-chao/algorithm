/*
	假设找3.2毛钱，那么在第一次的可以确定找1块的，在找2次一块的后，找2次一毛的
	 
*/ 
#include <stdio.h>
#define MAXN 8
int prevalue[MAXN]={10000,5000,2000,1000,500,100,50,10};
int num[MAXN]={0};			//这是很重要的数据结构，用来存放面额的对应位置，或者说表示有效位 

exchange(int n)
{
	int i;
	for(i=0;i<MAXN;i++)
	{
		if(n>prevalue[i])			//第一次找到比n小的面值的时候，就是要找的第一张
		 	break;					 
	}
	while(n>0&&i<MAXN)
	{
		if(n>=prevalue[i])			//首先找到第一张要找的面额，将对于位置i 
		{							//找第二张面额，减去已经找过的 
			n-=prevalue[i];			//假设32，则32-10之后还要循环一次22-10，13-10； 
			num[i]++; 			
		}							//标志位置1 
		
		else if(n<10&&n>=5)			//如果通过前面的步骤无法找到合适的，说明要找的是5毛和1毛的 
		{
			num[MAXN-1]++;			//如果是要找5毛以上1块以下，则一定要找一个5毛的， 
			break;
		}
		else i++;
	}
	return 0;
}

int main(){
	
	float money;
	printf("要找你多少钱？");
	scanf("%f",&money);
	exchange((int)100*money);
	printf("\n%.2f元零钱的组成：\n",money);
	for(int i;i<MAXN;i++)
	{
		if(num[i]>0)
		{
			printf("%6.2f:%d张\n",(float)prevalue[i]/100.0,num[i]);
		}
	}
	return 0;
	 
}
