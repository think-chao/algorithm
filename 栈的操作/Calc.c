typedef DATA int;

int IsOperator(char c){
	switch(c)
    {
        case'+':
        case'-':
        case'*':
        case'/':
        case'(':
        case')':
        case'=':
            return 1;
            break;
        default:
            return 0;
            break;
    } 
}

/*
oper1,oper2优先级
括号优先级比其他优先级高
乘除优先级比括号高 
data1 oper1 data2 oper2
如果前面操作符优先级比后面优先级高，就可以从左向右计算，返回1 
oper2:+- *\  (  ) 
oper1
+-    1  -1 -1  1 
*\    1   1 -1  1  
(    -1  -1 -1  0 
)     1   1     1
= 
*/

int PRI(oper1,oper2){
	int pri;
	switch(oper2){
		case '+':
		case '-':
			if(oper1=='('||oper1='='){
				pri=-1
				break;
			}else{
				pri=1;
				break;
			}
		case '*':
		case '/':
			if(oper1=='*'||oper1=='/'||oper==')'){
				pri=1;
				break;
			}else{
				pri=-1;
				break;
			}
		case '(':
			if(oper1!=')'){
				pri=-1;
				break;
			}else{
				printf("语法错误\n");
				exit(0);
			}
		case ')':
			if(oper1=='('){
				pri=0;
			}
			else if(oper1=='='){
				printf("符号不匹配\n");
			}else{
				pri=1;
			}
			break;
		case '=':
			if(oper1=='(')
            {
                printf("括号不匹配!\n");
                exit(0);
            }else if(oper1=='=')
                pri=0;
            else
                pri=1;
            break;
	}
	return pri;
}

int CalcExp(char exp[]){
		DATA x,c, 
		SeqStack *StackOper,*StackData;
		StackOper=SeqStackInit();
		StackData=SeqStackInit();
		
		x='=';
		
		//先将=入栈 
		SeqStackPush(StackOper,x);
		//去操作符栈顶元素 
		x=SeqStackPeek(StackOper); 
		
		//开始不断的取表达式中的符号了
		//=
		//假设（2+3）*4= 
		c=exp[i++];
		while(c!='='||x!='='){
			if(IsOperator(c)){
				//如果操作数入栈了 
				if(flag){
					SeqStackPush(StackData,q);//将操作数入栈 
                	q=0;
                	flag=0;
				}
				switch(PRI(x,c)){
					case -1://操作符栈中顶的优先级高于从表达式中取出的操作符的优先级，那么就从需要将其入栈
						SeqStackPush(StackOper,c);
						c=exp[i++];
						break;
					case 1://说明前面优先级高于取出的优先级，就可以先计算了 
						oper=SeqStackPop(StackOper);
						b=SeqStackPop(StackData);
						a=SeqStackPop(StackData);
						t=Calc(a,oper,b);
						SeqStackPush(StackData,t);
						break;
						
					//(2+3*(1+2))=
					case 0:
						c=SeqStackPop(StackOper);
						c=exp[i++];
						break;			
				}				 
			}else if(c>='0'&&c<='9'){
				c-='0';
				q=q*10+c;
				c=exp[i++];
				flag=1;//准备将数据入栈 
			}else
	        {
	            printf("输入错误!\n");
	            getch();
	            exit(0);
	        }
	         x=SeqStackPeek(StackOper);//获取栈顶的运算符 
		}
		q=SeqStackPop(StackData);
    SeqStackFree(StackOper); 	//释放栈所占用的空间 
    SeqStackFree(StackData);
    return q; //出栈，返回结果 
}


int CalcExp(exp){
	
}
int main(){
	int c;
	char exp[80];
	printf("请输入要计算的表达式(以=结束):"); 
    scanf("%s",exp);
    printf("%s%d\n",exp,CalcExp(exp));
} 
