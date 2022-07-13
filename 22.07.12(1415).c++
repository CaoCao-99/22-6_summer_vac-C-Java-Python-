#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;
int cost[10001]; //1~10000까지의 개수 
int n;
int answer[500001];
//int input[50];
bool Prime[500001];
int k[50];
int kind[50];
void GetPrime() {
	memset(Prime, true, sizeof(Prime));
	for (int i = 2; i * i < 500000; i++) {
		if (Prime[i] == false)continue;
		for (int j = i * i; j < 500000; j += i) {
			Prime[j] = false;
		}
	}
}

int main() {
	int z_cnt = 1;
	GetPrime();
	for (int i = 0; i < 500000; i++) {
		answer[i] = 0;
	}
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0)z_cnt++;
		k[i] = a;
		cost[a]++;
	}


	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (k[i] == k[j]) {
				k[j] = -1;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (k[i] != -1 && k[i] != 0) {
			kind[cnt++] = k[i];
		}
	}

	answer[0] = 1;

	//숫자 종류
	for (int i = 0; i < cnt; i++) {

		for (int j = 500000; j > 0; j--)
		{
			for (int x = 1; x <= cost[kind[i]] && j >= x*kind[i]; x++) {
					answer[j] += answer[j - x * kind[i]];
			}
		}
	}
	long long cc = 0;

	for (int i = 2; i < 500000; i++) {
		if (Prime[i] && answer[i] >0) {
			cc += answer[i];
		}
	}


	cout << cc * z_cnt;


}