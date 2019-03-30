/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRQm6qfL0DFAUo
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int WMAX = 12;
const int HMAX = 15;

int N, W, H;

int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int minLeft;

int resetMap(vector<vector<int>> &map) {
    int left = 0;
    for(int j = 0; j < W; j++) {
        int curPosition = H - 1;
        for(int i = H - 1; i >= 0; i--) {
            if(map[i][j] != 0) {
                int curBlock = map[i][j];
                map[i][j] = 0;
                map[curPosition][j] = curBlock;
                curPosition--;
                left++;
            }
        }
    }
    return left;
}
void removeBlocks(vector<vector<int>> &map, int originX, int originY, int originBlock) {
    map[originX][originY] = 0;

    for(int i = 0; i < 4; i++) {
        int curX = originX;
        int curY = originY;
        for(int j = 0; j < originBlock - 1; j++) {
            curX = curX + moving[i][0];
            curY = curY + moving[i][1];
            if(curX >= 0 && curY >= 0 && curX < H && curY < W) {
                if(map[curX][curY] > 0) {
                    removeBlocks(map, curX, curY, map[curX][curY]);
                } else {
                    map[curX][curY] = 0;
                }
            } else
                break;
        }
    }
}

void solve(const vector<vector<int>> &prevMap, int curRound, int curLeft) {
    if(curRound == N) {
        minLeft = min(curLeft, minLeft);
        return;
    }

    for(int j = 0; j < W; j++) {
        vector<vector<int>> map = prevMap;
        int curX = 0;
        int curY = 0;
        int blockNum = 0;

        for(int i = 0; i < H; i++) {
            if(map[i][j] != 0) {
                curX = i;
                curY = j;
                blockNum = map[i][j];
                break;
            }
        }

        if(blockNum != 0)
            removeBlocks(map, curX, curY, blockNum);


        curLeft = resetMap(map);
        solve(map, curRound + 1, curLeft);
    }
}


int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++) {
        cin >> N >> W >> H;

        vector<vector<int>> map(HMAX,vector<int>(WMAX));

        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                cin >> map[i][j];
            }
        }

        minLeft = 12 * 15 + 1;
        solve(map, 0, 0);

        cout << "#" << k + 1 << " " << minLeft << endl;
    }
}