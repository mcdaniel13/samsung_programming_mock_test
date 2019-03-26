/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV14ABYKADACFAYh&categoryId=AV14ABYKADACFAYh&categoryType=CODE
 */

#include <iostream>

using namespace std;

const int LMAX = 100;

int ladderMap[LMAX][LMAX];
int exitPoint[2];

int solve() {
    int curX = exitPoint[0];
    int curY = exitPoint[1];

    int movingY = 0;
    bool isFound = false;
    bool cannotFound = false;
    while(true) {
        if(isFound)
            break;

        if(cannotFound)
            break;

        while(true) {
            if(curY - 1 >= 0 && ladderMap[curX][curY - 1] == 1) {
                curY = curY - 1;
                movingY = -1;
                //cout << "<- (x, y) = (" << curX << ", " << curY << ") " << endl;
                break;
            } else if(curY + 1 < LMAX && ladderMap[curX][curY + 1] == 1) {
                curY = curY + 1;
                movingY = 1;
                //cout << "-> (x, y) = (" << curX << ", " << curY << ") " << endl;
                break;
            } else if (curX >= 0 && curX < LMAX){
                if(curX == 0) {
                    isFound = true;
                    break;
                }
                curX = curX - 1;
            } else {
                cannotFound = true;
                //cout << "no route" << endl;
                break;
            }
        }

        while(true) {
            if(isFound)
                break;

            if(curX - 1 >= 0 && ladderMap[curX - 1][curY] == 1) {
                curX = curX - 1;
                //cout << "^ (x, y) = (" << curX << ", " << curY << ") " << endl;
                break;
            } else if (curY >= 0 && curY < LMAX){
                curY = curY + movingY;
            } else {
                cannotFound = true;
                //cout << "no route" << endl;
                break;
            }
        }
    }

    return curY;
}

int main() {
    for(int i = 0 ; i < 10; i++) {
        int t;
        cin >> t;

        for(int j = 0; j < LMAX; j++) {
            for(int k = 0; k < LMAX; k++) {
                cin >> ladderMap[j][k];
                if(ladderMap[j][k] == 2) {
                    exitPoint[0] = j;
                    exitPoint[1] = k;
                }
            }
        }

        int X = solve();

        cout << "#" << t << " " << X << endl;
    }

}