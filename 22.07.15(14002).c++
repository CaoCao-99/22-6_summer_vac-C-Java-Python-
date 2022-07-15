#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int n;
int cnt = 0;
int input[1000];
int dp[1000];
int parent[1000];
int check = 0;
int answer = 0;	
int idx = 0;

void printAns(int p) {
	check++;
	if (check == answer) {
		cout << input[p] << " ";
		return;
	}
	printAns(parent[p]);
	cout << input[p] << " ";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		dp[i] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j && input[i] > input[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
				parent[i] = j;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (answer < dp[i]) {
			answer = dp[i];
			idx = i;
		}
	}
	cout << answer << endl;

	printAns(idx);

}