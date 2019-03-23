/*
 *  https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GKs06AU0DFAXB&categoryId=AV7GKs06AU0DFAXB&categoryType=CODE
 */

#include <iostream>
#include <algorithm>

using namespace std;

int col[10];
int totalCount;

bool isPromising(int row) {
    for(int i = 0; i < row; i++) {
        if(col[i] == col[row] || abs(i - row) == abs(col[i] - col[row]))
            return false;
    }

    return true;
}

void solve(int n, int row) {
    if(row == n) {
        totalCount++;
        return;
    }

    for(int i = 0; i < n; i++) {
        col[row] = i;
        if(isPromising(row))
            solve(n, row + 1);
    }
}

int main() {
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int n;
        cin >> n;

        for(int j = 0; j < 10; j++) {
            col[j] = -1;
        }

        totalCount = 0;

        solve(n, 0);

        cout << "#" << i + 1 << " " << totalCount << endl;
    }

}