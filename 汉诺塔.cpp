/*
问题描述：汉诺塔问题，A,B,C三个杆子，最开始所有盘子都套在A杆上，想办法把所有杆子移动到C杆上 

解题思路：首先想到的是要想办法将底下那个最大的盘移动到C杆上，这样这个盘就不会影响其他盘的移动
		  可以把这些盘子分成两部分，最底下一个，以及上面的所有盘子
		  先把上盘移到B杆，底盘移到C杆
		  接下里做的就是将B杆上的最后一个盘移到C盘，同样也把这个时候B杆上的盘子分成两部分
		  将上面的盘子移到A杆，底盘移到C杆
		  ......
		  不断的进行下去，到最后A杆或者B杆上只有两个 盘子，这个时候就可以把这两个盘子名正言顺的分成两部分
		  最上面的盘子放到A杆或者B杆上，底盘移到C杆上，再把A杆或者B杆上剩下的最后一个盘子移动到C杆上 
*/ 

#include <stdio.h>
void mov(char start,char end)
{
	printf("\t%c---------->%c\n",start,end);
}
void hano(int n,char a,char b,char c)
{
	if(n==1)
	{
		mov(a,c);
	}
	else
	{
		hano(n-1,a,c,b);
		mov(a,c);
		hano(n-1,b,a,c);
	} 	
} 

int main()
{
	int number;
	printf("A杆上设置几个盘？");
	scanf("%d",&number); 
	hano(number,'a','b','c');
	return 0;
	
}

