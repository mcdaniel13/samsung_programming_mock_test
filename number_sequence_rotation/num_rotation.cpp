/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5Pq-OKAVYDFAUq&categoryId=AV5Pq-OKAVYDFAUq&categoryType=CODE
 */

#include <iostream>

using namespace std;

const int NMAX = 7;

int nums[NMAX][NMAX];
string printed[NMAX][NMAX];
int n;

void print(string printed[NMAX][NMAX]) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n ; j++) {
            cout << printed[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    // 90 degree rotation
    for(int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(nums[n - j - 1][i] + '0');
        }
        printed[i][0] = temp;
    }
    
    //print(printed);
    
    // 180 degree rotation
    for(int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(nums[n - 1- i][n - j - 1] + '0');
        }
        printed[i][1] = temp;
    }
    
    //print(printed);
    
    // 270 degree rotation
    for(int i = 0; i < n; i++) {
        string temp;
        for (int j = 0; j < n; j++) {
            temp.push_back(nums[j][n - i - 1] + '0');
        }
        printed[i][2] = temp;
    }
    
    //print(printed);
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                cin >> nums[j][k];
            }
        }
        
        solve();
        cout << "#" << i + 1 << endl;
        print(printed);
    }
}
