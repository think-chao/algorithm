int lengthOfLongestSubstring(char* s){
	int len=strlen(s);
	int max=-1;
	int tmp=0;
    if(len==0){
        return 0;
    }
	for(int i=0;i<len;i++){				//������ͳ��ÿ���ַ����ܹ�ʵ�ֵ�������ַ������� 
		tmp=1;							//������һ���ַ���ʱ�����ʱ�ĳ��ȼ�Ϊ1 
		int j=i+1;						//���Ǵ�i������ַ���ʼ�Աȵ� 
		int repeat=0;					
		while(j<len&&repeat==0){		 
			int k=i;
			while(k<j){					//���Ǵ�j��ʼ���ַ����ܺʹ�i~j-1���κ��ַ���ͬ 
				if(s[k]!=s[j]){		 
					k++;
				}else{
					repeat=1;
					break;
				}
			}
			if(k==j){					//�����j��ʼ���ַ����ʹ�i~j-1���κ��ַ���ͬ����ô��ʱ��k��j����ͬ�� 
				tmp++;
				j++;
			} 
		}
		max=max>tmp?max:tmp;
	} 
	return max;

} 
