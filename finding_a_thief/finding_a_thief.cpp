/*
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpLlKAQ4DFAUq
*/

#include <iostream>

using namespace std;

const int NMAX = 50;

int moving[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int map[NMAX][NMAX];
bool arr[NMAX][NMAX];
bool visit[NMAX][NMAX];
int n, m, r, c, l;

void print() {
	cout << "====" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j])
				cout << "8 ";
			else
				cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}

int calculate() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j])
				cnt++;
		}
	}
	return cnt;
}

bool checkDirection(int dir, int type) {
	if (dir == 0) {
		if (type == 1 || type == 2 || type == 4 || type == 7)
			return true;
	}
	else if (dir == 1) {
		if (type == 1 || type == 2 || type == 5 || type == 6)
			return true;
	}
	else if (dir == 2) {
		if (type == 1 || type == 3 || type == 6 || type == 7)
			return true;
	}
	else if (dir == 3) {
		if (type == 1 || type == 3 || type == 4 || type == 5)
			return true;
	}
	return false;
}

bool checkAvailabiliy(int dir, int next) {
	if (dir == 0) {
		if (next == 1 || next == 2 || next == 5 || next == 6)
			return true;
	}
	else if (dir == 1) {
		if (next == 1 || next == 2 || next == 4 || next == 7)
			return true;
	}
	else if (dir == 2) {
		if (next == 1 || next == 3 || next == 4 || next == 5)
			return true;
	}
	else if (dir == 3) {
		if (next == 1 || next == 3 || next == 6 || next == 7)
			return true;
	}
	return false;
}

void solve(int x, int y, int cnt) {
	if (cnt == l)
		return;

	for (int i = 0; i < 4; i++) {
		if (!checkDirection(i, map[x][y]))
			continue;

		int nx = x + moving[i][0];
		int ny = y + moving[i][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && checkAvailabiliy(i, map[nx][ny]) && !visit[nx][ny]) {
			//cout << "==== next = " << nx << ", " << ny << " cnt = " << cnt + 1 << " ====" << endl;
			visit[nx][ny] = true;
			arr[nx][ny] = true;
			//print();
			solve(nx, ny, cnt + 1);
			visit[nx][ny] = false;
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
				visit[i][j] = false;
				arr[i][j] = false;
			}
		}


		visit[r][c] = true;
		if (map[r][c] != 0)
			arr[r][c] = true;
		//cout << "==== start = " << r << ", " << c << " ====" << endl;
		solve(r, c, 1);
		cout << '#' << t + 1 << ' ' << calculate() << endl;
	}
}