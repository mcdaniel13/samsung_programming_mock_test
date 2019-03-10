#include <iostream>
#include <vector>

using namespace std;

int moving[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };

void print(vector<vector<int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


vector<vector<int>>solve(int m) {
    vector<vector<int>> arr(m, vector<int>(m, -1));
    int x = 0;
    int y = 0;
    int data = 1;
    while (true) {
        bool isDone = true;
        for (int i = 0; i < 4; i++) {
            if (x + y != 0) {
                x += moving[i][0];
                y += moving[i][1];
            }
            while (x >= 0 && x < arr.size() && y >= 0 && y < arr.size() && arr[x][y] == -1) {
                isDone = false;
                arr[x][y] = data;
                data++;
                x += moving[i][0];
                y += moving[i][1];
            }
            x -= moving[i][0];
            y -= moving[i][1];
            //print(arr);
        }
        if (isDone)
            break;
    }


    return arr;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<vector<int>> arr = solve(m);
        cout << "#" << i + 1 << endl;
        for (int j = 0; j < arr.size(); j++) {
            for (int k = 0; k < arr[j].size(); k++) {
                cout << arr[j][k] << " ";
            }
            cout << endl;
        }
    }
}

