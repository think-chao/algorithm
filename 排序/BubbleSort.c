#include <stdio.h>
#include "CreateData.c"
#define ARRAYLEN 6

//��ð������ĸĽ�
//����Լ��ź�����ɨ���� 
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
			printf("��%2d��:",i+1); 
        	for(j=0;j<n;j++)
            	printf("%d ",a[j]);
        	printf("\n");
			flag=0;
		}    
    }
}
void BubbleSort1(int a[],int n)
{
    int i,j,t,flag=0;        //flag��������Ƿ�������
    for(i=0;i<n-1;i++)
    {
        for(j=n-1;j>i;j--)
        {
            if(a[j-1]>a[j])//�������� 
            {
                t=a[j-1];
                a[j-1]=a[j];
                a[j]=t;
                flag=1;
            }
        }
        printf("��%2d��:",i+1); 
        for(j=0;j<n;j++)
            printf("%d ",a[j]);
        printf("\n");
        if(flag==0)    //û��������,ֱ������ѭ��
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
        printf("������������ɹ�!\n");
        getch();
        return 1;
    }
    printf("ԭ����:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    BubbleSort1(a,ARRAYLEN);
    printf("�����:"); 
    for(i=0;i<ARRAYLEN;i++)
        printf("%d ",a[i]);
    printf("\n");
    getch();
    return 0;   
}

