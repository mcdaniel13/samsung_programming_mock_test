/*
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PoOKKAPIDFAUq
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 8;

int n, k;


int moving[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
int map[NMAX][NMAX];
bool visit[NMAX][NMAX];
int result;

void print() {
	cout << "===" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j])
				cout << '0' << " ";
			else
				cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int x, int y, int val, int cnt, bool used) {
	for (int i = 0; i < 4; i++) {
		int nx = x + moving[i][0];
		int ny = y + moving[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visit[nx][ny]) {
			if (map[nx][ny] < val) {
				visit[nx][ny] = true;
				//cout << "==== next at " << nx << ", " << ny << " ====" <<  endl;
				//print();
				dfs(nx, ny, map[nx][ny], cnt + 1, used);
				//cout << "==== move back from " << nx << ", " << ny << " ====" << endl;
				visit[nx][ny] = false;
				continue;
			}
			if (map[nx][ny] - k < val && !used) {
				visit[nx][ny] = true;
				//cout << "==== [USED] next at " << nx << ", " << ny << " ====" << endl;
				//print();
				dfs(nx, ny, val - 1, cnt + 1, true);
				//cout << "==== move back from " << nx << ", " << ny << " ====" << endl;
				visit[nx][ny] = false;
				continue;
			}
		}
	}

	//cout << "stop!! cnt = " << cnt << endl;
	result = max(result, cnt);

}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visit[i][j] = false;
		}
	}
}

void solve(int start) {
	//find start point
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == start) {
				init();
				visit[i][j] = true;
				//cout << "====== start at " << i << ", " << j << " ======" << endl;
				//print();
				dfs(i, j, map[i][j], 1, false);
				visit[i][j] = false;
			}
		}
	}
}

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int start = 0;
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				start = max(start, map[i][j]);
			}
		}

		result = 0;
		solve(start);
		cout << "#" << t + 1 << " " << result << endl;
	}
	cout << endl;

}