#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
#define Max 10001
using namespace std;
int n, m, k;
long long dp[10001][21];

vector <pair<int,int>>input[10001];

void BFS() {
	priority_queue <pair<long long, pair<int, int>>> pq;//가중치, 현재도시, 포장 개수
	memset(dp, -1, sizeof(dp));
	pq.push({ 0,{1, 0} });
	dp[1][0] = 0;
	while (!pq.empty()) {
		long long h_c = -pq.top().first;
		int here = pq.top().second.first;
		int road = pq.top().second.second;
		pq.pop();
		if (dp[here][road] < h_c)continue;
		for (int i = 0; i < input[here].size(); i++) {
			int next = input[here][i].first;
			long long next_c = input[here][i].second;
			if (road < k) {
				if (dp[next][road+1] == -1 || dp[next][road+1] > h_c) {
					dp[next][road + 1] = h_c;
					pq.push({ -dp[next][road+1],{next, road+1} });
				}
			}
			if (dp[next][road] == -1 || dp[next][road] > (h_c + next_c)) {
				dp[next][road] = (h_c + next_c);
				pq.push({ -dp[next][road],{next, road} });
			}
		}

	}
	long long a = 9999999999;
	for (int i = 0; i <= 20; i++) {
		if (dp[n][i] != -1) {
			a = min(dp[n][i], a);
		}

	}
	cout << a<<endl;
}


int main() {
	cin >> n >> m >> k;
	int a, b, c;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		input[a].push_back({ b,c });
		input[b].push_back({ a,c });
	}
	BFS();

	return 0;
}