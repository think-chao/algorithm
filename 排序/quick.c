
//分割 
/*
1. 首先去最左侧的值为基数base
2. 从right往左搜索，知道数比base小right-- 
3. 把该数保存到a[left]
4. 从left往right搜索，直到数比base大，left++ 
5. 把该数保存到a[right]
6. 保存left和right的值作为下一次迭代的left和right 

7. 这个过程left始终要小于right 
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
