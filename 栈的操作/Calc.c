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
oper1,oper2���ȼ�
�������ȼ����������ȼ���
�˳����ȼ������Ÿ� 
data1 oper1 data2 oper2
���ǰ����������ȼ��Ⱥ������ȼ��ߣ��Ϳ��Դ������Ҽ��㣬����1 
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
				printf("�﷨����\n");
				exit(0);
			}
		case ')':
			if(oper1=='('){
				pri=0;
			}
			else if(oper1=='='){
				printf("���Ų�ƥ��\n");
			}else{
				pri=1;
			}
			break;
		case '=':
			if(oper1=='(')
            {
                printf("���Ų�ƥ��!\n");
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
		
		//�Ƚ�=��ջ 
		SeqStackPush(StackOper,x);
		//ȥ������ջ��Ԫ�� 
		x=SeqStackPeek(StackOper); 
		
		//��ʼ���ϵ�ȡ���ʽ�еķ�����
		//=
		//���裨2+3��*4= 
		c=exp[i++];
		while(c!='='||x!='='){
			if(IsOperator(c)){
				//�����������ջ�� 
				if(flag){
					SeqStackPush(StackData,q);//����������ջ 
                	q=0;
                	flag=0;
				}
				switch(PRI(x,c)){
					case -1://������ջ�ж������ȼ����ڴӱ��ʽ��ȡ���Ĳ����������ȼ�����ô�ʹ���Ҫ������ջ
						SeqStackPush(StackOper,c);
						c=exp[i++];
						break;
					case 1://˵��ǰ�����ȼ�����ȡ�������ȼ����Ϳ����ȼ����� 
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
				flag=1;//׼����������ջ 
			}else
	        {
	            printf("�������!\n");
	            getch();
	            exit(0);
	        }
	         x=SeqStackPeek(StackOper);//��ȡջ��������� 
		}
		q=SeqStackPop(StackData);
    SeqStackFree(StackOper); 	//�ͷ�ջ��ռ�õĿռ� 
    SeqStackFree(StackData);
    return q; //��ջ�����ؽ�� 
}


int CalcExp(exp){
	
}
int main(){
	int c;
	char exp[80];
	printf("������Ҫ����ı��ʽ(��=����):"); 
    scanf("%s",exp);
    printf("%s%d\n",exp,CalcExp(exp));
} 
