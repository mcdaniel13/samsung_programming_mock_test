#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<vector<bool>> isVisited;

bool isConnected(int direction, int nextType) {
    if (nextType == 0)
        return false;

    if (direction == 0) {
        if (nextType == 1 || nextType == 2 || nextType == 4 || nextType == 7)
            return true;
    }
    else if (direction == 1) {
        if (nextType == 1 || nextType == 2 || nextType == 5 || nextType == 6)
            return true;
    }
    else if (direction == 2) {
        if (nextType == 1 || nextType == 3 || nextType == 6 || nextType == 7)
            return true;
    }
    else if (direction == 3) {
        if (nextType == 1 || nextType == 3 || nextType == 4 || nextType == 5)
            return true;
    }

    return false;
}


int bfs(int startX, int startY, int t) {
    int retCount = 1;
    queue<pair<int,int>> q;
    queue<pair<int, int>> qPrev;
    queue<int> qDepth;

    q.push(make_pair(startX, startY));
    qPrev.push(make_pair(startX, startY));
    qDepth.push(1);
    isVisited[startX][startY] = true;

    while (!q.empty())  {
        int x = q.front().first;
        int y = q.front().second;
        int prevX = qPrev.front().first;
        int prevY = qPrev.front().second;
        int curDepth = qDepth.front();

        if (curDepth == t)
            break;


        int type = map[x][y];
        q.pop();
        qPrev.pop();
        qDepth.pop();

        if ((type == 1 || type == 2 || type == 5 || type == 6)) {
            if (x + 1 < map.size() && x + 1 >= 0 && y < map[0].size() && y >= 0 && !(x + 1 == prevX && y == prevY)) {
                if (isConnected(0, map[x + 1][y])) {
                    if (!isVisited[x + 1][y]) {
                        isVisited[x + 1][y] = true;
                        retCount += 1;
                    }
                    q.push(make_pair(x + 1, y));
                    qPrev.push(make_pair(x, y));
                    int nextDepth = curDepth + 1;
                    qDepth.push(nextDepth);
                }

            }
        }
        if (type == 1 || type == 2 || type == 4 || type == 7) {
            if (x - 1 < map.size() && x - 1 >= 0 && y < map[0].size() && y >= 0 && !(x - 1 == prevX && y == prevY)) {
                if (isConnected(1, map[x - 1][y])) {
                    if (!isVisited[x - 1][y]) {
                        isVisited[x - 1][y] = true;
                        retCount += 1;
                    }
                    q.push(make_pair(x - 1, y));
                    qPrev.push(make_pair(x, y));
                    int nextDepth = curDepth + 1;
                    qDepth.push(nextDepth);
                }

            }
        }
        if (type == 1 || type == 3 || type == 4 || type == 5) {
            if (x < map.size() && x >= 0 && y + 1 < map[0].size() && y + 1 >= 0 && !(x == prevX && y + 1 == prevY)) {
                if (isConnected(2, map[x][y + 1])) {
                    if (!isVisited[x][y + 1]) {
                        isVisited[x][y + 1] = true;
                        retCount += 1;
                    }
                    q.push(make_pair(x, y + 1));
                    qPrev.push(make_pair(x, y));
                    int nextDepth = curDepth + 1;
                    qDepth.push(nextDepth);
                }

            }
        }
        if (type == 1 || type == 3 || type == 6 || type == 7) {
            if (x < map.size() && x >= 0 && y - 1 < map[0].size() && y - 1 >= 0 && !(x == prevX && y - 1 == prevY)) {
                if (isConnected(3, map[x][y - 1])) {
                    if (!isVisited[x][y - 1]) {
                        isVisited[x][y - 1] = true;
                        retCount += 1;
                    }
                    q.push(make_pair(x, y - 1));
                    qPrev.push(make_pair(x, y));
                    int nextDepth = curDepth + 1;
                    qDepth.push(nextDepth);
                }

            }
        }
    }

    return retCount;
}

int solve(int col, int row, int x, int y, int t) {
    if (t > 1) {
        return bfs(x, y, t);
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
        isVisited.clear();
        int col, row, m_col, m_row, t;
        cin >> col >> row >> m_col >> m_row >> t;
        //cout << col << " " <<  row << " " << m_col << " " << m_row << " " << t << endl;
        for (int i = 0; i < col; ++i) {
            for (int j = 0; j < row; ++j) {
                map.resize(col, vector<int>(row, 0));
                isVisited.resize(col, vector<bool>(row, false));
                int temp;
                cin >> temp;
                map[i][j] = temp;
            }
        }

        cout << "#" << k + 1 << " " << solve(col, row, m_col, m_row, t) << endl;
    }
}

