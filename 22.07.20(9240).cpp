#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int C;
vector <pair<int, int>> v;

double dist(pair<int, int> a, pair<int, int> b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}


int CCW(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	return a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second);
}

bool check(pair<int, int> a, pair<int, int> b) {
	int ch = CCW(v[0], a, b);
	if (ch != 0)return ch > 0;
	else if (a.second != b.second) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

int main() {
	cin >> C;
	int a, b;
	v.resize(C+1);
	for (int i = 1; i <= C; i++) {
		cin >> a >> b;
		v[i] = { a,b };
	}
	for (int i = 2; i <= C; i++) {
		if (v[1].second > v[i].second || v[1].second == v[i].second && v[1].first > v[i].first) {
			swap(v[1], v[i]);
		}
	}
	sort(v.begin() + 2, v.end(), check);
	vector <pair <int, int>> q;
	q.push_back(v[1]);
	q.push_back(v[2]);
	
	for (int i = 3; i <= C; i++) {
		while (q.size() > 2 && CCW(q[q.size() - 2], q[q.size() - 1], v[i]) <= 0) {
			q.pop_back();
		}
		q.push_back(v[i]);
	}
	double answer = 0.f;
	for (int i = 0; i < q.size(); i++) {
		for (int j = i + 1; j < q.size(); j++) {
			double di = dist(q[i], q[j]);
			if (answer < di ) {
				answer = di;
			}
		}
	}
	printf("%.6f", answer);
}
