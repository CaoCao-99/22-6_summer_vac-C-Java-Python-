#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int n;
int input[64][64];

void recursive(int y, int x , int size) {
	bool onlyone = true;
	bool onlyzero = true;
	if (size == 1) {
		cout << input[y][x];
		return;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (input[y + i][x + j] == 1) {
				onlyzero = false;
			}
			if (input[y + i][x + j] == 0) {
				onlyone = false;
			}
		}
	}

	if (onlyone) {
		cout << 1;
		return;
	}
	if (onlyzero) {
		cout << 0;
		return;
	}

	cout << '(';
	int resize = size / 2;
	//좌측 상단
	recursive(y, x, resize);
	//우측 상단
	recursive(y, x + resize, resize);
	//좌측 하단
	recursive(y + resize, x, resize);
	//우측 하단
	recursive(y + resize, x + resize, resize);
	cout << ')';
}


int main() {
	//n값 입력 받기
	cin >> n;
	char a;
	//n개의 값 입력 받기(input)
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			input[i][j] = a-'0';
		}
	}

	recursive(0,0,n);
}