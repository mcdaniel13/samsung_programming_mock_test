#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct Location {
    pair<int,int> location;
    bool visited;
};
int minDistance;

void move(vector<Location> &position, pair<int,int> curPoint, int n, int sum, int count) {
    if(count == n) {
        sum += abs(curPoint.first - position[1].location.first) + abs(curPoint.second - position[1].location.second);
        minDistance = min(sum, minDistance);
        return;
    }

    int partSum;
    for(int i = 2; i < n + 2; i++) {
        if(!position[i].visited) {
            int absolute = abs(curPoint.first - position[i].location.first) + abs(curPoint.second - position[i].location.second);
            partSum = sum + absolute;
            position[i].visited = true;
            move(position, position[i].location, n, partSum, count + 1);
            position[i].visited = false;
        }
    }


}

int main() {
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++) {
        int n;
        cin >> n;

        vector<Location> position(n + 2);

        for(int j = 0; j < n + 2; j++) {
            cin >> position[j].location.first >>position[j].location.second;
            position[j].visited = false;
        }
        minDistance = INT_MAX;

        move(position, position[0].location, n, 0, 0);

        cout << "#" << i + 1 << " " << minDistance << endl;

    }
}
