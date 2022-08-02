#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
#define Max -100000000
using namespace std;
int flow[52][52];
int cap[52][52];
int visit[52];
vector <int> input[52];
int n;

int change(char a) {
	if (a >= 'a')return a - 'a' + 26;
	return a - 'A';
}


int main() {
	cin >> n;
	memset(flow, 0, sizeof(flow));
	memset(cap, 0, sizeof(cap));
	int answer = 0;
	char a, b;
	int c;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		a = change(a);
		b = change(b);
		cap[a][b] += c;
		cap[b][a] += c;
		input[a].push_back(b);
		input[b].push_back(a);
	}
	int sink = change('Z');


	while (1) {
		memset(visit, -1, sizeof(visit));
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			int here = q.front();
			if (here == sink)break;
			q.pop();
			for (int i = 0; i < input[here].size(); i++) {
				int next = input[here][i];
				if (visit[next] == -1 && cap[here][next] - flow[here][next] > 0) {
					visit[next] = here;
					q.push(next);
				}
			}
		}
		if (visit[sink] == -1)break;
		int mini = 999999999;

		for (int i = sink; i != 0; i = visit[i]) {
			mini = min(mini, cap[visit[i]][i] - flow[visit[i]][i]);
		}
		for (int i = sink; i != 0; i = visit[i]) {
			flow[visit[i]][i] += mini;
			flow[i][visit[i]] -= mini;
		}
		answer += mini;
	}
	cout << answer<<endl;
}
