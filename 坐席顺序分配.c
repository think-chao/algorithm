#include<stdio.h>
#include<stdlib.h> 

/**FA������ʾ��ϯA�Ӵ�ѧ�������� *n����ͨ��ָ�봫�뵱ǰ�Ļ�δ������Դ����������������Ҫ��������������޸�
	*count_A��������A��ϯ���Ӵ�����ѧ���ĺ�
	*id������ʾѧ������ŵģ�ÿ����ϯ�Ӵ�һ���˵�ʱ��id��ֵ�ͼ�һ����ʾ��һ��ѧ�� 
	FB FC����ͬ�� 
**/ 
int FA(int *n,int *count_A,int *id){
	int i,j,flag=0;
	
	if(*n<=3){
		for(j=0;j<*n;j++){
			printf("ΪA��ϯ����ѧ��%d\n",*id);
			*id=*id+1;
		} 
		
		*count_A=*count_A+*n;
		*n=0;					//ȫ���������ˣ�flagΪ��־��һ��� 
		flag=1;
		
	}else{
		for(j=0;j<3;j++){
			printf("ΪA��ϯ����ѧ��%d\n",*id);
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
		printf("ΪB��ϯ����ѧ��%d\n",*id);
		*id=*id+1;
		*count_B=*count_B+*n;
		*n=0;					//ȫ���������ˣ�flagΪ��־��һ��� 
		flag=1;
	}else{
		printf("ΪB��ϯ����ѧ��%d\n",*id);
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
			printf("ΪC��ϯ����ѧ��%d\n",*id);
			*id=*id+1;
		} 
		*count_C=*count_C+*n;
		*n=0;					//ȫ���������ˣ�flagΪ��־��һ��� 
		flag=1;
	}else{
		for(j=0;j<5;j++){
			printf("ΪC��ϯ����ѧ��%d\n",*id);
			*id=*id+1;
		} 
		*n=*n-5;
		*count_C=*count_C+5;		
	}
	return flag;
}
int main(){
	int num,flag;						//flag�������Ҫ��Ҫ�˳�whileѭ����û����Ҫ������Դ��ʱ���˳��� 
	printf("�������ж�����Ҫ��绰\n");
	scanf("%d",&num);
	int count_A=0,count_B=0,count_C=0,id=1;	//id������ʾѧ������� 
	 
	while(num>0){						//num>0��˵����Ȼ��û�з��䵽��Դ��ѧ�� 
		if(num>0){
			flag=FA(&num,&count_A,&id);
			if(flag==0){
				printf("*****************************************��ʣ%d��û�з���\n",num);
			}else{
				printf("�������\n");
				break;
			}				
		}
		if(num>0){
			flag=FC(&num,&count_C,&id);
			if(flag==0){
				printf("*****************************************��ʣ%d��û�з���\n",num);
			}else{
				printf("�������\n");
				break;
			}
		}
		if(num>0){
			flag=FB(&num,&count_B,&id);
			if(flag==0){
				printf("*****************************************��ʣ%d��û�з���\n",num);
			}else{
				printf("�������\n");
				break;
			}
		}
	}
	printf("ΪA��ϯһ������%d\nΪB��ϯһ������%d\nΪC��ϯһ������%d\n",count_A,count_B,count_C);
	
} 
