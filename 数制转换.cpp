#include<stdio.h>  
void decimalToBinary(int n);  
int main()  
{  
    int n;  
    char again;  
    do  
    {  
        printf("输入10进制：");  
        scanf("%d",&n);  
        printf("%d的二进制：",n);  
        decimalToBinary(n);  
        printf("\n继续[y/n]?:");  
        scanf("%s",&again);  
    }while(again=='y'||again=='Y');  
    printf("程序结束！\n");  
}  
//long long decimalToBinary(int n)//二进制转成10进制：除2取余，逆序排列  
void decimalToBinary(int n)  
{  
    static long long binary=0;  
    static int i=1;//使用static,静态局部变量使得i可以累加  
    int remainder=0;//余数不使用，静态局部变量，每次递归的结果不互相干扰  
    static int count=0;  
    if(n!=0)  
    {  
        remainder=n%2;// 取余数  
//        printf("步骤=%d,%d/2--->余数=%d,商=%d\n",++count,n,remainder,n/2);  
        n=n/2;//除以2  
        decimalToBinary(n);//求下一个余数  
        printf("%d",remainder);//递归返回是自然就逆序的，打印的余数已经是逆序好的  
    }  
}  
