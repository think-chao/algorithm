/*
	������3.2ëǮ����ô�ڵ�һ�εĿ���ȷ����1��ģ�����2��һ��ĺ���2��һë��
	 
*/ 
#include <stdio.h>
#define MAXN 8
int prevalue[MAXN]={10000,5000,2000,1000,500,100,50,10};
int num[MAXN]={0};			//���Ǻ���Ҫ�����ݽṹ������������Ķ�Ӧλ�ã�����˵��ʾ��Чλ 

exchange(int n)
{
	int i;
	for(i=0;i<MAXN;i++)
	{
		if(n>prevalue[i])			//��һ���ҵ���nС����ֵ��ʱ�򣬾���Ҫ�ҵĵ�һ��
		 	break;					 
	}
	while(n>0&&i<MAXN)
	{
		if(n>=prevalue[i])			//�����ҵ���һ��Ҫ�ҵ���������λ��i 
		{							//�ҵڶ�������ȥ�Ѿ��ҹ��� 
			n-=prevalue[i];			//����32����32-10֮��Ҫѭ��һ��22-10��13-10�� 
			num[i]++; 			
		}							//��־λ��1 
		
		else if(n<10&&n>=5)			//���ͨ��ǰ��Ĳ����޷��ҵ����ʵģ�˵��Ҫ�ҵ���5ë��1ë�� 
		{
			num[MAXN-1]++;			//�����Ҫ��5ë����1�����£���һ��Ҫ��һ��5ë�ģ� 
			break;
		}
		else i++;
	}
	return 0;
}

int main(){
	
	float money;
	printf("Ҫ�������Ǯ��");
	scanf("%f",&money);
	exchange((int)100*money);
	printf("\n%.2fԪ��Ǯ����ɣ�\n",money);
	for(int i;i<MAXN;i++)
	{
		if(num[i]>0)
		{
			printf("%6.2f:%d��\n",(float)prevalue[i]/100.0,num[i]);
		}
	}
	return 0;
	 
}
