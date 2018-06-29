#include<stdio.h>
#include<stdlib.h> 

/**FA函数表示坐席A接待学生，参数 *n是想通过指针传入当前的还未分配资源的总人数，而且需要对这个人数进行修改
	*count_A用来计算A坐席所接待过的学生的和
	*id用来表示学生的序号的，每当坐席接待一个人的时候，id的值就加一来表示下一个学生 
	FB FC函数同理 
**/ 
int FA(int *n,int *count_A,int *id){
	int i,j,flag=0;
	
	if(*n<=3){
		for(j=0;j<*n;j++){
			printf("为A坐席分配学生%d\n",*id);
			*id=*id+1;
		} 
		
		*count_A=*count_A+*n;
		*n=0;					//全部分配完了，flag为标志这一情况 
		flag=1;
		
	}else{
		for(j=0;j<3;j++){
			printf("为A坐席分配学生%d\n",*id);
			*id=*id+1;
		} 
		*n=*n-3;
		*count_A=*count_A+3;		
	}
	return flag;
}
int FB(int *n,int *count_B,int *id){
	int i,j,flag=0;
	if(*n<=1){
		printf("为B坐席分配学生%d\n",*id);
		*id=*id+1;
		*count_B=*count_B+*n;
		*n=0;					//全部分配完了，flag为标志这一情况 
		flag=1;
	}else{
		printf("为B坐席分配学生%d\n",*id);
		*id=*id+1;
		*n=*n-1;
		*count_B=*count_B+1;		
	}
	return flag;
}

int FC(int *n,int *count_C,int *id){
	int i,j,flag=0;
	if(*n<=5){
		for(j=0;j<*n;j++){
			printf("为C坐席分配学生%d\n",*id);
			*id=*id+1;
		} 
		*count_C=*count_C+*n;
		*n=0;					//全部分配完了，flag为标志这一情况 
		flag=1;
	}else{
		for(j=0;j<5;j++){
			printf("为C坐席分配学生%d\n",*id);
			*id=*id+1;
		} 
		*n=*n-5;
		*count_C=*count_C+5;		
	}
	return flag;
}
int main(){
	int num,flag;						//flag用来标记要不要退出while循环（没有需要分配资源的时候退出） 
	printf("请输入有多少人要打电话\n");
	scanf("%d",&num);
	int count_A=0,count_B=0,count_C=0,id=1;	//id用来表示学生的序号 
	 
	while(num>0){						//num>0就说明任然有没有分配到资源的学生 
		if(num>0){
			flag=FA(&num,&count_A,&id);
			if(flag==0){
				printf("*****************************************还剩%d人没有分配\n",num);
			}else{
				printf("分配完毕\n");
				break;
			}				
		}
		if(num>0){
			flag=FC(&num,&count_C,&id);
			if(flag==0){
				printf("*****************************************还剩%d人没有分配\n",num);
			}else{
				printf("分配完毕\n");
				break;
			}
		}
		if(num>0){
			flag=FB(&num,&count_B,&id);
			if(flag==0){
				printf("*****************************************还剩%d人没有分配\n",num);
			}else{
				printf("分配完毕\n");
				break;
			}
		}
	}
	printf("为A坐席一共分配%d\n为B坐席一共分配%d\n为C坐席一共分配%d\n",count_A,count_B,count_C);
	
} 
