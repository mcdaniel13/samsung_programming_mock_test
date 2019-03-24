/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV597vbqAH0DFAVl
 */

#include <iostream>

using namespace std;

const int maxN = 100;
const int maxK = 1000;

int cellMap[maxN][maxN];
int cellMapLocation[maxN][maxN];
int mLocation[maxK][2];
int mCount[maxK];
int mDirection[maxK];

int n;
int m;
int k;
int totalCount;

void solve(int curK, int curM) {
    if(curM == 0) {
        totalCount = 0;
        for(int i = 0; i < curK; i++) {
            totalCount += mCount[i];
        }
        return;
    }

    for(int j = 0; j < n; j++) {
        for(int l = 0; l < n; l++) {
            cellMap[j][l] = 0;
        }
    }

    int newK = 0;
    for(int i = 0; i < curK; i++) {
        bool isNewK = true;
        int newX, newY, newCount, newDirection;
        if(mDirection[i] == 1) {
            newX = mLocation[i][0] - 1;
            newY = mLocation[i][1];
        } else if (mDirection[i] == 2) {
            newX = mLocation[i][0] + 1;
            newY = mLocation[i][1];
        } else if(mDirection[i] == 3) {
            newX = mLocation[i][0];
            newY = mLocation[i][1] - 1;
        } else {
            newX = mLocation[i][0];
            newY = mLocation[i][1] + 1;
        }

        if(newX == 0 || newX == n - 1 || newY == 0 || newY == n - 1) {
            newCount = mCount[i] / 2;
            if(mDirection[i] == 1)
                newDirection = 2;
            else if (mDirection[i] == 2)
                newDirection = 1;
            else if(mDirection[i] == 3)
                newDirection = 4;
            else
                newDirection = 3;
        } else {
            if(cellMap[newX][newY] == 0) {
                cellMap[newX][newY] = mCount[i];
                cellMapLocation[newX][newY] = newK;
                newCount = mCount[i];
                newDirection = mDirection[i];
            } else {
                isNewK = false;
                if(cellMap[newX][newY] < mCount[i]) {
                    cellMap[newX][newY] = mCount[i];
                    mCount[cellMapLocation[newX][newY]] += mCount[i];
                    mDirection[cellMapLocation[newX][newY]] = mDirection[i];
                } else {
                    mCount[cellMapLocation[newX][newY]] += mCount[i];
                }
            }
        }

        if(isNewK) {
            mLocation[newK][0] = newX;
            mLocation[newK][1] = newY;
            mCount[newK] = newCount;
            mDirection[newK] = newDirection;
            newK++;
        }
    }



    solve(newK, curM - 1);
}


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m >> k;
        for(int j = 0; j < k; j++) {
            cin >> mLocation[j][0] >> mLocation[j][1] >> mCount[j] >> mDirection[j];
        }

        solve(k, m);

        cout << "#" << i + 1 << " " << totalCount << endl;
    }
}