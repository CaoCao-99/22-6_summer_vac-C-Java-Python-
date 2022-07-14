#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<string>
#define Max 17002
using namespace std;
char first[17002];
char second[17002];
int dp[2][17002];
//비트 마스킹?
struct bit {
	unsigned char a : 2;
	unsigned char b : 2;
	unsigned char c : 2;
	unsigned char d : 2;
};
string fir;
string sec;
bit answer[Max / 2][Max / 2];


void printAns(int n, int m) {
	if (n == 0 && m == 0) { 
		return; 
	}
	else if (n == 0 && m > 0) {
		printAns(n, m - 1);
		cout << "a " << sec[m] << endl;
	}
	else if (n > 0 && m == 0) {
		printAns(n - 1, m);
		cout << "d " << fir[n] << endl;
	}
	else if (n % 2 == 0 && m % 2 == 0) {
		if (answer[n / 2][m / 2].a == 2) {
			printAns(n, m - 1);
			cout << "a " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].a == 3) {
			printAns(n - 1, m - 1);
			cout << "m " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].a == 1) {
			printAns(n - 1, m);
			cout << "d " << fir[n] << endl;
		}
		else {
			printAns(n - 1, m - 1);
			cout << "c " << fir[n] << endl;
		}
	}
	else if (n % 2 == 0 && m % 2 == 1) {
		if (answer[n / 2][m / 2].b == 2) {
			printAns(n, m - 1);
			cout << "a " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].b == 3) {
			printAns(n - 1, m - 1);
			cout << "m " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].b == 1) {
			printAns(n - 1, m);
			cout << "d " << fir[n] << endl;
		}
		else {
			printAns(n - 1, m - 1);
			cout << "c " << fir[n] << endl;
		}
	}
	else if (n % 2 == 1 && m % 2 == 0) {
		if (answer[n / 2][m / 2].c == 2) {
			printAns(n, m - 1);
			cout << "a " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].c == 3) {
			printAns(n - 1, m - 1);
			cout << "m " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].c == 1) {
			printAns(n - 1, m);
			cout << "d " << fir[n] << endl;
		}
		else {
			printAns(n - 1, m - 1);
			cout << "c " << fir[n] << endl;
		}
	}
	else{
		if (answer[n / 2][m / 2].d == 2) {
			printAns(n, m - 1);
			cout << "a " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].d == 3) {
			printAns(n - 1, m - 1);
			cout << "m " << sec[m] << endl;
		}
		else if (answer[n / 2][m / 2].d == 1) {
			printAns(n - 1, m);
			cout << "d " << fir[n] << endl;
		}
		else {
			printAns(n - 1, m - 1);
			cout << "c " << fir[n] << endl;
		}
	}
}


void setting(int n, int m, char aa) {
	if (n % 2 == 0 && m % 2 == 0) {
		answer[n / 2][m / 2].a = aa;
	}
	else if (n % 2 == 0 && m % 2 == 1) {
		answer[n / 2][m / 2].b = aa;
	}
	else if (n % 2 == 1 && m % 2 == 0) {
		answer[n / 2][m / 2].c = aa;
	}
	else {
		answer[n / 2][m / 2].d = aa;
	}
}

int main() {
	cin >> fir;
	cin >> sec;
	fir = '#' + fir;
	sec = '#' + sec;
	for (int i = 0; i < fir.length(); i++) {
		dp[0][i] = i;
		setting(0, i, 1);
		setting(i, 0, 2);
	}

	for (int i = 1; i < fir.length(); i++) {
		dp[i][0]=i;
		for (int j = 1; j < sec.length(); j++) {

			if (fir[i] == sec[j]) {
				//좌측 상단에서 값 받기
				dp[i % 2][j] = dp[!(i % 2)][j - 1];
				setting(i, j, 0);
			}
			else {
				dp[i % 2][j] = min(dp[i % 2][j - 1], (min(dp[!(i % 2)][j - 1], dp[!(i % 2)][j])))+1;
				if (dp[i % 2][j] == dp[i % 2][j - 1] + 1) {
					setting(i, j, 2);
				}
				else if (dp[i % 2][j] == dp[!(i % 2)][j - 1] + 1) {
					setting(i, j, 3);
				}
				else {
					setting(i, j, 1);
				}
			}
		}
	}


	printAns(fir.length() - 1, sec.length() - 1);


}