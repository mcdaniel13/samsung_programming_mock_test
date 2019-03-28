#include <iostream>

using namespace std;


const int NMAX = 10;
const int MMAX = 101;
const int AMAX = 9;

int m, a;

int moving[5][2] = {{0, 0}, {0, -1}, {1, 0}, {0, 1}, {-1, 0}};
int arr[NMAX][NMAX][2];
int isOccupied[AMAX];
int charger[AMAX];
int userA[MMAX];
int userB[MMAX];

int chargerX;
int chargerY;
int chargerRange;

int aTotalCount;
int bTotalCount;
void print() {
    cout << " ==== first ==== " << endl;
    for(int i = 0; i < NMAX; i++) {
        for(int j = 0; j < NMAX; j++) {
            cout << arr[i][j][0] << " ";
        }
        cout << endl;
    }
    cout << " ==== second ==== " << endl;
    for(int i = 0; i < NMAX; i++) {
        for(int j = 0; j < NMAX; j++) {
            cout << arr[i][j][1] << " ";
        }
        cout << endl;
    }
}

int solve() {
    aTotalCount = 0;
    bTotalCount = 0;

    int aCurX = 0;  // inner
    int aCurY = 0;  // outer
    int bCurX = 9;  // inner
    int bCurY = 9;  // outer

    int aCurCount;
    int bCurCount;

    for(int i = 0; i <= m; i++) {
        cout << " ===== round " << i << " ===== " << endl;
        aCurX += moving[userA[i]][0];
        aCurY += moving[userA[i]][1];
        bCurX += moving[userB[i]][0];
        bCurY += moving[userB[i]][1];

        cout << "[A] (" << aCurX << ", " << aCurY << ")" << endl;
        cout << "[B] (" << bCurX << ", " << bCurY << ")" << endl;

        if(arr[aCurY][aCurX][0] != 0) {
            isOccupied[arr[aCurY][aCurX][0]] = true;
        }
        aCurCount = charger[arr[aCurY][aCurX][0]];

        if(isOccupied[arr[bCurY][bCurX][0]]) {
            if(arr[bCurY][bCurX][1] == 0) {
                aCurCount = charger[arr[aCurY][aCurX][1]];
                bCurCount = charger[arr[bCurY][bCurX][0]];
            } else {
                bCurCount = charger[arr[bCurY][bCurX][1]];
            }
        } else {
            bCurCount = charger[arr[bCurY][bCurX][0]];
        }

        cout << "[A] charger = " << aCurCount << endl;
        cout << "[B] charger = " << bCurCount << endl;

        aTotalCount += aCurCount;
        bTotalCount += bCurCount;

        isOccupied[arr[aCurY][aCurX][0]] = false;
    }

    return aTotalCount + bTotalCount;
}

void setRange(int start, int end, int curY, int chargerNum) {
    if(start > end || curY < 0 || curY >= NMAX)
        return;

    for(int i = start; i <= end; i++) {
        if(i >= 0 && i < NMAX) {
            if(charger[arr[curY][i][0]] < charger[chargerNum]) {
                arr[curY][i][1] = arr[curY][i][0];
                arr[curY][i][0] = chargerNum;
            } else if (charger[arr[curY][i][1]] < charger[chargerNum]) {
                arr[curY][i][1] = chargerNum;
            }
        }
    }

    if(curY >= chargerY - 1) {
        setRange(start + 1, end - 1, curY + 1, chargerNum);
    }

    if(curY <= chargerY - 1) {
        setRange(start + 1, end - 1, curY - 1, chargerNum);
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < NMAX; j++) {
            for(int k = 0; k < NMAX; k++) {
                arr[j][k][0] = 0;
                arr[j][k][1] = 0;
            }
        }

        cin >> m >> a;

        userA[0] = 0;
        for(int j = 1; j <= m; j++) {
            cin >> userA[j];
        }

        userB[0] = 0;
        for(int j = 1; j <= m; j++) {
            cin >> userB[j];
        }

        isOccupied[0] = false;
        charger[0] = 0;
        for(int j = 1; j <= a; j++) {
            cin >> chargerX >> chargerY >> chargerRange >> charger[j];
            setRange(chargerX - 1 - chargerRange, chargerX - 1 + chargerRange, chargerY - 1, j);
            isOccupied[j] = false;
            //print();
        }

        cout << "#" << i + 1 << " " << solve() << endl;
    }
}