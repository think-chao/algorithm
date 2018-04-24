int lengthOfLongestSubstring(char* s){
	int len=strlen(s);
	int max=-1;
	int tmp=0;
    if(len==0){
        return 0;
    }
	for(int i=0;i<len;i++){				//作用是统计每个字符所能够实现的最大子字符串长度 
		tmp=1;							//计算下一个字符的时候把临时的长度记为1 
		int j=i+1;						//都是从i后面的字符开始对比的 
		int repeat=0;					
		while(j<len&&repeat==0){		 
			int k=i;
			while(k<j){					//就是从j开始的字符不能和从i~j-1的任何字符相同 
				if(s[k]!=s[j]){		 
					k++;
				}else{
					repeat=1;
					break;
				}
			}
			if(k==j){					//假设从j开始的字符不和从i~j-1的任何字符相同，那么此时的k和j是相同的 
				tmp++;
				j++;
			} 
		}
		max=max>tmp?max:tmp;
	} 
	return max;

} 
