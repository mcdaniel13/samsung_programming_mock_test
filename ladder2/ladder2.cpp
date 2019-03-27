/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14BgD6AEECFAYh&categoryId=AV14BgD6AEECFAYh&categoryType=CODE&&&
 */

#include <iostream>

using namespace std;

const int LMAX = 100;

int ladderMap[LMAX][LMAX];
int endY[LMAX / 2];
int endCount;

int solve() {
    int minCount = 1000000;
    int minCountX = 0;
    int curX, curY;
    
    for(int k = 0; k < endCount; k++) {
        curX = LMAX - 1;
        curY = endY[k];
        int totalCount = 0;
        int movingY = 0;
        bool isFound = false;
        bool cannotFound = false;
        while (true) {
            if (isFound) {
                if(minCount == totalCount) {
                    if(minCountX < curY) {
                        minCountX = curY;
                    }
                }else if(minCount > totalCount) {
                    minCount = totalCount;
                    minCountX = curY;
                }
                break;
            }
            
            if (cannotFound)
                break;
            
            while (true) {
                if (curY - 1 >= 0 && ladderMap[curX][curY - 1] == 1) {
                    curY = curY - 1;
                    movingY = -1;
                    totalCount++;
                    //                    cout << "<- (x, y) = (" << curX << ", " << curY << ") " << endl;
                    break;
                } else if (curY + 1 < LMAX && ladderMap[curX][curY + 1] == 1) {
                    curY = curY + 1;
                    movingY = 1;
                    totalCount++;
                    //                    cout << "-> (x, y) = (" << curX << ", " << curY << ") " << endl;
                    break;
                } else if (curX >= 0 && curX < LMAX) {
                    if (curX == 0) {
                        isFound = true;
                        break;
                    }
                    curX = curX - 1;
                    totalCount++;
                } else {
                    cannotFound = true;
                    //cout << "no route" << endl;
                    break;
                }
            }
            
            while (true) {
                if (isFound)
                    break;
                
                if (curX - 1 >= 0 && ladderMap[curX - 1][curY] == 1) {
                    curX = curX - 1;
                    totalCount++;
                    //                    cout << "^ (x, y) = (" << curX << ", " << curY << ") " << endl;
                    break;
                } else if (curY >= 0 && curY < LMAX) {
                    curY = curY + movingY;
                    totalCount++;
                } else {
                    cannotFound = true;
                    //cout << "no route" << endl;
                    break;
                }
            }
        }
    }
    
    return minCountX;
}

int main() {
    for(int i = 0; i < 10; i++) {
        int t;
        cin >> t;
        for(int i = 0; i < LMAX; i++) {
            for(int j = 0; j < LMAX; j++) {
                cin >> ladderMap[i][j];
            }
        }
        
        endCount =  0;
        for(int i = 0; i < LMAX; i++) {
            if(ladderMap[LMAX - 1][i] == 1) {
                endY[endCount] = i;
                endCount++;
            }
        }
        
        cout << "#" << t << " " << solve() << endl;
        
    }
}
