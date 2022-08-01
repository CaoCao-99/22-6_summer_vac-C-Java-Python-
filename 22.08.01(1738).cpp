#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
#define Max -100000000
using namespace std;
vector <pair<int, int>> input[101];
vector<int>rev[101];
int parent[101];
bool visit[101];
int cost[101];
int n, m;

void answer(int a) {
	if (a == 1) {
		cout << a << " ";
		return;
	}
	answer(parent[a]);
	cout << a << " ";
}

int main() {
	memset(cost, Max, sizeof(cost));
	memset(visit, false, sizeof(visit));
	cost[1] = 0;
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		input[a].push_back({ b,c });
		rev[b].push_back(a);
	}
	queue<int> q;
	q.push(n);
	visit[n] = true;
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < rev[here].size(); i++) {
			int next = rev[here][i];
			if (visit[next] == false) {
				visit[next] = true;
				q.push(next);
			}
		}
	}
	for (int x = 1; x <= n; x++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < input[i].size(); j++) {
				if (cost[i] != Max && cost[input[i][j].first] < cost[i] + input[i][j].second) {
					cost[input[i][j].first] = cost[i] + input[i][j].second;
					parent[input[i][j].first] = i;
					if (x == n && visit[1] == true) {
						cout << -1;
						return 0;
					}
				}
			}
		}
	}

	answer(n);
	return 0;
}
