/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB
 */

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int arr[4][4];
int direction[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
bool visited[10000000];
int maxCount;


void recursive(int x, int y, int count, int madeNum) {
    if(count <= 7) {
        if(count - 1 <= 2) {}
        int temp = pow(10,(count - 1)) * arr[x][y];
        madeNum += temp;
    }
    
    if(count == 7) {
        if(!visited[madeNum]) {
            //            cout << "madeNum = " << madeNum << endl;
            visited[madeNum] = true;
            maxCount++;
        }
        return;
    }
    
    
    for(int i = 0; i < 4; i++) {
        int newX = x + direction[i][0];
        int newY = y + direction[i][1];
        if(newX >= 0 && newX < 4 && newY >= 0 && newY < 4) {
            //            cout << "[D" << i + 1 << "] (" << x << ", " << y << ") -> (" << newX << ", " << newY << ") ";
            //            cout << "count = " << count + 1 << " madeNum = " << madeNum << " maxCount = " << maxCount << endl;
            recursive(newX, newY, count + 1, madeNum);
        }
    }
}

void solve() {
    for(int j = 0; j < 4; j++) {
        for(int k = 0; k < 4; k ++) {
            recursive(k, j, 1, 0);
        }
    }
    //    recursive(0, 0, 1, 0);
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            for(int k = 0; k < 4; k ++) {
                cin >> arr[j][k];
            }
        }
        
        for(int i = 0; i < 10000000; i++)
            visited[i] = false;
        
        maxCount = 0;
        solve();
        cout << "#" << i + 1 << " " << maxCount << endl;
    }
}
