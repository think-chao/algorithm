//num1[]num2[]num3[]num4[]num5=num6
//��ⷽ���еķ���

/*��ⷽ����
	�������з��ŵĿ��ܣ�1����+��2����-��3����*��4����/��
	Ƕ��4��forѭ��(һ����4����Ҫ�����)��ÿ��ѭ��4��̽�����ŵĿ��� ��
	
	Ҫ��
	�������Ϊ"/",��ô���ŵ��ұ߲���Ϊ0�� 
*/ 
#include <stdio.h>
int main()
{
	int num[6];
	int i[5];
	int result;
	int count=0;
	char oper[5]={'0','+','-','*','/'};
	
	printf("����5������\n");
	for(int i=1;i<=5;i++)
	{
		scanf("%d",&num[i]);
	}
	
	printf("������Ҫ�Ľ��\n");
	scanf("%d",&result);
	
	for(i[1]=1;i[1]<=4;i[1]++)
	{
		if(i[1]<4||num[2]!=0)
		{
			for(i[2]=1;i[2]<=4;i[2]++)
			{
				if(i[2]<4||num[3]!=0)
				{
					for(i[3]=1;i[3]<=4;i[3]++)
					{
						if(i[3]<4||num[4]!=0)
						{
							for(i[4]=1;i[4]<=4;i[4]++)
							{
								if(i[4]<4||num[5]!=0)
								{
									/*
										���Ϊ��+����left+right�Ľ����Ϊ�´μ����left��
										 
									*/
									int left=0;
									int flag;
									int right=num[1];
									for(int j=1;j<=4;j++)
									{
										switch(oper[i[j]])
										{
											case '+':
												left=left+flag*right;
												flag=1;
												right=num[j+1];
												break;
											case '-':
												left=left+flag*right;
												flag=-1;
												right=num[j+1];
												break;
											case '*':
												right=right*num[j+1];
												break;
												
											case '/':
												right=right/num[j+1];
												break;
								
										}
									}
									if(left+flag*right==result)
									{
										count++;
										printf("%d:",count);
										for(int k=1;k<=4;k++)
										{
											printf("%d%c",num[k],oper[i[k]]);
										}
										printf("%d=%d\n",num[5],result);
									}
								}
							}
						}
					}
				}
			}
		}
		
	}
	if(count==0)
	{
		printf("��̫���ˣ��Ҳ�����");
	}
	
	
} 
 
