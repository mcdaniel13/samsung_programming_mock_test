/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu
 */
#include <iostream>
#include <algorithm>

using namespace std;

const int NMAX = 20;

int n, m;

int map[NMAX][NMAX];
int K[NMAX + 1];
int cnt;
int maxCount;

void calculate(int row, int x, int start, int end) {
	if (start > end || (x < 0 || x >= n))
		return;

	for (int i = start; i <= end; i++) {
		if (i >= 0 && i < n && map[x][i] == 1)
			cnt++;
	}

	if (x <= row)
		calculate(row, x - 1, start + 1, end - 1);

	if (x >= row)
		calculate(row, x + 1, start + 1, end - 1);
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << "==== start = " << i << ", " << j << " ====" << endl;
			//find at each k
			for (int k = 0; k < n + 1; k++) {
				cnt = 0;
				calculate(i, i, j - k, j + k);
				//cout << "k = " << k << " cnt = " << cnt << " ";
				//cout << "total = " << total << endl;
				if (cnt * m - K[k] >= 0)
					maxCount = max(maxCount, cnt);
			}
		}
	}
}


int main() {
	int test;
	cin >> test;

	//init
	K[0] = 1;
	for (int i = 1; i < NMAX + 1; i++)
		K[i] = K[i - 1] + 4 * i;


	for (int t = 0; t < test; t++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		maxCount = 0;
		solve();
		cout << "#" << t + 1 << " " << maxCount << endl;
	}
}
}