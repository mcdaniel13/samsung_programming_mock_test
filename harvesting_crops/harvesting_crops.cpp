/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GLXqKAWYDFAXB&categoryId=AV7GLXqKAWYDFAXB&categoryType=CODE
 */

#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE = 50;

int cropField[MAXSIZE][MAXSIZE];
int n;
int totalCount;

void solve(int startingLine, int curScanningLine, int start, int end) {
    if(curScanningLine < 0 || curScanningLine >= n)
        return;

    for(int i = start; i <= end; i++) {
        totalCount += cropField[curScanningLine][i];
    }

    if(curScanningLine <= startingLine) {
        solve(startingLine, curScanningLine - 1, start + 1, end - 1);
    }

    if(curScanningLine >= startingLine) {
        solve(startingLine, curScanningLine + 1, start + 1, end - 1);
    }
}


int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            string tempString;
            cin >> tempString;
            for(int k = 0; k < n; k++) {
                cropField[j][k] = tempString[k] - '0';
            }
        }

        totalCount = 0;
        int curScanningLine = n / 2;
        solve(curScanningLine, curScanningLine, 0, n - 1);

        cout << "#" << i + 1 << " " << totalCount << endl;
    }
}