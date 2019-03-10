#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point {
public:
    int x;
    int y;
    vector<bool> visited;
    int count;
    int startX;
    int startY;

    Point(int curX, int curY, int stX, int stY, int cnt, vector<bool> isVisited) {
        x = curX;
        y = curY;
        startX = stX;
        startY = stY;
        count = cnt;
        visited = isVisited;
    }
};

int solve(const vector<vector<int>> &dessertMap, int m) {
    vector<Point> a;
    vector<Point> b;
    vector<Point> c;
    vector<Point> d;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            vector<bool> isVisited(101, false);
            int count = 1;
            int startX = i;
            int startY = j;
            int x = i;
            int y = j;
            isVisited[dessertMap[x][y]] = true;
            while (x + 1 >= 0 && x + 1 < m - 1 && y + 1 >= 0 && y + 1 < m && isVisited[dessertMap[x + 1][y + 1]] == false) {
                x = x + 1;
                y = y + 1;
                count++;
                isVisited[dessertMap[x][y]] = true;
                Point tempPoint(x, y, startX, startY, count, isVisited);
                a.push_back(tempPoint);
            }
        }
    }

    for (int i = 0; i < a.size(); i++) {
        int x = a[i].x;
        int y = a[i].y;
        int count = a[i].count;
        while (x + 1 >= 0 && x + 1 < m && y - 1 >= 1 && y - 1 < m && a[i].visited[dessertMap[x + 1][y - 1]] == false) {
            x = x + 1;
            y = y - 1;
            count++;
            a[i].visited[dessertMap[x][y]] = true;
            Point tempPoint(x, y, a[i].startX, a[i].startY, count, a[i].visited);
            b.push_back(tempPoint);
        }
    }

    for (int i = 0; i < b.size(); i++) {
        int x = b[i].x;
        int y = b[i].y;
        int count = b[i].count;
        while (x - 1 >= 1 && x - 1 < m && y - 1 >= 0 && y - 1 < m && b[i].visited[dessertMap[x - 1][y - 1]] == false) {
            x = x - 1;
            y = y - 1;
            count++;
            b[i].visited[dessertMap[x][y]] = true;
            Point tempPoint(x, y, b[i].startX, b[i].startY, count, b[i].visited);
            c.push_back(tempPoint);
        }
    }

    int maxCount = -1;
    for (int i = 0; i < c.size(); i++) {
        int x = c[i].x;
        int y = c[i].y;
        int count = c[i].count;
        while (x - 1 >= 0 && x - 1 < m && y + 1 >= 0 && y + 1 < m && c[i].visited[dessertMap[x - 1][y + 1]] == false) {
            x = x - 1;
            y = y + 1;
            count++;
            c[i].visited[dessertMap[x][y]] = true;
            Point tempPoint(x, y, c[i].startX, c[i].startY, count, c[i].visited);
            d.push_back(tempPoint);
        }
        if (x - 1 == c[i].startX && y + 1 == c[i].startY) {
            maxCount = max(maxCount, count);
        }
    }

    return maxCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<vector<int>> dessertMap(m, vector<int>(m));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                cin >> dessertMap[j][k];
            }
        }

        res[i] = solve(dessertMap, m);
    }

    for (int i = 0; i < n; i++) {
        cout << "#" << i + 1 << " " << res[i] << endl;
    }
}