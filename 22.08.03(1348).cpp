#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<stack>
#include<queue>
#define Max 100000000
using namespace std;
char input[50][50];
vector <int> v[100];
int parking[100][2];//주차공간 좌표
int dist[100][100];
int p_cnt = 0;
int c_cnt = 0;
int car[100][2];
int n, m;
int visit[50][50];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int check[101];
int used[101];
void BFS(int start) {
	memset(visit, -1, sizeof(visit));
	queue<pair<int, int>> q;
	q.push({ car[start][0], car[start][1] });
	visit[car[start][0]][car[start][1]] = 0;
	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int n_y = y + dy[i];
			int n_x = x + dx[i];
			if (n_y < 0 || n_x < 0 || n_y >= n || n_x >= m || visit[n_y][n_x] != -1 || input[n_y][n_x] == 'X')continue;
			visit[n_y][n_x] = visit[y][x] + 1;
			q.push({ n_y,n_x });
		}
	}
	for (int i = 0; i < p_cnt; i++) {
		if (visit[parking[i][0]][parking[i][1]] == -1) {
			dist[start][i] = Max;
		}
		else {
			dist[start][i] = visit[parking[i][0]][parking[i][1]];
			v[start].push_back(i);
		}
	}

}

bool DFS(int car_num,int time) {
	for (int i = 0; i < v[car_num].size(); i++) {
		int next = v[car_num][i];
		if (check[next] == true || dist[car_num][next] > time)continue;
		check[next] = true;
		if (used[next] == -1 || DFS(used[next], time)) {
			used[next] = car_num;
			return true;
		}
	}
	return false;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> input[i][j];
			if (input[i][j] == 'P') {
				parking[p_cnt][0] = i;
				parking[p_cnt][1] = j;
				p_cnt++;
			}
			if (input[i][j] == 'C') {
				car[c_cnt][0] = i;
				car[c_cnt][1] = j;
				c_cnt++;
			}
		}
	}
	if (c_cnt > p_cnt) {
		cout << -1;
		return 0;
	}
	if (c_cnt == 0) {
		cout << 0;
		return 0;
	}
	for (int i = 0; i < c_cnt; i++) {
		BFS(i);
	}
	int s = 0, e = 101 * 101, mid = 0, ret = 0;
	int answer = -1;
	while (s <= e) {
		ret = 0;
		memset(used, -1, sizeof(used));
		mid = (s + e) / 2;
		for (int i = 0; i < c_cnt; i++) {
			memset(check, false, sizeof(check));
			if (DFS(i, mid)) {
				ret++;
			}
		}
		if (ret == c_cnt) {
			answer = mid;
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}

	cout << answer << endl;


}