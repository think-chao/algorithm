#include <stdio.h>
#include "CreateData.c"
#define ARRAYLEN 6

//对冒泡排序的改进
//如果以及排好了则不扫描了 
void BubbleSort(int a[],int n)
{
    int i,j,t;
    int flag=0;
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;
            }
        }
        if(flag==0){
        	break;
		}else{
			printf("第%2d遍:",i+1); 
        	for(j=0;j<n;j++)
            	printf("%d ",a[j]);
        	printf("\n");
			flag=0;
		}    
    }
}
void BubbleSort1(int a[],int n)
{
    int i,j,t,flag=0;        //flag用来标记是否发生交换
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])//交换数据 
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;
            }
        }
        printf("第%2d遍:",i+1); 
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
        if(flag==0)    //没发生交换,直接跳出循环
            break;
        else
            flag=0;
    }
}
int main()
{
    int i,a[ARRAYLEN];
    for(i=0;i<ARRAYLEN;i++)
        a[i]=0;
    if(!CreateData(a,ARRAYLEN,1,100))
    {
        printf("生成随机数不成功!\n");
        getch();
        return 1;
    }
    printf("原数据:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    BubbleSort1(a,ARRAYLEN);
    printf("排序后:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}

