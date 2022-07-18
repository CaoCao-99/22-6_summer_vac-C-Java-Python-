#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

int r, c;
int input[1500][1500][2], banana[1500][1500], apple[1500][1500], sum[1500][1500];
int answer[1500][1500];
int main() {
	cin >> r >> c;
	char a;
	int b;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a;
			cin >> b;
			if (a == 'A') {
				input[i][j][0] = b;
			}
			else {
				input[i][j][1] = b;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = c - 1; j > 0; j--) {
			//banana
			banana[i][j-1] = banana[i][j] + input[i][j][1];
			//apple
			apple[i][c - j] = apple[i][c - j - 1] + input[i][c - j - 1][0];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum[i][j] = banana[i][j] + apple[i][j];
		}
	}
	answer[0][0] = sum[0][0];
	for (int i = 1; i < r; i++) {
		answer[i][0] = answer[i - 1][0] + sum[i][0];
	}
	for (int i = 1; i < c; i++) {
		answer[0][i] = answer[0][i-1] - input[0][i][1];
	}
	for (int i = 1; i < r; i++) {
		for (int j = 1; j < c; j++) {
			//right(-banana)
			int right = answer[i][j - 1] - input[i][j][1];

			//down
			int down = answer[i - 1][j] + sum[i][j];

			//r-d
			int r_d = answer[i - 1][j - 1] + sum[i][j];
			answer[i][j] = max(right, max(down, r_d));
		}
	}
	cout << answer[r - 1][c - 1];
}