#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#define INF 99999999
using namespace std;
int W[16][16];
int dp[16][1 << 16];
int n;


int TSP(int now, int visit) {
	visit |= 1 << now;
	if (visit == (1 << n) - 1) {
		if (W[now][0] != 0)return W[now][0];
		else return INF;
	}
	int& answer = dp[now][visit];
	if (answer != -1)return answer;
	answer = INF;
	
	for (int i = 0; i < n; i++) {
		int dist = 0;
		if (i != now && (visit & (1 << i)) == 0 && W[now][i] != 0) {
			dist += TSP(i, visit) + W[now][i];
			answer = min(answer, dist);
		}
	}

	return answer;
}

int main() {
	cin >> n;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			cin >> W[i][j];
		}}
	cout << TSP(0, 0);
}
