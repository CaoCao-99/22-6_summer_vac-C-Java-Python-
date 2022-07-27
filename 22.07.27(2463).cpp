#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#define INF 99999999
using namespace std;
typedef struct st {
	int x;
	int y;
	int w;
};
st input[100001];
long long sum;
int n, m;
int parent[100001];
long long Size[100001];



bool cmp(st a, st b) {
	return a.w > b.w;
}

int getParent(int a) {
	if (parent[a] == a)return a;
	return getParent(parent[a]);
}
void mergeParent(int a, int b) {
	if (Size[a] > Size[b]) {
		parent[b] = a;
		Size[a] += Size[b];
		Size[b] = 1;
	}
	else {
		parent[a] = b;
		Size[b] += Size[a];
		Size[a] = 1;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		Size[i] = 1;
	}
	for (int i = 1; i <= m; i++) {
		cin >> input[i].x;
		cin >> input[i].y;
		cin >> input[i].w;
		sum += input[i].w;
	}
	long long answer = 0;
	sort(input+1, input + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int a = getParent(input[i].x);
		int b = getParent(input[i].y);
		if (a != b) {
			
			answer += (((Size[a] * Size[b]) % 1000000000) * sum) % 1000000000;
			mergeParent(a, b);
		}
		sum -= input[i].w;
	}
	cout << answer % 1000000000;


}