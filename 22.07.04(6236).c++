#include<iostream>
#include<string.h>
#include<math.h>
#define Max 100000
using namespace std;
int n, m;
int input[Max];
long long sum=0;
int main() {
	int low = 1;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
		sum += input[i];
		if (low < input[i]) {
			low = input[i];
		}
	}
	int high = sum;
	int time = 1;
	int mid = (high + low) / 2;
	int copy_mid = mid;
	for (int i = 0; i < n; i++) {
		mid -= input[i];
		if (mid < 0) {
			mid = copy_mid;
			time++;
		}
	}
	while (true) {
		while (time > m) {
			if (high - low == 1) {
				cout << high;
				return 0;
			}
			time = 1;
			low = copy_mid;
			mid = (high + low) / 2;
			copy_mid = mid;
			for (int i = 0; i < n; i++) {
				mid -= input[i];
				if (mid < 0) {
					i--;
					mid = copy_mid;
					time++;
				}
			}
		}
		while (time <= m) {
			if (high - low == 1 || high == low) {
				cout << low;
				return 0;
			}
			time = 1;
			high = copy_mid;
			mid = (high + low) / 2;
			copy_mid = mid;
			for (int i = 0; i < n; i++) {
				mid -= input[i];
				if (mid < 0) {
					i--;
					mid = copy_mid;
					time++;
				}
			}
		}
	}
	return 0;
}
