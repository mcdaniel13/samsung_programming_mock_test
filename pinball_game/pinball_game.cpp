/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRF8s6ezEDFAUo
 */
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int NMAX = 100;

int moving[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};   // up, down, left, right

int gameMap[NMAX][NMAX];
int wormhole[5][2][2];

int n;
int maxPoint;

struct Pinball {
    int x;
    int y;
    int dir;
    int point;
    Pinball(int inX, int inY, int inDir, int inPoint) {
        x = inX;
        y = inY;
        dir = inDir;
        point = inPoint;
    }
};

int determineDirAtBlk(int curDir, int curType) {
    int newDir;
    if(curDir == 0) {
        if(curType == 1 || curType == 4 || curType == 5) {
            newDir = 1;
        } else if (curType == 2) {
            newDir = 3;
        } else {    // curType = 3
            newDir = 2;
        }
    } else if(curDir == 1) {
        if(curType == 2 || curType == 3 || curType == 5) {
            newDir = 0;
        } else if (curType == 1) {
            newDir = 3;
        } else {    // curType == 4
            newDir = 2;
        }
    } else if(curDir == 2) {
        if(curType == 3 || curType == 4 || curType == 5) {
            newDir = 3;
        } else if (curType == 1) {
            newDir = 0;
        } else {    // curType == 2
            newDir = 1;
        }
    } else {    // curDir == 3
        if(curType == 1 || curType == 2 || curType == 5) {
            newDir = 2;
        } else if (curType == 3) {
            newDir = 1;
        } else {    // curType == 4
            newDir = 0;
        }
    }

    return newDir;
}

void findMaximumPoint(int startX, int startY) {
    for(int i = 0; i < 4; i++) {
        int curX = startX;
        int curY = startY;
        int curDir = i;
        int curPoint = 0;

        queue<Pinball> q;  // x, y, direction, point
        Pinball startPin(curX, curY, curDir, curPoint);

        q.push(startPin);

//        cout << "======== Direction #" << i + 1 << " =========" << endl;
//        cout << "start = (" << curX << ", " << curY << ")" << endl;
        while(!q.empty()) {
            Pinball cur = q.front();
            q.pop();
            curDir = cur.dir;
            curPoint = cur.point;
            curX = cur.x + moving[curDir][0];
            curY = cur.y + moving[curDir][1];
//            cout << "(" << curX << ", " << curY << ") Direction = " << curDir << " -> " << endl;
            if(curX == startX && curY == startY) {      // game end
                maxPoint = max(maxPoint, curPoint);
//                cout << "[STARTPOINT] curPoint = " << curPoint << " max = " << maxPoint << endl;
            } else {
                int curType = gameMap[curX][curY];
                if (curX >= 0 && curX < n && curY >= 0 && curY < n) {
                    if (curType < 0) {        //blackhole
//                        cout << "[BLACKHOLE] curPoint = " << curPoint << " max = " << maxPoint << endl;
                        maxPoint = max(maxPoint, curPoint);
                    } else if (curType <= 5 && curType > 0) {      // block
                        curDir = determineDirAtBlk(curDir, curType);
//                        cout << "[BLOCK] type #" << curType <<" : newDirection = " << curDir << endl;
                        Pinball nextPin(curX, curY, curDir, curPoint + 1);
                        q.push(nextPin);
                    } else if (curType <= 10 && curType > 5) {     // wormhole
                        int wormholeNumber = curType - 6;
                        if(wormhole[wormholeNumber][0][0] == curX && wormhole[wormholeNumber][0][1] == curY) {
                            curX = wormhole[wormholeNumber][1][0];
                            curY = wormhole[wormholeNumber][1][1];
                        } else {
                            curX = wormhole[wormholeNumber][0][0];
                            curY = wormhole[wormholeNumber][0][1];
                        }
//                        cout << "[WORMHOLE] type #" << curType <<" : newLocation = (" << curX << ", " << curY << ") " << endl;
                        Pinball nextPin(curX, curY, curDir, curPoint);
                        q.push(nextPin);
                    }  else {     // nothing
//                        cout << "[NOTHING]" << endl;
                        Pinball nextPin(curX, curY, curDir, curPoint);
                        q.push(nextPin);
                    }
                } else {
                    if (curDir == 0) {
                        curDir = 1;
                    } else if (curDir == 1) {
                        curDir = 0;
                    } else if (curDir == 2) {
                        curDir = 3;
                    } else {
                        curDir = 2;
                    }
//                    cout << "[OUT OF BOUNDS] newDirection = " << curDir << endl;
                    Pinball nextPin(curX, curY, curDir, curPoint + 1);
                    q.push(nextPin);
                }
            }
        }

    }
}

void solve() {
    maxPoint = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(gameMap[i][j] == 0)
                findMaximumPoint(i, j);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;

        int wormholeCount[5] = {0, 0, 0, 0, 0};
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> gameMap[j][k];
                if(gameMap[j][k] > 5) {
                    int number = gameMap[j][k] - 6;
                    wormhole[number][wormholeCount[number]][0] = j;
                    wormhole[number][wormholeCount[number]][1] = k;
                    wormholeCount[number] += 1;
                }
            }
        }

        solve();

        cout << "#" << i + 1 << " " << maxPoint << endl;
    }
}