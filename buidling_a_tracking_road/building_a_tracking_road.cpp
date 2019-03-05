#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int moveCordinates[4][2] = {{0, 1},{1, 0}, {0, -1}, {-1, 0}};
int maxDistance = 0;

void dfs(const vector<vector<int>> &consMap, vector<vector<bool>> &isVisited, int x, int y, int curVal, bool isUsed, int distance, int k) {
    for (int i = 0; i < 4; ++i) {
        int newX = x + moveCordinates[i][0];
        int newY = y + moveCordinates[i][1];

        if(newX < 0 || newX >= consMap.size() || newY < 0 || newY >= consMap.size())
            continue;

        if(isVisited[newX][newY])
            continue;

        int nextVal = consMap[newX][newY];
        if(nextVal < curVal) {
            isVisited[newX][newY] = true;
            int newDistance = distance + 1;
            //cout << "x = " << x << " y = " << y << " newX = " << newX << " newY = " << newY << " distance = " << newDistance << endl;
            dfs(consMap, isVisited, newX, newY, nextVal, isUsed, newDistance, k);
            isVisited[newX][newY] = false;
        } else {
            if ((!isUsed) && (nextVal - k < curVal)) {
                int newDistance = distance + 1;
                //cout << "x = " << x << " y = " << y << " newX = " << newX << " newY = " << newY << " distance = " << newDistance << endl;
                isVisited[newX][newY] = true;
                dfs(consMap, isVisited, newX, newY, curVal - 1, true, newDistance, k);
                isVisited[newX][newY] = false;
            }
        }


        if(maxDistance < distance)
            maxDistance = distance;
    }


}

int findLogestPath(const vector<vector<int>> &consMap, const vector<pair<int,int>> &maxCordinates, const int &k) {
    for (int i = 0; i < maxCordinates.size(); ++i) {
        int x = maxCordinates[i].first;
        int y = maxCordinates[i].second;

        vector<vector<bool>> isVisited(consMap.size(), vector<bool>(consMap.size(), false));

        isVisited[x][y] = true;
        dfs(consMap, isVisited, x, y, consMap[x][y], false, 1, k);
    }

    return maxDistance;
}

int main() {
    int n, size, K;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> size >> K;
        vector<vector<int>> consMap;
        map<int, vector<pair<int, int>>> cordinates;
        int maxVal = 0;
        for (int j = 0; j < size; ++j) {
            consMap.resize(size, vector<int>(size));
            for (int k = 0; k < size; ++k) {
                int temp;
                cin >> temp;
                consMap[j][k] = temp;
                cordinates[temp].push_back(make_pair(j, k));

                if(temp >= maxVal) {
                    maxVal = temp;
                }
            }
        }
        vector<pair<int,int>> maxCordinates = cordinates[maxVal];

        int result = findLogestPath(consMap, maxCordinates, K);
        maxDistance = 0;
        cout << "#" << i + 1 << " " << result << endl;
    }

}
