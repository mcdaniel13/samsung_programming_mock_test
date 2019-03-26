/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeV9sKkcoDFAVH
 */

#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int rotate[20][2];
int magnet[4][8];
int magnetRotate[4];
bool visited[4];
int startPoint[4];


int n;
int totalPoint;

void updateMagnetStartPoint() {
    for(int i = 0; i < 4; i++) {
        if(magnetRotate[i] == 1) {
            startPoint[i] = (startPoint[i] + 7) % 8;
        } else if (magnetRotate[i] == -1) {
            startPoint[i] = (startPoint[i] + 1) % 8;
        }
    }
}

void solve() {
    totalPoint = 0;

    for(int i = 0; i < 4; i++) {
        startPoint[i] = 0;
    }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            magnetRotate[j] = 0;
            visited[j] = false;
        }

        int start = rotate[i][0] - 1;
        magnetRotate[start] = rotate[i][1];

        queue<int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()) {
            int curMagnet = q.front();
            q.pop();

            int nextMagnet = curMagnet + 1;
            if(nextMagnet >= 0 && nextMagnet < 4) {
                if (!visited[nextMagnet]) {
                    int curMagnetPosition = (startPoint[curMagnet] + 2) % 8;
                    int nextMagnetPosition = (startPoint[nextMagnet] + 6) % 8;
                    if ((magnet[curMagnet][curMagnetPosition] == 1 && magnet[nextMagnet][nextMagnetPosition] == 0) ||
                        (magnet[curMagnet][curMagnetPosition] == 0 && magnet[nextMagnet][nextMagnetPosition] == 1)) {
                        magnetRotate[nextMagnet] = -magnetRotate[curMagnet];
                        q.push(nextMagnet);
                    }
                    visited[nextMagnet] = true;
                }
            }

            nextMagnet = curMagnet - 1;
            if(nextMagnet >= 0 && nextMagnet < 4) {
                if (!visited[nextMagnet]) {
                    int curMagnetPosition = (startPoint[curMagnet] + 6) % 8;
                    int nextMagnetPosition = (startPoint[nextMagnet] + 2) % 8;
                    if ((magnet[curMagnet][curMagnetPosition] == 1 && magnet[nextMagnet][nextMagnetPosition] == 0) ||
                        (magnet[curMagnet][curMagnetPosition] == 0 && magnet[nextMagnet][nextMagnetPosition] == 1)) {
                        magnetRotate[nextMagnet] = -magnetRotate[curMagnet];
                        q.push(nextMagnet);
                    }
                    visited[nextMagnet] = true;
                }
            }
        }

        updateMagnetStartPoint();
    }
    for(int i = 0; i < 4; i++) {
        int curPoint = magnet[i][startPoint[i]] * pow(2, i);
        totalPoint += curPoint;
    }
}

int main() {
    int t;
    cin >> t;
    for(int k = 0 ; k < t; k++) {
        cin >> n;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 8; j++) {
                cin >> magnet[i][j];
            }
        }

        for(int i = 0; i < n; i++) {
            cin >> rotate[i][0] >> rotate[i][1];
        }

        solve();

        cout << "#" << k + 1 << " " << totalPoint << endl;
    }
}