#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Place {
    int playingTime;
    int satisfying;
    char type;
    bool visited;
};

vector<vector<int>> movingTime;
vector<Place> place;
vector<int> path;
vector<int> finalPath;
int maxSatisfying;
int maxDay;
int startIndex;
int pathPrintIndexMax;

void solve(int curPlace, int funSum, int timeSum, int curDay, int pathIndex) {
    if(curDay > maxDay) {
        if (maxSatisfying < funSum) {
            maxSatisfying = funSum;
            pathPrintIndexMax = pathIndex;
            for (int i = 0; i < pathIndex; i++)
                finalPath[i] = path[i];
        }
        return;
    }

    for (int i = 0; i < place.size(); i++) {
        if (!place[i].visited) {
            if (timeSum + movingTime[curPlace][i] + place[i].playingTime <= 540) {
                if (place[i].type == 'P') {
                    place[i].visited = true;
                    path[pathIndex] = i + 1;
                    solve(i, funSum + place[i].satisfying, timeSum + movingTime[curPlace][i] + place[i].playingTime,
                          curDay, pathIndex + 1);
                    place[i].visited = false;
                }
            }
            if (timeSum + movingTime[curPlace][i] <= 540) {
                if (place[i].type == 'H' && curDay < maxDay) {
                    path[pathIndex] = i + 1;
                    solve(i, funSum, 0, curDay + 1, pathIndex + 1);
                }
                if (place[i].type == 'A' && curDay == maxDay) {
                    path[pathIndex] = i + 1;
                    solve(i, funSum, 0, curDay + 1, pathIndex + 1);
                }
            }
        }
    }
}


int main() {
    int testCase;
    cin >> testCase;

    path.resize(40, 0);
    finalPath.resize(40, 0);

    for(int k = 0; k < testCase; k++) {
        int N, M;
        cin >> N >> M;
        maxDay = M;

        movingTime.resize(N, vector<int>(N));
        place.resize(N);

        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                int tempInt;
                cin >> tempInt;
                movingTime[i][j] = tempInt;
                movingTime[j][i] = tempInt;
            }
        }

        for(int i = 0; i < N; i++) {
            place[i].visited = false;
            char tempType;
            cin >> tempType;
            if (tempType == 'A') {
                startIndex = i;
                place[i].type = 'A';
                continue;
            } else if (tempType == 'H') {
                place[i].type = 'H';
                continue;
            } else {
                int tempTime;
                int tempFun;
                cin >> tempTime >> tempFun;
                place[i].type = 'P';
                place[i].playingTime = tempTime;
                place[i].satisfying = tempFun;
            }
        }

        maxSatisfying = 0;
        pathPrintIndexMax = 0;
        solve(startIndex, 0, 0, 1, 0);

        cout << "#" << k + 1 << " " << maxSatisfying;
        for(int i = 0; i < pathPrintIndexMax; i++) {
            cout << " " << finalPath[i];
        }
        cout << endl;
    }
}