/*
Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
*/ 

bool isPalindrome(int x) {
    //首先获取整数位数
    if(x<0||x>INT_MAX){
        return false;
    }
    int n=0;
    int oper1=10;
    int y=x;
    while(y){
        y=y/10;
        n++;
        oper1=pow(10,n-1);
    }
    int oper2=10;
    int m=n/2;
    int x1=x;
    int x2=x;
    int flag=0;
    //x1=122 x2=122 oper1=100 oper2=10
    for(int i=0;i<m;i++){
        int left=x1/oper1;
        int right=x2%oper2;
        if(left==right){
            x1=x1%oper1;
            x2=x2/oper2;
            oper1=oper1/10;
        }else{
            flag=1;
            break;
        }
    }
    if(flag==1){
        return false;
    }else{
        return true;
    } 
}
