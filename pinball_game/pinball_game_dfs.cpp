/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 100;

int n;

struct wormhole {
	int x[2];
	int y[2];
	int cnt;
};

int moving[4][2] = { {0, 1},{1, 0}, {0, -1}, {-1, 0} };
int map[NMAX][NMAX];
wormhole wh[5];
int sx, sy;
int result;

void print(int x, int y) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (x == i && y == j) {
				cout << 'P' << " ";
				continue;
			}
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int change(int dir, int type) {
	int ndir;
	if (dir == 0) {
		if (type == 1 || type == 2 || type == 5)
			ndir = 2;
		else if (type == 3)
			ndir = 1;
		else
			ndir = 3;
	}
	else if (dir == 1) {
		if (type == 2 || type == 3 || type == 5)
			ndir = 3;
		else if (type == 1)
			ndir = 0;
		else
			ndir = 2;
	}
	else if (dir == 2) {
		if (type == 3 || type == 4 || type == 5)
			ndir = 0;
		else if (type == 1)
			ndir = 3;
		else
			ndir = 1;
	}
	else {
		if (type == 1 || type == 4 || type == 5)
			ndir = 1;
		else if (type == 2)
			ndir = 0;
		else
			ndir = 2;
	}
	return ndir;
}

int dfs(int x, int y, int dir) {
	int nx = x;
	int ny = y;
	int ndir = dir;
	int point = 0;
	//print(x, y);
	while (true) {
		nx += moving[ndir][0];
		ny += moving[ndir][1];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (map[nx][ny] == -1 || (nx == sx && ny == sy))
				break;

			if (map[nx][ny] == 0)
				continue;
			else if (map[nx][ny] >= 1 && map[nx][ny] <= 5) {
				ndir = change(ndir, map[nx][ny]);
				point++;
				//cout << "== [ " << map[nx][ny] << "] = " << nx << ", " << ny << " dir - " << dir << " -> " << ndir << " ==" << endl;
			}
			else if (map[nx][ny] >= 6 && map[nx][ny] <= 10) {
				wormhole cur = wh[map[nx][ny] - 6];
				if (cur.x[0] == nx && cur.y[0] == ny) {
					nx = cur.x[1];
					ny = cur.y[1];
				}
				else {
					nx = cur.x[0];
					ny = cur.y[0];
				}
				//cout << "== [ " << map[nx][ny] << "] = " << nx << ", " << ny << " x,y -> " << nx << ", " << ny << " ==" << endl;
			}
		}
		else {
			ndir = (ndir + 2) % 4;
			point++;
			if (nx + moving[ndir][0] == sx && ny + moving[ndir][1] == sy)
				break;
		}
	}
	return point;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 0) {
				for (int k = 0; k < 4; k++) {
					sx = i;
					sy = j;
					//cout << "======== start = " << sx << ", " << sy << " ========" << endl;
					result = max(result, dfs(sx, sy, k));
				}
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n;

		////init
		for (int i = 0; i < 5; i++) {
			wh[i].cnt = 0;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
				if (map[i][j] >= 6 && map[i][j] <= 10) {
					wh[map[i][j] - 6].x[wh[map[i][j] - 6].cnt] = i;
					wh[map[i][j] - 6].y[wh[map[i][j] - 6].cnt] = j;
					wh[map[i][j] - 6].cnt++;
				}
			}
		}

		result = 0;
		solve();
		cout << '#' << t + 1 << ' ' << result << endl;
	}
}