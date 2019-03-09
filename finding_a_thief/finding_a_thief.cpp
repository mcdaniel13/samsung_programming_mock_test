// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> map;
int retCount;
void print(vector<vector<int>> val) {
    for (int i = 0; i < val.size(); ++i) {
        for (int j = 0; j < val[0].size(); ++j) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

bool isConnected(int direction, int nextType) {
    if (nextType == 0)
        return false;

    if (direction == 0) {
        if (nextType == 1 || nextType == 2 || nextType == 4 || nextType == 7)
            return true;
    } else if (direction == 1) {
        if (nextType == 1 || nextType == 2 || nextType == 5 || nextType == 6)
            return true;
    } else if (direction == 2) {
        if (nextType == 1 || nextType == 3 || nextType == 6 || nextType == 7)
            return true;
    }
    else if (direction == 3) {
        if (nextType == 1 || nextType == 3 || nextType == 4 || nextType == 5)
            return true;
    }

    return false;
}


void dfs(int x, int y, int t, int curTime, vector<vector<bool>> &isVisited) {
    retCount += 1;

    if (curTime == t) {
        isVisited[x][y] = true;
        return;
    }


    int type = map[x][y];
    if ((type == 1 || type == 2 || type == 5 || type == 6)) {
        if (x + 1 < map.size() && x + 1 >= 0 && y < map[0].size() && y >= 0) {
            if (isConnected(0, map[x + 1][y]) && !isVisited[x + 1][y]) {
                isVisited[x][y] = true;
                cout << "[x + 1] time = " << curTime << " " << x << ", " << y << "(" << type << ") -> " << x + 1 << ", " << y << "(" << map[x + 1][y] << ") retCount = " << retCount << endl;
                dfs(x + 1, y, t, curTime + 1, isVisited);
                //isVisited[x][y] = false;
            }

        }
    }
    if (type == 1 || type == 2 || type == 4 || type == 7) {
        if (x - 1 < map.size() && x - 1 >= 0 && y < map[0].size() && y >= 0) {
            if (isConnected(1, map[x - 1][y]) && !isVisited[x - 1][y]) {
                isVisited[x][y] = true;
                cout << "[x - 1] time = " << curTime << " " << x << ", " << y << "(" << type << ") -> " << x - 1 << ", " << y << "(" << map[x - 1][y] << ") retCount = " << retCount << endl;
                dfs(x - 1, y, t, curTime + 1, isVisited);
                //isVisited[x][y] = false;
            }

        }
    }
    if (type == 1 || type == 3 || type == 4 || type == 5) {
        if (x < map.size() && x >= 0 && y + 1 < map[0].size() && y + 1 >= 0) {
            if (isConnected(2, map[x][y + 1]) && !isVisited[x][y + 1]) {
                isVisited[x][y] = true;
                cout << "[y + 1] time = " << curTime << " " << x << ", " << y << "(" << type << ") -> " << x << ", " << y + 1 << "(" << map[x][y + 1] << ") retCount = " << retCount << endl;
                dfs(x, y + 1, t, curTime + 1, isVisited);
                //isVisited[x][y] = false;
            }

        }
    }
    if (type == 1 || type == 3 || type == 6 || type == 7) {
        if (x < map.size() && x >= 0 && y - 1 < map[0].size() && y - 1 >= 0) {
            if (isConnected(3, map[x][y - 1]) && !isVisited[x][y - 1]) {
                isVisited[x][y] = true;
                cout << "[y - 1] time = " << curTime << " " << x << ", " << y << "(" << type << ") -> " << x << ", " << y - 1 << "(" << map[x][y - 1] << ") retCount = " << retCount << endl;
                dfs(x, y - 1, t, curTime + 1, isVisited);
                //isVisited[x][y] = false;
            }

        }
    }
}

int solve(int col, int row, int x, int y, int t) {
    vector<vector<bool>> isVisited(col, vector<bool>(row, false));
    if (t > 1) {
        retCount = 0;
        dfs(x, y, t, 1, isVisited);
    }
    else
        return 1;
}

int main() {
    int n;
    cin >> n;

    vector<int> res;
    for (int k = 0; k < n; ++k) {
        map.clear();
        int col, row, m_col, m_row, t;
        cin >> col >> row >> m_col >> m_row >> t;
        //cout << col << " " <<  row << " " << m_col << " " << m_row << " " << t << endl;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                map.resize(col, vector<int>(row, 0));
                int temp;
                cin >> temp;
                map[i][j] = temp;
            }
        }

        solve(col, row, m_col, m_row, t);
        res.push_back(retCount);
        //print(map);
    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;

}

