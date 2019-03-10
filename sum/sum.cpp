#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(const vector<vector<int>> &arr) {
    vector<int> rowSums(100, 0);
    vector<int> colSums(100, 0);
    vector<int> diagSums(2, 0);

    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            int curVal = arr[i][j];
            colSums[i] += curVal;
            rowSums[j] += curVal;

            if (i == j)
                diagSums[0] += curVal;

            if (i + j == arr.size() - 1)
                diagSums[1] += curVal;
        }
    }

    int maxSum = 0;
    for (int i = 0; i < 100; i++) {
        maxSum = max(maxSum, max(colSums[i], rowSums[i]));
    }
    maxSum = max(maxSum, max(diagSums[0], diagSums[1]));

    return maxSum;
}

int main() {
    vector<pair<int, int>> res;
    for (int k = 0; k < 10; k++) {
        int n;
        cin >> n;
        vector<vector<int>> arr(100, vector<int>(100));
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
            }
        }

        //cout << solve(arr) << endl;
        res.push_back(make_pair(n, solve(arr)));
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << "#" << res[i].first << " " << res[i].second << endl;
    }
}

