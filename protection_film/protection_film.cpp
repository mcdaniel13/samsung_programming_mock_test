## https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu

#include <iostream>
using namespace std;

int arr[13][20];
int chemical[20];
int k;
int row;
int col;
int minNumOfChem;

void recursive(int curRow, int numOfChem, int prevCount[20], int prevMaxCount[20]) {
    if(numOfChem >= minNumOfChem)
        return;

    if(curRow == row) {
        bool isSatisfied = true;
        for(int i = 0; i < col; i++)
            if(prevMaxCount[i] < k) {
                isSatisfied = false;
                break;
            }

        if(isSatisfied && numOfChem < minNumOfChem)
            minNumOfChem = numOfChem;

        return;
    }

    int curCount[20];
    int curMaxCount[20];

    for(int i = 2; i >= 0; i--) {
        chemical[curRow] = i;
        for(int j = 0; j < col; j++) {
            int curType;
            int prevType;
            if(chemical[curRow] == 2)
                curType = arr[curRow][j];
            else
                curType = chemical[curRow];

            if(chemical[curRow - 1] == 2)
                prevType = arr[curRow - 1][j];
            else
                prevType = chemical[curRow - 1];

            if(curType == prevType)
                curCount[j] = prevCount[j] + 1;
            else
                curCount[j] = 1;


            if(curCount[j] > prevMaxCount[j])
                curMaxCount[j] = curCount[j];
            else
                curMaxCount[j] = prevMaxCount[j];
        }

        if(chemical[curRow] == 2)
            recursive(curRow + 1, numOfChem,  curCount, curMaxCount);
        else
            recursive(curRow + 1, numOfChem + 1, curCount, curMaxCount);
    }
}

void solve() {
    int curCount[20];
    int curMaxCount[20];

    for(int i = 0; i < col; i++) {
        curCount[i] = 1;
        curMaxCount[i] = 1;
    }

    chemical[0] = 2;
    recursive(1, 0, curCount, curMaxCount);

    chemical[0] = 1;
    recursive(1, 1, curCount, curMaxCount);

    chemical[0] = 0;
    recursive(1, 1, curCount, curMaxCount);
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> row >> col >> k;

        for(int j = 0; j < row; j++) {
            for(int k = 0; k < col; k++) {
                cin >> arr[j][k];

            }
        }
        minNumOfChem = 13;

        solve();

        cout << "#" << i + 1 << " " << minNumOfChem << endl;
    }
}