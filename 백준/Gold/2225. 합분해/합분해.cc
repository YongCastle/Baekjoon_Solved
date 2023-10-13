#include <cstdio>
int main(void){
	int n,k,dp[201]= {1,};scanf("%d %d",&n,&k);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= n; j++)
			dp[j] = (dp[j]+dp[j-1])%1000000000;
	printf("%d",dp[n]);
}