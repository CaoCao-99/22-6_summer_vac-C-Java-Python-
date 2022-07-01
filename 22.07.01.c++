#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char answer[1024*3][1024*6];


void draw(int center, int height, int length) {
	if (length == 3) {
		answer[height][center] = '*';
		answer[height + 1][center - 1] = '*';
		answer[height + 1][center + 1] = '*';
		for (int i = -2; i < 3; i++) {
			answer[height + 2][center + i] = '*';
		}
		return;
	}
	//중앙
	draw(center, height, length / 2);
	//좌측
	draw(center - length / 2, height + length / 2, length / 2);
	//우측
	draw(center + length / 2, height + length / 2, length / 2);
}




int main() {
	memset(answer, ' ', sizeof(answer));
	int n;
	cin >> n;
	draw(n - 1, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			cout << answer[i][j];
		}
		cout << endl;
	}
}