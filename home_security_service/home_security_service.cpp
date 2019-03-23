/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V61LqAf8DFAWu
 */

#include <iostream>
#include <algorithm>

using namespace std;

int operatingPrice[21];
int maxLineSize[21];

int houseMap[20][20];
int n;
int m;

int earningPrice;
int houseCount;
int maxHouseCount;

void findEarningPrice(int curRow, int midRow, int start, int end, int count, int k) {
    if(curRow < 0 || curRow >= n)
        return;

    for(int i = start; i <= end; i++) {
        if(i >= 0 && i < n) {
            if(houseMap[curRow][i]) {
                houseCount++;
                earningPrice += m;
            }
        }
    }

    if(curRow <= midRow && count < k) {
        findEarningPrice(curRow - 1, midRow, start + 1, end - 1, count + 1, k);
    }

    if(curRow >= midRow && count < k) {
        findEarningPrice(curRow + 1, midRow, start + 1, end - 1, count + 1, k);
    }
}

void solve() {
    maxHouseCount = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j< n; j++) {
            for(int k = 0; k < n + 1; k++) {
                earningPrice = -operatingPrice[k];
                houseCount = 0;
                findEarningPrice(i, i, j - maxLineSize[k] / 2, j + maxLineSize[k] / 2, 0, k);
                if(earningPrice >= 0) {
                    maxHouseCount = max(houseCount, maxHouseCount);
                }
            }
        }
    }
}


int main() {
    operatingPrice[0] = 1;
    maxLineSize[0] = 1;

    for(int i = 1; i < 21; i++) {
        operatingPrice[i] = operatingPrice[i - 1] + 4 * i;
        maxLineSize[i] += maxLineSize[i - 1] + 2;
    }

    int t;
    cin >> t;
    for(int k = 0; k < t; k++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> houseMap[i][j];
            }
        }

        solve();

        cout << "#" << k + 1 << " " << maxHouseCount << endl;
    }
}