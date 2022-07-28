#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
#define Max 10001
using namespace std;
int n, m, s, t, cnt, scnt = 1;
int discovered[Max], sccn[Max];
int country[Max], result[Max];
vector<vector<int>>adj, scc;
stack<int>st;
int start, target;

int DFS(int x) {
	st.push(x);
	discovered[x] = cnt++;
	int parent = discovered[x];
	for (int i = 0; i < adj[x].size(); i++) {
		int next = adj[x][i];
		if (discovered[next] == -1) {
			parent = min(parent, DFS(next));
		}
		else if (sccn[next] == -1) {
			parent = min(parent, discovered[next]);
		}
	}
	if (parent == discovered[x]) {
		while (true) {
			int here = st.top();
			st.pop();
			if (s == here)start = scnt;
			if (t == here)target = scnt;
			sccn[here] = scnt;
			country[scnt]++;
			if (here == x)break;
		}
		scnt++;
	}
	return parent;
}

void BFS(int start) {
	queue<int> q;
	q.push(start);
	result[start] = country[start];
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		for (int i = 0; i < scc[here].size(); i++) {
			int next = scc[here][i];
			if (result[next] < result[here] + country[next]) {
				result[next] = result[here] + country[next];
				q.push(next);
			}
		}
	}
}

int main() {
	cin >> n >> m >> s >> t;
	adj.resize(n+1);
	scc.resize(n + 1);
		int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
	}
	memset(discovered, -1, sizeof(discovered));
	memset(country, 0, sizeof(country));
	memset(result, 0, sizeof(result));
	memset(sccn, -1, sizeof(sccn));
	for (int i = 1; i <= n; i++) {
		if (discovered[i] == -1)DFS(i);
	}
	if (start == target) {
		cout << country[start] << endl;
		return 0;
	}
	for (int s = 1; s <= n; s++) {
		for (int i = 0; i < adj[s].size(); i++) {
			int next = sccn[adj[s][i]];
			if (sccn[s] != next) {
				scc[sccn[s]].push_back(next);
			}
		}
	}
	BFS(start);
	cout << result[target] << endl;
	return 0;
}