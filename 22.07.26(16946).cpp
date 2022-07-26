#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#define INF 99999999
using namespace std;
int n, m;
vector <pair<int, int>> v;
int board[1000][1000];
bool visit[1000][1000];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0, 0, -1, 1 };

void DFS(int y, int x) {
	queue <pair<int, int>> q;
	vector <pair<int, int>> v;
	q.push({ y,x });
	visit[y][x] = true;
	int cnt = 1;
	while (!q.empty()) {
		int h_y = q.front().first;
		int h_x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_y = h_y + dy[i];
			int next_x = h_x + dx[i];
			if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visit[next_y][next_x]==true)continue;
			visit[next_y][next_x] = true;
			if (board[next_y][next_x] == 0) {
				q.push({ next_y, next_x });
				cnt++;
			}
			else {
				v.push_back({ next_y, next_x });
			}
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		board[v[i].first][v[i].second] += cnt;
		visit[v[i].first][v[i].second] = false;
	}
}


int main() {
	memset(visit, false, sizeof(visit));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char a;
			cin >> a;
			board[i][j] = a - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] == false && board[i][j] == 0) {
				DFS(i, j);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << board[i][j]%10;
		}
		cout << endl;
	}
}