#include<stdio.h>
#include<stdlib.h>

//坐席A接待学生,flag=1表示所有学生都分配完毕 
int FA(int *count_A,int *id,int *num){
	int flag=0;
	*count_A=*count_A+1;
	*id=*id+1;
	*num=*num-1;
	printf("为A坐席分配学生%d",*id);
	printf("，还剩%d人没有分配\n",*num);
	if(*num<=0){
		flag=1;
	}
	return flag;
}
//坐席B接待学生 
int FB(int *count_B,int *id,int *num){
	int flag=0;
	*count_B=*count_B+1;
	*id=*id+1;
	*num=*num-1;
	printf("为B坐席分配学生%d",*id);
	printf("，还剩%d人没有分配\n",*num);
	if(*num<=0){
		flag=1;
	}
	return flag;
}
//坐席C接待学生 
int FC(int *count_C,int *id,int *num){
	int flag=0;
	*count_C=*count_C+1;
	*id=*id+1;
	*num=*num-1;
	printf("为C坐席分配学生%d",*id);
	printf("，还剩%d人没有分配\n",*num);
	if(*num<=0){
		flag=1;
	}
	return flag;
}
int main(){
	int num,i;
	printf("请输入有多少人要打电话\n");
	scanf("%d",&num);
	int count_A=0,count_B=0,count_C=0,id=0,flag=0,k=1;
	
	while(num>0){
		printf("********************第%d轮*************************\n",k++); 
		for(i=1;i<=5;i++){
			if(i<=1){
				flag=FA(&count_A,&id,&num);
				if(flag==1) break;
				flag=FC(&count_C,&id,&num);
				if(flag==1) break;
				flag=FB(&count_B,&id,&num);
				if(flag==1) break;		
			}else if(i<=3){
				flag=FA(&count_A,&id,&num);
				if(flag==1) break;
				flag=FC(&count_C,&id,&num);
				if(flag==1) break;
			}else{
				flag=FC(&count_C,&id,&num);
				if(flag==1) break;	
			}
		}
		
		if(flag==1) break; 
	}
	printf("分配完毕\n");
	printf("为A坐席一共分配%d\n为C坐席一共分配%d\n为B坐席一共分配%d\n",count_A,count_C,count_B);
}
