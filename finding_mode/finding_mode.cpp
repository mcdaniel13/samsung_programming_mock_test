#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> res;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;

        vector<int> points(1000);
        map<int, int> arr;

        int maxAppear = 0;
        int maxPoint = 0;
        for (int j = 0; j < 1000; j++) {
            cin >> points[j];
            arr[points[j]] += 1;
            if (maxAppear <= arr[points[j]]) {
                maxAppear = arr[points[j]];
                maxPoint = points[j];
            }
        }

        cout << maxPoint << endl;
        res.push_back(maxPoint);
    }

    for (int i = 0; i < n; i++) {
        cout << "#" << i + 1 << " " << res[i] << endl;
    }
}