#include <iostream>
#include <bits/stdc++.h>
#define MAX(a, b) (((a) > (b))? (a) : (b))

//DP(N) = MAX{F(N) , F(N-1)+DP(1) + F(N-2) + DP(2)
//DP[1] = F[1]
//DP[2] = MAX(F[2], F[1]+DP[1])
//DP[N] = MAX{F[1]+DP[N-1], ... F[N]+DP[0]}
int update(const int * P, const int N){
	int* DP = new int[N+1];
	DP[0] = 0;
	int tmp_max=0;
	for(int i=1; i<N+1; i++){
		for(int j=1; j<=i; j++){
			tmp_max = MAX(tmp_max, P[j] + DP[i-j]);
		}
		DP[i] = tmp_max;
	}
	int ret = DP[N];
	delete[] DP;
	return ret;
}

int main(void){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0); std::cout.tie(0);
	int N;
	std::cin>>N;

	int* P = new int[N+1];
	for(int i=1; i<N+1; i++){
		std::cin>>P[i];
	}

	std::cout<<update(P, N);
	
	return 0;
}