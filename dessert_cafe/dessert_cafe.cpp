// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<vector<int>> dessertMap;
vector<bool> appearedDessert(101, false);

int moving[4][2] = { {-1, -1}, {-1, 1}, {1, -1}, {1, 1} };

struct Info {
    int startX;
    int startY;
    int count;
    bool isVisited = false;
};

int maxCycle;
void isCycle(vector<vector<Info>> &mapInfo, int x, int y, int prevX, int prevY) {

    for (int k = 0; k < 4; k++) {
        if (x + moving[k][0] >= 0 && x + moving[k][0] < dessertMap.size() && y + moving[k][1] >= 0 && y + moving[k][1] < dessertMap.size()) {
            int newX = x + moving[k][0];
            int newY = y + moving[k][1];
            //cout << "mapInfo = " << mapInfo[x][y].startX << " , " << mapInfo[x][y].startY << endl;
            //cout << "prev = " << prevX << " , " << prevY << endl;
            //cout << "new = " << newX << " , " << newY << endl;
            if (!mapInfo[newX][newY].isVisited && !appearedDessert[dessertMap[newX][newY]]) {
                appearedDessert[dessertMap[newX][newY]] = true;
                mapInfo[newX][newY].count = mapInfo[x][y].count + 1;
                //cout << "newDessert Appears! - start = [" << mapInfo[x][y].startX << ", " << mapInfo[x][y].startY << "] : (" << x << ", " << y << ") -> (" << x + moving[k][0] << " ," << y + moving[k][1] << ") resCount = " << mapInfo[newX][newY].count << endl;
                mapInfo[newX][newY].startX = mapInfo[x][y].startX;ddddddd
                mapInfo[newX][newY].startY = mapInfo[x][y].startY;
                mapInfo[newX][newY].isVisited = true;
                isCycle(mapInfo, newX, newY, x, y);
                mapInfo[newX][newY].isVisited = false;
            }
            else if ((prevX != mapInfo[x][y].startX && prevY != mapInfo[x][y].startY != 1) && (newX == mapInfo[x][y].startX && newY == mapInfo[x][y].startY)) {
                //cout << "cycle Appears! - start = [" << mapInfo[x][y].startX << ", " << mapInfo[x][y].startY << "] : (" << x << ", " << y << ") -> (" << x + moving[k][0] << " ," << y + moving[k][1] << ") resCount = " << mapInfo[x][y].count << endl;
                int currCount = mapInfo[x][y].count;
                if (currCount > maxCycle)
                    maxCycle = currCount;
            }
        }
    }
    appearedDessert[dessertMap[x][y]] = false;
    mapInfo[x][y].isVisited = false;
}


void solve(int m) {
    maxCycle = -1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            vector<vector<Info>> mapInfo(m, vector<Info>(m));
            int x = i;
            int y = j;
            if ((x == 0 && y == 0) || (x == 0 && y == m - 1) || (x == m - 1 && y == 0) || (x == m - 1 || y == m - 1))
                continue;
            mapInfo[x][y].count = 1;
            mapInfo[x][y].startX = x;
            mapInfo[x][y].startY = y;

            appearedDessert[dessertMap[x][y]] = true;
            mapInfo[x][y].isVisited = true;
            isCycle(mapInfo, x, y, x, y);
            appearedDessert[dessertMap[x][y]] = false;

        }
    }
}


int main() {
    int n;
    cin >> n;
    vector<int> res;
    for (int i = 0; i < n; i++) {
        dessertMap.clear();
        int m;
        cin >> m;
        dessertMap.resize(m, vector<int>(m));

        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                cin >> dessertMap[j][k];
            }
        }

        solve(m);
        res.push_back(maxCycle);

    }

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << endl;
    return 0;
}

