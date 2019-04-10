/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl
 */

#include <iostream>

using namespace std;

const int NMAX = 100;
const int KMAX = 1000;

struct bacteria {
	int x;
	int y;
	int dir;
	int cnt;
	bacteria() {}
	bacteria(int x_, int y_, int dir_, int cnt_) {
		x = x_;
		y = y_;
		dir = dir_;
		cnt = cnt_;
	}
};

int moving[5][2] = { {0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int map[NMAX][NMAX];
int index[NMAX][NMAX];
bacteria arr[KMAX];

int n, m, k;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
		}
	}
}

int solve() {
	int ck = k;
	for (int j = 0; j < m; j++) {
		init();
		int nk = 0;
		for (int i = 0; i < ck; i++) {
			bool flag = true;
			arr[i].x += moving[arr[i].dir][0];
			arr[i].y += moving[arr[i].dir][1];
			if (arr[i].x == 0 || arr[i].x == n - 1 || arr[i].y == 0 || arr[i].y == n - 1) {
				arr[i].cnt /= 2;
				if (arr[i].dir % 2 == 1)
					arr[i].dir += 1;
				else
					arr[i].dir -= 1;
			}
			else {
				if (map[arr[i].x][arr[i].y] == 0) {
					map[arr[i].x][arr[i].y] = arr[i].cnt;
					index[arr[i].x][arr[i].y] = nk;
				}
				else {
					flag = false;
					if (map[arr[i].x][arr[i].y] < arr[i].cnt) {
						map[arr[i].x][arr[i].y] = arr[i].cnt;
						arr[index[arr[i].x][arr[i].y]].dir = arr[i].dir;
					}
					arr[index[arr[i].x][arr[i].y]].cnt += arr[i].cnt;
				}
			}

			if (flag) {
				arr[nk] = bacteria(arr[i].x, arr[i].y, arr[i].dir, arr[i].cnt);
				nk++;
			}
		}
		ck = nk;
	}

	int total = 0;
	for (int j = 0; j < ck; j++)
		total += arr[j].cnt;

	return total;
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++) {
			cin >> arr[i].x >> arr[i].y >> arr[i].cnt >> arr[i].dir;
		}

		cout << "#" << t + 1 << " " << solve() << endl;
	}
}