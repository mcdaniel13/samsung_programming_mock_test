/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5V1SYKAaUDFAWu
 */

#include <iostream>

using namespace std;

const int DMAX = 13;
const int WMAX = 20;

int t;
int d;
int w;
int k;

int arr[DMAX][WMAX];
int chemType[DMAX];
int minChemUse;


void findMinChemUse(int curRow, int curChemUse, int prevCount[DMAX], int maxPrevCount[DMAX]) {
    if(curChemUse >= minChemUse)
        return;
    
    if(curRow == d) {
        for(int i = 0; i < w; i++) {
            if(maxPrevCount[i] < k) {
                return;
            }
        }
        
        if(minChemUse > curChemUse)
            minChemUse =  curChemUse;
        return;
    }
    
    
    int curCount[WMAX];
    int maxCurCount[WMAX];
    
    for(int i = -1; i < 2; i++) {
        chemType[curRow] = i;
        for(int curCol = 0; curCol < w; curCol++) {
            int prevNum;
            int curNum;
            
            if(chemType[curRow - 1] == -1)
                prevNum = arr[curRow - 1][curCol];
            else
                prevNum = chemType[curRow - 1];
            
            if(chemType[curRow] == -1)
                curNum = arr[curRow][curCol];
            else
                curNum = chemType[curRow];
            
            if(prevNum == curNum)
                curCount[curCol] = prevCount[curCol] + 1;
            else
                curCount[curCol] = 1;
            
            if(maxPrevCount[curCol] < curCount[curCol])
                maxCurCount[curCol] = curCount[curCol];
            else
                maxCurCount[curCol] = maxPrevCount[curCol];
        }
        
        if(chemType[curRow] == -1) {
            findMinChemUse(curRow + 1, curChemUse, curCount, maxCurCount);
        } else {
            findMinChemUse(curRow + 1, curChemUse + 1, curCount, maxCurCount);
        }
    }
    
    
    
}

void solve() {
    minChemUse = DMAX;
    
    int curCount[WMAX];
    int maxCurCount[WMAX];
    
    for(int i = 0; i < WMAX; i++) {
        curCount[i] = 1;
        maxCurCount[i] = 1;
    }
    
    chemType[0] = -1;
    findMinChemUse(1, 0, curCount, maxCurCount);
    
    chemType[0] = 0;
    findMinChemUse(1, 1, curCount, maxCurCount);
    
    chemType[0] = 1;
    findMinChemUse(1, 1, curCount, maxCurCount);
}

int main() {
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> d >> w >> k;
        for(int x = 0; x < d; x++) {
            for(int y = 0; y < w; y++) {
                cin >> arr[x][y];
            }
        }
        
        solve();
        
        cout << "#" << i + 1 << " " << minChemUse << endl;
    }
}
