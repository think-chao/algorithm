/*
选出数组中两个最小的数 
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
	printf("最小的是%d",min);
	printf("在数组的第：%d位\n",flag);
	return flag; //返回最小值所在的数组的位置 
}

void second(int *b,int c){
	
	int i,j;
	int *h;
	h=b;

	printf("********************8\n");
	printf("%d\n",*(h+1));
	printf("********************8\n");
	int flag;
	flag=c;//flag=1已确认 
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
			printf("sflag1等于%d\n",sflag);
		}
	}
	printf("sflag2等于%d\n",sflag);

	for(i=flag+1;i<4;i++){
		if(min2>*(h+i)){
			min2=*(h+i);
			dflag=i;
		}
	}
	//printf("%d",*(b+sflag));
	//printf("我进来了"); 
	if(*(h+sflag)>*(h+dflag)){
		printf("第二小的值是：%d\n",*(h+dflag));
		printf("第二小的值在第：%d位\n",dflag);
	}else{
		printf("第二小的值是：%d\n",*(h+sflag));
		printf("第二小的值在第：%d位\n",sflag);
	}	
}

int main(){
	int a[4]={7,2,3,4};
	int *b=a;
	second(b,mini(b));
	
} 
