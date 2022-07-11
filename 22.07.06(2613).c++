#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int m, n;
int c_mid = 0, mid = 0, high = 0, low = 0, sum = 0;
int input[300];

bool check(int answer) {
	int count = 1;
	int mid = answer;
	for (int i = 0; i < m; i++) {
		mid -= input[i];
		if (mid < 0) {
			count++;
			i--;
			mid = answer;
		}
	}
	return count <= n;
}



int main() {
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		cin >> input[i];
		sum += input[i];
		if (low < input[i])low = input[i];
	}
	int answer = 0;
	high = sum;
	while (low <= high) {
		mid = (low + high) / 2;
		if (check(mid)) {
			high = mid - 1;
			answer = mid;
		}
		else {
			low = mid + 1;
		}
	}
	cout << answer << endl;
	int count = 0;
	mid = answer;
	for (int i = 0; i < m; i++) {
		mid -= input[i];
		if (mid < 0) {
			cout << count << " ";
			n--;
			mid = answer - input[i];
			count = 0;
		}
		count++;
		if (m - i  == n) {
			cout << count << " ";
			n--;
			for (int i = 0; i < n; i++) {
				cout << 1 << " ";
			}
			break;
		}
	}
}
