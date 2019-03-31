/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV4suNtaXFEDFAUf
 */

#include <iostream>
#include <vector>

using namespace std;

const int NMAX = 12;

int moving[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int processor[NMAX][2]; // 0 = row  1 = col
int arr[NMAX][NMAX];

int N, P;
int maxCount;
int totalWireCount;

void print() {
    cout << "====" << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool isLineDrawable(int index, int curX, int curY) {
    while(curX >= 0 && curX < N && curY >= 0 && curY < N) {
        if(arr[curX][curY] == 0) {
            curX += moving[index][0];
            curY += moving[index][1];
        } else {
            return false;
        }
    }
    return true;
}

int drawLine(int index, int curX, int curY) {
    int length = 0;
    while(curX >= 0 && curX < N && curY >= 0 && curY < N) {
        arr[curX][curY] = 2;
        length++;
        curX += moving[index][0];
        curY += moving[index][1];
    }
    return length;
}

void removeLine(int index, int curX, int curY) {
    while(curX >= 0 && curX < N && curY >= 0 && curY < N) {
        arr[curX][curY] = 0;
        curX += moving[index][0];
        curY += moving[index][1];
    }
}

void solve(int curP, int curLine, int totalP) {
    if(curP == P) {
        if(maxCount < totalP) {
            maxCount = totalP;
            totalWireCount = curLine;
        } else if(maxCount == totalP) {
            if(totalWireCount > curLine) {
                totalWireCount = curLine;
            }
        }
        return;
    }

    for(int i = 0 ; i < 4; i++) {
        int curX = processor[curP][0];
        int curY = processor[curP][1];

        if(isLineDrawable(i, curX + moving[i][0], curY + moving[i][1])) {
            int curLength = drawLine(i, curX + moving[i][0], curY + moving[i][1]);
//            cout << "drawLine at CurP = " << curP << endl;
//            print();
            solve(curP + 1, curLine + curLength, totalP + 1);
            removeLine(i, curX + moving[i][0], curY + moving[i][1]);
//            cout << "removeLine at CurP = " << curP << endl;
//            print();
        }
    }
    solve(curP + 1, curLine, totalP);
}

int main() {
    int t;
    cin >> t;
    for(int k = 0; k < t; k++) {
        cin >> N;
        P = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> arr[i][j];
                if(arr[i][j] == 1 && (i > 0 && j > 0 && i < N - 1 && j < N - 1)) {
                    processor[P][0] = i;
                    processor[P][1] = j;
                    P++;
                }
            }
        }

//        for(int i = 0 ; i < P; i++) {
//            cout << "(" << processor[i][0] << ", " << processor[i][1] << ")" << endl;
//        }

        maxCount = 0;
        totalWireCount = 0;
        solve(0, 0, 0);

        cout << "#" << k + 1 << " " << totalWireCount << endl;
    }
}