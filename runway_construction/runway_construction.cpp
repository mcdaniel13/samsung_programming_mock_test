/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWIeW7FakkUDFAVH
 */

#include <iostream>

using namespace std;

const int NMAX = 20;

int arr[NMAX][NMAX];
int n, k;
int totalCount;

void solve() {
    totalCount = 0;
    
    // 가로
    for(int i = 0; i < n; i++) {
        int curHeight = arr[i][0];
        int curCount = 1;
        bool isAvailable = true;
        for(int j = 1; j < n; j++) {
            if (arr[i][j] == curHeight) {
                curCount++;
            } else if (arr[i][j] == curHeight + 1) {
                if (curCount >= k) {
                    curHeight = arr[i][j];
                    curCount = 1;
                } else {
                    isAvailable = false;
                    break;
                }
            } else if (arr[i][j] == curHeight - 1) {
                curHeight = arr[i][j];
                curCount = 1;
                bool isInnerAvailable = false;
                for(int temp_j = j + 1; temp_j < n; temp_j++) {
                    if(arr[i][temp_j] == curHeight) {
                        curCount++;
                    } else {
                        break;
                    }
                    
                    if(curCount == k) {
                        isInnerAvailable = true;
                        j = temp_j;
                        curCount = 0;
                        break;
                    }
                }
                if(!isInnerAvailable) {
                    isAvailable = false;
                    break;
                }
            } else {
                isAvailable = false;
                break;
            }
        }
        if(isAvailable) {
            //cout << "row #" << i + 1 << " is available" << endl;
            totalCount++;
        }
    }
    
    //세로
    for(int j = 0; j < n; j++) {
        int curHeight = arr[0][j];
        int curCount = 1;
        bool isAvailable = true;
        for(int i = 1; i < n; i++) {
            if (arr[i][j] == curHeight) {
                curCount++;
            } else if (arr[i][j] == curHeight + 1) {
                if (curCount >= k) {
                    curHeight = arr[i][j];
                    curCount = 1;
                } else {
                    isAvailable = false;
                    break;
                }
            } else if (arr[i][j] == curHeight - 1) {
                curHeight = arr[i][j];
                curCount = 1;
                bool isInnerAvailable = false;
                for(int temp_i = i + 1; temp_i < n; temp_i++) {
                    if(arr[temp_i][j] == curHeight) {
                        curCount++;
                    } else {
                        break;
                    }
                    
                    if(curCount == k) {
                        isInnerAvailable = true;
                        i = temp_i;
                        curCount = 0;
                        break;
                    }
                }
                if(!isInnerAvailable) {
                    isAvailable = false;
                    break;
                }
            } else {
                isAvailable = false;
                break;
            }
        }
        if(isAvailable) {
            //cout << "col #" << j + 1 << " is available" << endl;
            totalCount++;
        }
    }
}


int main() {
    int t;
    cin >> t;
    for(int l = 0; l < t; l++) {
        cin >> n >> k;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        
        solve();
        
        cout << "#" << l + 1 << " " << totalCount << endl;
    }
}
