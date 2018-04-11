/*
功能描述:
	将一个十进制数转换为二进制或者8进制的数
待增加:
	增加十进制数转换为16进制数
	
实现思路:
	1.输入:10进制整数;输出:二进制(由0,1组成),8进制(0到7组成)
	2.数据结构:
		s[80]:数组保存输出的结果 
*/

#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[4];
	strcpy(s,"");
	for(int i=0;i<4;i++)
	{
		printf("%s",s[i]);
	}
	
} 
