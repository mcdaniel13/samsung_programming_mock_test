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

bool isConnected(int type, int nextType) {
    if(nextType == 1)
        return true;
    if(type == 1 || type == 2 || type == 4 || type == 7) {
        if(nextType == 2 || nextType == 5 || nextType == 6)
            return true;
    }
    if(type == 1 || type == 2 || type == 5 || type == 6) {
        if(nextType == 2 || nextType == 4 || nextType == 7)
            return true;
    }
    if(type == 1 || type == 4 || type == 5 || type == 3) {
        if(nextType == 3 || nextType == 6 || nextType == 7)
            return true;
    }
    if(type == 1 || type == 3 || type == 6 || type == 7) {
        if(nextType == 4 || nextType == 5 || nextType == 3)
            return true;
    }

    return false;
}

void dfs(int x, int y, int t, int curTime, vector<vector<bool>> &isVisited) {
    retCount += 1;

    if(curTime == t)
        return;

    int type = map[x][y];
    if((type == 1 || type == 2 || type == 4 || type == 7)) {

        isVisited[x][y] = true;
        if(isConnected(type, map[x + 1][y]) && !isVisited[x + 1][y]) {
            cout << x << ", " << y << " -> " << x + 1 << ", " << y << " retCount = " << retCount << endl;
            dfs(x + 1, y, t, curTime + 1, isVisited);
        }
        isVisited[x][y] = false;
    }
    if(type == 1 || type == 2 || type == 5 || type == 6) {
        isVisited[x][y] = true;
        if(isConnected(type, map[x - 1][y]) && !isVisited[x - 1][y]) {
            cout << x << ", " << y << " -> " << x - 1 << ", " << y << " retCount = " << retCount << endl;
            dfs(x - 1, y, t, curTime + 1, isVisited);
        }
        isVisited[x][y] = false;
    }
    if(type == 1 || type == 4 || type == 5 || type == 3) {
        isVisited[x][y] = true;
        if(isConnected(type, map[x][y + 1]) && !isVisited[x][y + 1]) {
            cout << x << ", " << y << " -> " << x  << ", " << y + 1 << " retCount = " << retCount << endl;
            dfs(x, y + 1, t, curTime + 1, isVisited);
        }
        isVisited[x][y] = false;
    }
    if(type == 1 || type == 3 || type == 6 || type == 7) {
        isVisited[x][y] = true;
        if(isConnected(type, map[x][y - 1]) && !isVisited[x][y - 1]) {
            cout << x << ", " << y << " -> " << x << ", " << y - 1 << " retCount = " << retCount << endl;
            dfs(x, y - 1, t, curTime + 1, isVisited);
        }
        isVisited[x][y] = false;
    }
}

int solve(int col, int row, int x, int y, int t) {
    vector<vector<bool>> isVisited(col, vector<bool>(row, false));
    if(t > 1) {
        retCount = 0;
        dfs(x, y, t, 1, isVisited);
    } else
        return 1;
}

int main() {
    int n;
    cin >> n;

    for(int k = 0; k < n; ++k) {
        map.clear();
        int col, row, m_col, m_row, t;
        cin >> col >> row >> m_col >> m_row >> t;
        cout << col << " " <<  row << " " << m_col << " " << m_row << " " << t << endl;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                map.resize(col, vector<int>(row, 0));
                int temp;
                cin >> temp;
                map[i][j] = temp;
            }
        }

        solve(col, row, m_col, m_row, t);
        cout << retCount << endl;
        print(map);
    }


}