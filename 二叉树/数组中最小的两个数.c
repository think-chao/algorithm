/*
ѡ��������������С���� 
*/ 

#include<stdio.h>

int mini(int *b){
	int i,flag;
	int min=100;
	for(i=0;i<4;i++){
		if(min>*(b+i)){
			min=*(b+i);
			flag=i;
		}
	}
	printf("��С����%d",min);
	printf("������ĵڣ�%dλ\n",flag);
	return flag; //������Сֵ���ڵ������λ�� 
}

void second(int *b,int c){
	
	int i,j;
	int *h;
	h=b;

	printf("********************8\n");
	printf("%d\n",*(h+1));
	printf("********************8\n");
	int flag;
	flag=c;//flag=1��ȷ�� 
	printf("flag %d\n",flag);
	printf("********************8\n");

	int min2=100;
	int min1=100;
	int sflag=100,dflag=100;
	
	for(i=0;i<flag;i++){
		printf("000000000%d\n",min1-*(h+i));
		if(min1>*(h+i)){
			
			min1=*(h+i);
			sflag=i;
			printf("sflag1����%d\n",sflag);
		}
	}
	printf("sflag2����%d\n",sflag);

	for(i=flag+1;i<4;i++){
		if(min2>*(h+i)){
			min2=*(h+i);
			dflag=i;
		}
	}
	//printf("%d",*(b+sflag));
	//printf("�ҽ�����"); 
	if(*(h+sflag)>*(h+dflag)){
		printf("�ڶ�С��ֵ�ǣ�%d\n",*(h+dflag));
		printf("�ڶ�С��ֵ�ڵڣ�%dλ\n",dflag);
	}else{
		printf("�ڶ�С��ֵ�ǣ�%d\n",*(h+sflag));
		printf("�ڶ�С��ֵ�ڵڣ�%dλ\n",sflag);
	}	
}

int main(){
	int a[4]={7,2,3,4};
	int *b=a;
	second(b,mini(b));
	
} 
