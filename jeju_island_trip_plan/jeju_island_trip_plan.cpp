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

vector<int> path;
int maxSatsfying;
int maxDay;
int startIndex;
int pathPrintIndexMax;

void solve(vector<Place> &place, vector<vector<int>> &movingTime, int curPlace, int funSum, int timeSum, int curDay, int pathIndex) {
    if(curDay > maxDay) {
        if (maxSatsfying < funSum) {
            maxSatsfying = funSum;
            pathPrintIndexMax = pathIndex;
        }
        return;
    }
    for (int i = 0; i < place.size(); i++) {
        if (!place[i].visited) {
            if (timeSum + movingTime[curPlace][i] + place[i].playingTime <= 540 && place[i].type == 'P') {
                place[i].visited = true;
                //path[pathIndex] = i + 1;
                solve(place, movingTime, i, funSum + place[i].satisfying, timeSum + movingTime[curPlace][i] + place[i].playingTime, curDay, pathIndex + 1);
                place[i].visited = false;
            } else if (timeSum + movingTime[curPlace][i] <= 540 && place[i].type == 'H' && curDay < maxDay) {
                //path[pathIndex] = i + 1;
                solve(place, movingTime, i, funSum, 0, curDay + 1, pathIndex + 1);
            } else if (timeSum + movingTime[curPlace][i] <= 540 && place[i].type == 'A' && place[curPlace].type == 'P' && curDay == maxDay) {
                //path[pathIndex] = i + 1;
                solve(place, movingTime, i, funSum, 0, curDay + 1, pathIndex + 1);
            }
        }
    }
}


int main() {
    int testCase;
    cin >> testCase;
    for(int k = 0; k < testCase; k++) {
        int N, M;
        cin >> N >> M;
        maxDay = M;
        vector<vector<int>> temp(N, vector<int>(N));
        vector<Place> place(N);
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                int tempInt;
                cin >> tempInt;
                temp[i][j] = tempInt;
                temp[j][i] = tempInt;
            }
        }

        path.clear();

        for(int i = 0; i < N; i++) {
            place[i].visited = false;
            char tempType;
            cin >> tempType;
            if (tempType == 'A') {
                startIndex = i;
                place[i].type = 'A';
                place[i].playingTime = 0;
                place[i].satisfying = 0;
            } else if (tempType == 'H') {
                place[i].type = 'H';
                place[i].playingTime = 0;
                place[i].satisfying = 0;
            } else {
                int tempTime;
                int tempFun;
                cin >> tempTime >> tempFun;
                place[i].type = 'P';
                place[i].playingTime = tempTime;
                place[i].satisfying = tempFun;
            }
        }

        maxSatsfying = 0;
        path.resize(40, 0);

        solve(place, temp, startIndex, 0, 0, 1, 0);

        cout << "#" << k + 1 << " " << maxSatsfying;
//        for(int i = 0; i < pathPrintIndexMax; i++) {
//            cout << " " << path[i];
//        }
        cout << endl;
    }
}