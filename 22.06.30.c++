#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int MAX = 10000 + 1;
const int INF = 987654321;
int N, nodeIdx=1; //N과 노드의 위치
int node[MAX]; //루트 찾기
int low[MAX]; //레벨에서의 가장 좌측
int high[MAX]; //레벨에서의 가장 우측
int length[MAX]; // 차이값
pair<int, int> tree[MAX]; // 입력값



void DFS(int parent, int cnt) {
	if (tree[parent].first != -1) {
		DFS(tree[parent].first, cnt + 1);
	}
	//좌측 노드 구하기
	low[cnt] = min(low[cnt], nodeIdx);
	//우측 노드 구하기
	high[cnt] = max(high[cnt], nodeIdx);
	//인덱스 번호 늘려주기
	nodeIdx++;
	length[cnt] = high[cnt] - low[cnt]+1;


	if (tree[parent].second != -1) {
		DFS(tree[parent].second, cnt + 1);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		low[i] = INF;
		node[i] = 0;
	}
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		node[a]++;
		if (b != -1) {
			node[b]++;
		}
		if (c != -1) {
			node[c]++;
		}
		tree[a].first = b;
		tree[a].second = c;
	}
	int root = 0;

	//루트 구하기
	for (int i = 1; i <= N; i++) {
		if (node[i] == 1) {
			root = i;
			break;
		}
	}

	DFS(root, 1);
	int answer = 0;
	int answer_level = 1;
	for (int i = 1; i < 20; i++) {
		if (answer < length[i]) {
			answer = length[i];
			answer_level = i;
		}
	}
	cout << answer_level << " " << answer;
}
