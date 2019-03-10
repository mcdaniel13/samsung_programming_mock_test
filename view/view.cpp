#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<int> buildings) {
    int viewCount = 0;
    for (int i = 2; i < buildings.size() - 2; i++) {
        int curHeight = buildings[i];
        int maxLeft = max(buildings[i - 1], buildings[i - 2]);
        int maxRight = max(buildings[i + 1], buildings[i + 2]);
        int maxHeight = max(maxLeft, maxRight);

        if (maxHeight < curHeight) {
            viewCount += curHeight - maxHeight;
        }
    }
    return viewCount;
}

int main() {
    int n = 10;
    vector<int> res(10);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> buildings(m);
        for (int j = 0; j < m; j++) {
            cin >> buildings[j];
        }

        res[i] = solve(buildings);
    }

    for (int i = 0; i < n; i++) {
        cout << "#" << i + 1 << " " << res[i] << endl;
    }
}