#include<stdio.h>  
void decimalToBinary(int n);  
int main()  
{  
    int n;  
    char again;  
    do  
    {  
        printf("����10���ƣ�");  
        scanf("%d",&n);  
        printf("%d�Ķ����ƣ�",n);  
        decimalToBinary(n);  
        printf("\n����[y/n]?:");  
        scanf("%s",&again);  
    }while(again=='y'||again=='Y');  
    printf("���������\n");  
}  
//long long decimalToBinary(int n)//������ת��10���ƣ���2ȡ�࣬��������  
void decimalToBinary(int n)  
{  
    static long long binary=0;  
    static int i=1;//ʹ��static,��̬�ֲ�����ʹ��i�����ۼ�  
    int remainder=0;//������ʹ�ã���̬�ֲ�������ÿ�εݹ�Ľ�����������  
    static int count=0;  
    if(n!=0)  
    {  
        remainder=n%2;// ȡ����  
//        printf("����=%d,%d/2--->����=%d,��=%d\n",++count,n,remainder,n/2);  
        n=n/2;//����2  
        decimalToBinary(n);//����һ������  
        printf("%d",remainder);//�ݹ鷵������Ȼ������ģ���ӡ�������Ѿ�������õ�  
    }  
}  
