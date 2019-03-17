#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<vector<int>> &dessertMap, int m) {
    int result = -1;
    for (int i = 0; i < dessertMap.size(); i++) {
        for (int j = 0; j < dessertMap[i].size(); j++) {

            for (int a = 1; a < m - 1; a++) {
                for (int b = 1; b < m - 1; b++) {
                    if (j - b >= 0 && i + a + b < m && j + a < m && (a + b) * 2 > result) {
                        //cout << "result = " << result << " start = (" << i << ", " << j << ") where a = " << a << " b = " << b << endl;
                        bool isAble = true;
                        vector<bool> visited(101, false);
                        visited[dessertMap[i][j]] = true;
                        int curi = i;
                        int curj = j;
                        for (int n = 0; n < a; n++) {
                            curi = curi + 1;
                            curj = curj + 1;
                            int newDessert = dessertMap[curi][curj];
                            if (!visited[newDessert]) {
                                //cout << "[downright] (" << curi << ", " << curj << ")" << endl;
                                visited[newDessert] = true;
                            }
                            else {
                                isAble = false;
                                break;
                            }
                        }

                        if (!isAble)
                            continue;

                        for (int n = 0; n < b; n++) {
                            curi = curi + 1;
                            curj = curj - 1;
                            int newDessert = dessertMap[curi][curj];
                            if (!visited[newDessert]) {
                                //cout << "[downleft] (" << curi << ", " << curj << ")" << endl;
                                visited[newDessert] = true;
                            }
                            else {
                                isAble = false;
                                break;
                            }
                        }

                        if (!isAble)
                            continue;

                        for (int n = 0; n < a; n++) {
                            curi = curi - 1;
                            curj = curj - 1;
                            int newDessert = dessertMap[curi][curj];
                            if (!visited[newDessert]) {
                                //cout << "[upleft] (" << curi << ", " << curj << ")" << endl;
                                visited[newDessert] = true;
                            }
                            else {
                                isAble = false;
                                break;
                            }
                        }

                        if (!isAble)
                            continue;

                        for (int n = 0; n < b - 1; n++) {
                            curi = curi - 1;
                            curj = curj + 1;
                            int newDessert = dessertMap[curi][curj];
                            if (!visited[newDessert]) {
                                //cout << "[upright] (" << curi << ", " << curj << ")" << endl;
                                visited[newDessert] = true;
                            }
                            else {
                                isAble = false;
                                break;
                            }
                        }

                        if (!isAble)
                            continue;

                        result = (a + b) * 2;
                    }
                }
            }
        }
    }

    return result;
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