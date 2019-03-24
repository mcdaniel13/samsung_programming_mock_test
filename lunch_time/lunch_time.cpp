/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5-BEE6AK0DFAVl
 */
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

const int NMAX = 10;
const int MMAX = 10;
const int HMAX = 10;

int n;
int numOfHumans;
int numOfStairs;
int humans[HMAX][2];
int stairs[2][2];
int stairTime[2];
int choosingStair[HMAX];
int stairOneDist[HMAX];
int stairTwoDist[HMAX];
bool stairVisited[HMAX];
int minTime;
queue<int> stairDown;

void findTotalTime() {
    int stairOneCount = 0;
    int stairTwoCount = 0;
    for(int i = 0; i < numOfHumans; i++) {
        if(choosingStair[i] == 0) {
            stairOneDist[stairOneCount] = abs(humans[i][0] - stairs[0][0]) + abs(humans[i][1] - stairs[0][1]);
            stairOneCount++;
        } else {
            stairTwoDist[stairTwoCount] = abs(humans[i][0] - stairs[1][0]) + abs(humans[i][1] - stairs[1][1]);
            stairTwoCount++;
        }
    }

    int stairOneSec;
    int stairTwoSec;

    int sec = 0;
    int checkCount = 0;
    int stairWait = 0;

    while(true) {
        while(!stairDown.empty()) {
            if (sec == stairDown.front()) {
                stairDown.pop();
                checkCount++;
            } else {
                break;
            }
        }

        while(true) {
            if(stairWait != 0 && stairDown.size() < 3) {
                stairWait--;
                stairDown.push(sec + stairTime[0]);
            } else
                break;
        }

        for(int i = 0; i < stairOneCount; i++) {
            if (sec == stairOneDist[i]) {
                stairWait++;
            }
        }

        if(checkCount == stairOneCount) {
            stairOneSec = sec;
            break;
        }

        sec++;
    }

    if(stairOneSec > minTime)
        return;

    while(!stairDown.empty())
        stairDown.pop();


    sec = 0;
    checkCount = 0;
    stairWait = 0;

    while(true) {
        while(!stairDown.empty()) {
            if (sec == stairDown.front()) {
                stairDown.pop();
                checkCount++;
            } else {
                break;
            }
        }

        while(true) {
            if(stairWait != 0 && stairDown.size() < 3) {
                stairWait--;
                stairDown.push(sec + stairTime[1]);
            } else
                break;
        }

        for(int i = 0; i < stairTwoCount; i++) {
            if(sec == stairTwoDist[i]) {
                stairWait++;
            }
        }

        if(checkCount == stairTwoCount) {
            stairTwoSec = sec;
            break;
        }

        sec++;
    }

    if(stairTwoSec > minTime)
        return;

    minTime = min(minTime, max(stairOneSec, stairTwoSec));
}

void solve(int curHuman) {
    if(curHuman == numOfHumans) {
        findTotalTime();
        return;
    } else {
        for(int i = 0; i < 2; i++) {
            choosingStair[curHuman] = i;
            solve(curHuman + 1);
        }
    }
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        numOfHumans = 0;
        numOfStairs = 0;
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                int temp;
                cin >> temp;
                if(temp == 1) {
                    humans[numOfHumans][0] = j;
                    humans[numOfHumans][1] = k;
                    numOfHumans++;
                } else if (temp != 0) {
                    stairs[numOfStairs][0] = j;
                    stairs[numOfStairs][1] = k;
                    stairTime[numOfStairs] = temp;
                    numOfStairs++;
                }
            }
        }

        minTime = INT_MAX;

        solve(0);

        cout << "#" << i + 1 << " " << minTime << endl;
    }
}