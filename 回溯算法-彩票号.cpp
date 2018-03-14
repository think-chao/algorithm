/*
要求： 
	生成7位的彩票号，每一位都有1-29之中的一位数构成，而且7位数不能一样

算法思想：
	试探其中一种可能
	29 28 27 26 25 24 23 
	29 28 27 26 25 24 22
	..
	29 28 27 26 25 24 1
	29 28 27 26 25 23 22

数据结构：
	用数组存放数字 
*/ 

#include <stdio.h>
#define MAX 2
#define NUM 9
int lottery[MAX];
int num[NUM];
//
//可以从解题思路里看到，实际每次只要变化最后一位数字，知道最后一位数字可变的情况列举完毕
//然后使得倒数第2位数字减1，则倒数第1位数字又可以从头变化到列举完毕
//一次类推，可以使用递归
// 
void gen(int n,int m)
{
	int i,j;
	for (i=n;i>=m;i--)
	{
		lottery[m-1]=num[i-1];				//num[]里面包含了形成彩票的数字，默认将彩票号从小到大排列
											//确定了彩票最后一位的变化，可以列出所有可能
		if(m>1)								//m代表的是现在处理的彩票的位数，如果 
		{
			gen(i-1,m-1);
		}
		else
		{
			for(j=MAX-1;j>=0;j--)
			{
				printf("%3d",lottery[j]);
			}
			printf("\n");
		 } 
		 
	}
	
}

int main(){
	int i,j;
	//设置彩票各位的数字1,2...,29
	for(i=0;i<NUM;i++)
	{
		num[i]=i+1;	
	} 
	
	//初始彩票各个数值都0 
	for(i=0;i<MAX;i++)
	{
		lottery[i]=0;
	}
	
	gen(NUM,MAX); 
	return 0;
} 
