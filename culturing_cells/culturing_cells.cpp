/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRJ8EKe48DFAUo&
 */
#include <iostream>

using namespace std;

const int NMAX = 50;
const int MMAX = 150;

int n, m, k;
int moving[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
struct Cell {
    int state;      // 0 = nothing 1 = diactivate 2 = activate 3 = dead
    int actCount;
    int liveCount;
};

Cell arr[NMAX + MMAX + MMAX + 2][NMAX + MMAX + MMAX + 2][2];        //       0 = prev     1 = cur

void print(int curMap) {
    cout << "curMap = " << curMap << endl;
    for(int i = 0; i < n + k + 2; i++) {
        for (int j = 0; j < m + k + 2; j++) {
            cout << "[" << arr[i][j][curMap].state << "," << arr[i][j][curMap].liveCount << "," << arr[i][j][curMap].actCount << "] ";
        }
        cout << endl;
    }
}

int solve() {
    int curMap = 0;
    //print(curMap);
    for (int l = 0; l < k; l++) {
        //cout << "===== round #" << l + 1 << " =====" << endl;
        for (int i = 0; i < n + k + 2; i++) {
            for (int j = 0; j < m + k + 2; j++) {
                if (arr[i][j][curMap].state == 3) {
                    arr[i][j][1 - curMap].state = arr[i][j][curMap].state;
                } else if (arr[i][j][curMap].state == 1) {
                    arr[i][j][1 - curMap].actCount = arr[i][j][curMap].actCount + 1;
                    arr[i][j][1 - curMap].liveCount = arr[i][j][curMap].liveCount;
                    if (arr[i][j][1 - curMap].actCount == arr[i][j][1 - curMap].liveCount) {
                        arr[i][j][1 - curMap].state = 2;
                    } else {
                        arr[i][j][1 - curMap].state = 1;
                    }
                } else if (arr[i][j][curMap].state == 2) {
                    if (arr[i][j][curMap].actCount == arr[i][j][curMap].liveCount) {
                        for (int p = 0; p < 4; p++) {
                            int nextX = i + moving[p][0];
                            int nextY = j + moving[p][1];
                            if (arr[nextX][nextY][curMap].state == 0) {
                                if (arr[nextX][nextY][1 - curMap].state == 0) {
                                    arr[nextX][nextY][1 - curMap].state = 1;
                                    arr[nextX][nextY][1 - curMap].actCount = 0;
                                    arr[nextX][nextY][1 - curMap].liveCount = arr[i][j][curMap].liveCount;
                                } else if (arr[nextX][nextY][1 - curMap].state == 1) {
                                    if (arr[nextX][nextY][1 - curMap].liveCount < arr[i][j][curMap].liveCount) {
                                        arr[nextX][nextY][1 - curMap].liveCount = arr[i][j][curMap].liveCount;
                                    }
                                }
                            }
                        }
                    }
                    arr[i][j][1 - curMap].actCount = arr[i][j][curMap].actCount - 1;
                    if (arr[i][j][1 - curMap].actCount == 0) {
                        arr[i][j][1 - curMap].state = 3;
                    } else {
                        arr[i][j][1 - curMap].state = 2;
                    }
                }
            }
        }
        curMap = 1 - curMap;
        //print(curMap);
    }

    int totalCount = 0;
    for (int i = 0; i < n + k + 2; i++) {
        for (int j = 0; j < m + k + 2; j++) {
            if (arr[i][j][curMap].state == 1 || arr[i][j][curMap].state == 2)
                totalCount++;
        }
    }

    return totalCount;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m >> k;
        for(int j = 0; j < n + k + 2; j++) {
            for(int l = 0; l < m + k + 2; l++) {
                arr[j][l][0].state = 0;
                arr[j][l][1].state = 0;
            }
        }

        for(int j = k / 2 + 1; j < k / 2 + 1 + n; j++) {
            for(int l =  k / 2 + 1; l <  k / 2 + 1 + m; l++) {
                cin >> arr[j][l][0].liveCount;
                if(arr[j][l][0].liveCount > 0) {
                    arr[j][l][0].state = 1;
                    arr[j][l][0].actCount = 0;
                }
            }
        }

        cout << "#" << i + 1 << " " << solve() << endl;
    }

}