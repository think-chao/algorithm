#include<stdio.h>
#include<stdlib.h>

//��ϯA�Ӵ�ѧ��,flag=1��ʾ����ѧ����������� 
int FA(int *count_A,int *id,int *num){
	int flag=0;
	*count_A=*count_A+1;
	*id=*id+1;
	*num=*num-1;
	printf("ΪA��ϯ����ѧ��%d",*id);
	printf("����ʣ%d��û�з���\n",*num);
	if(*num<=0){
		flag=1;
	}
	return flag;
}
//��ϯB�Ӵ�ѧ�� 
int FB(int *count_B,int *id,int *num){
	int flag=0;
	*count_B=*count_B+1;
	*id=*id+1;
	*num=*num-1;
	printf("ΪB��ϯ����ѧ��%d",*id);
	printf("����ʣ%d��û�з���\n",*num);
	if(*num<=0){
		flag=1;
	}
	return flag;
}
//��ϯC�Ӵ�ѧ�� 
int FC(int *count_C,int *id,int *num){
	int flag=0;
	*count_C=*count_C+1;
	*id=*id+1;
	*num=*num-1;
	printf("ΪC��ϯ����ѧ��%d",*id);
	printf("����ʣ%d��û�з���\n",*num);
	if(*num<=0){
		flag=1;
	}
	return flag;
}
int main(){
	int num,i;
	printf("�������ж�����Ҫ��绰\n");
	scanf("%d",&num);
	int count_A=0,count_B=0,count_C=0,id=0,flag=0,k=1;
	
	while(num>0){
		printf("********************��%d��*************************\n",k++); 
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
	printf("�������\n");
	printf("ΪA��ϯһ������%d\nΪC��ϯһ������%d\nΪB��ϯһ������%d\n",count_A,count_C,count_B);
}
