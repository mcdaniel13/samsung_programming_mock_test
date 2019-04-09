/*
	https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5VwAr6APYDFAWu
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 20;
const int MMAX = 101;
int n;

int moving[4][2] = { {1, 1}, {1, -1}, {-1, -1}, {-1, 1} };
int map[NMAX][NMAX];
int visit[MMAX];
int sx, sy;
int maxCount;

struct point {
	int x;
	int y;
	int a;
	int b;
	int d;
	point(int x_, int y_) {
		x = x_;
		y = y_;
	}
};

void init() {
	for (int i = 0; i < MMAX; i++)
		visit[i] = false;
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "======== start = " << i << ", " << j << " =========" << endl;
			for (int a = 1; a < n - 1; a++) {
				for (int b = 1; b < n - 1; b++) {
					if (j - b >= 0 && j + a < n && i + a + b < n && (a + b) * 2 > maxCount) {
						//cout << "==== diag a = " << a << " diag b = " << j << " ====" << endl;
						bool flag = true;
						init();
						int cx = i;
						int cy = j;
						for (int m = 0; m < 4; m++) {
							//cout << "=== dir = " << m << "===" << endl;
							int cnt;
							if (m == 0 || m == 2)
								cnt = a;
							else
								cnt = b;

							for (int k = 0; k < cnt; k++) {
								cx += moving[m][0];
								cy += moving[m][1];
								if (!visit[map[cx][cy]]) {
									//cout << "next = " << cx << ", " << cy << endl;
									visit[map[cx][cy]] = true;
								}
								else {
									//cout << "stop = " << cx << ", " << cy << endl;
									flag = false;
									break;
								}
							}
							if (!flag)
								break;
						}
						if (flag)
							maxCount = max(maxCount, (a + b) * 2);
					}
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
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		maxCount = -1;
		solve();
		cout << "#" << t + 1 << " " << maxCount << endl;
	}
}