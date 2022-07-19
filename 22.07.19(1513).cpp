#include<iostream>
#include<string.h>
#include<math.h>
#include<vector>
using namespace std;
int dp[51][51][51][51]; //y,x,count,orak
int n, m, c;
int vec[51][51];

int solve(int y, int x, int count, int  orak) {
	if (y < 1 || x < 1 || count < 0)return 0;
	int& r = dp[y][x][count][orak];
	if (r != -1)return r;
	r = 0;
	if(vec[y][x] == 0) {
		//오락실이 아닌 경우(이동 - 우측, 하단)
		r = solve(y - 1, x, count, orak) % 1000007  + solve(y, x - 1, count, orak) % 1000007;
	}
	
	//오락실인 경우 == (y,x)
	else if (vec[y][x] == orak) {
		for (int i = 0; i < orak; i++) {
			r += solve(y - 1, x, count -1 , i) % 1000007  + solve(y, x - 1, count - 1, i) % 1000007;
		}
	}

	return r % 1000007;
}


int main() {
	cin >> n >> m >> c;
	memset(vec, 0, sizeof(vec));
	int a, b;
	for (int i = 1; i <= c; i++) {
		cin >> a >> b;
		vec[a][b] = i;
		//vec.push_back({ a,b });
	}
	memset(dp, -1, sizeof(dp));
	if (vec[1][1] == 0) {
		dp[1][1][0][0] = 1;
	}
	else {
		dp[1][1][1][vec[1][1]] = 1;
	}
	int answer = 0;
	for (int i = 0; i <= c; i++) {
		answer = 0;
		for (int j = 0; j <= c; j++) {
			answer += solve(n, m, i, j)%1000007;
		}
		cout << answer%1000007 << " ";
	}
}
