#include <stdio.h>

int main(void){
	int cp[5001]; // 암호
	int dp[5001]={ 0, };
	
	int i=1;
	dp[0]=1;

	while(scanf("%1d", cp+i)!=EOF) {
		if(cp[i]>0)
			dp[i]=dp[i-1]%1000000;
			
		if(cp[i-1]==1||(cp[i-1]==2&&cp[i]<=6)) 
			dp[i]=(dp[i]+dp[i-2])%1000000;
			
		i++;
	}
	
	printf("%d\n", dp[i-1]%1000000);
}