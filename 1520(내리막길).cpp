/*dp*/
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

/*점화식*/
/*cache[x][y] < cache[nx][ny] 이면
	dp[x][y] += dp[nx][ny]
	(nx,ny) = (x-1,y) or(x+1,y) or (x,y-1) or(x,y+1)
	기저사례 dp[0][0]=1*/

int dp[501][501];
int cache[501][501];
int M, N; // 세로, 가로
bool visit[500][500];

int solve(int x, int y) {
	visit[x][y] = true;
	if (dp[x][y] != -1)
		return dp[x][y];

	int dx[4] = { 0,-1,0,1 };
	int dy[4] = { -1,0,1,0 };
	int flag = false;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx > N || ny > M || nx < 0 || ny < 0)
			continue;
		/*틀린 이유 : 더 낮은 지역으로 이동한다고 하면 인접한 지역이 같거나 더 높은 걸 만나면 continue를 해주어야 하는데
		높을때만 continue를 해줘서 같은 경우까지 카운트되었다.*/
		if (cache[x][y] >= cache[nx][ny])
			continue;
		/*if (visit[nx][ny]) {
			printf("%d %d  (nx,ny) = (%d %d)\n", x, y,nx,ny);
			continue;
		}*/

		if (dp[nx][ny] == -1)
			dp[x][y] += solve(nx, ny);
		else
			dp[x][y] += dp[nx][ny];
		flag = true;
	}
	if (flag)
		dp[x][y]++;
	if (dp[x][y] == -1) { // 네 방향에서 올 수 있는 길을 다 탐색해도 여전히 초기값일때
		dp[x][y] = 0; // 이 셀로 갈 수 있는 경로가 없으면 0;
	}

	return dp[x][y];
}
int main() {
	scanf("%d %d", &M, &N);
	memset(dp, -1, sizeof(dp));


	for (int y = 0; y < M; y++) {
		for (int x = 0; x < N; x++)
			scanf("%d", &cache[x][y]);
	}
	dp[0][0] = 1;
	printf("%d\n", solve(N - 1, M - 1));
	//for (int y = 0; y < M; y++) {
	//	for (int x = 0; x < N; x++)
	//		printf("%d ", dp[x][y]);
	//	printf("\n");
	//}
}
