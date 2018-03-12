//num1_num2_num3_num4_num5=num6
//题目要求 

#include <stdio.h>
int main(){
	int result=5;
	int count =0;
	float left,right;
	int num[5]={5,5,5,5,5};
	char oper[4]={'+','-','*','/'};
	//用一个数组来存放运算符，都用数字代替，最后统一转换为运算符
	int y[4];
	//1,表示+；2表示-，3表示*，4表示/ 
	for(y[0]=1;y[0]<=4;y[0]++){
		if(y[0]<4||num[1]!=0){
			for(y[1]=1;y[1]<=4;y[1]++){
				if(y[1]<4||num[2]!=0){
					for(y[2]=1;y[2]<=4;y[2]++){
						if(y[2]<4||num[3]!=0){
							for(y[3]=1;y[3]<=4;y[3]++){
								if(y[3]<4||num[4]!=0)
								{
									//上次运算的结果作为下次运算的输入 
									left=0;
									int sign=1;
									right=num[0];
									for(int j=0;j<4;j++)
									{
										switch(oper[y[j]])
										{
											case '+':
												left=left+sign*right;
												sign=1;
												right=num[j+1];
												break;
											case '-':
												left=left+sign*right;
												sign=-1;
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
									if(left+sign*right==result){
										count++;
										printf("%3d:",count);
										for(int j=0;j<4;j++){
											printf("%d%c",num[j],oper[y[j]]);
										}
										printf("%d=%d\n",num[4],result);
									}
										
								}
								
								}
								}
							}
						}
					}
				}
			}
		}

