
//�ָ� 
/*
1. ����ȥ������ֵΪ����base
2. ��right����������֪������baseСright-- 
3. �Ѹ������浽a[left]
4. ��left��right������ֱ������base��left++ 
5. �Ѹ������浽a[right]
6. ����left��right��ֵ��Ϊ��һ�ε�����left��right 

7. �������leftʼ��ҪС��right 
*/
int Div(int a[],int left,int right){
	int base=a[left];
	while(left<right){
		while(left<right&&a[right]>base){
			right--;
		}
		a[left]=a[right];
		while(left<right&&a[left]<base){
			left++;
		}
		a[right]=a[left];
	}
	a[left]=base;
	return left;	
} 
