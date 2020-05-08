#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

int T[16], P[16];
int dp[16];
int N;
int solve(int i) {
	if(i >= N)
		return 0;
	if(dp[i] != -1)
		return dp[i];
	if(i + T[i] <= N)
		return dp[i] = max(P[i] + solve(i + T[i]), solve(i + 1));
	else
		return dp[i] = solve(i + 1);
}
int main() {
	memset(dp, -1,sizeof(dp));
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d",&T[i],&P[i]);
	}
	printf("%d", solve(0));
}