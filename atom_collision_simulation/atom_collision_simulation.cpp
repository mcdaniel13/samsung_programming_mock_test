/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRFInKex8DFAUo
 */

#include <iostream>

using namespace std;

int n;

int moving[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int atomPos[1000][2];
int atomDir[1000];
int atomEnergy[1000];
int occupied[4001][4001];
bool collided[4001][4001];
int totalCount;

void removeAtom(int index, int last) {
    atomPos[index][0] = atomPos[last][0];
    atomPos[index][1] = atomPos[last][1];
    atomDir[index] = atomDir[last];
    atomEnergy[index] = atomEnergy[last];
}

void solve() {
    totalCount = 0;
    int curN = n;
    //init position
    for(int i = 0; i < curN; i++) {
        atomPos[i][0] = atomPos[i][0] * 2;
        atomPos[i][1] = atomPos[i][1] * 2;
        occupied[atomPos[i][0]][atomPos[i][1]] += 1;
    }

    for(int i = 0; i <= 4001; i++) {
        for(int j = 0; j < curN; j++) {
            occupied[atomPos[j][0]][atomPos[j][1]] -= 1;
            atomPos[j][0] = atomPos[j][0] + moving[atomDir[j]][0];
            atomPos[j][1] = atomPos[j][1] + moving[atomDir[j]][1];
            if(atomPos[j][0] < 0 || atomPos[j][0] > 4000 || atomPos[j][1] < 0 || atomPos[j][1] > 4000) {
                removeAtom(j, curN - 1);
                curN--;
                j--;
            } else {
                occupied[atomPos[j][0]][atomPos[j][1]] += 1;
                if(occupied[atomPos[j][0]][atomPos[j][1]] >= 2) {
                    collided[atomPos[j][0]][atomPos[j][1]] = true;
                }
            }
        }

        for(int j = 0; j < curN; j++) {
            int curX = atomPos[j][0];
            int curY = atomPos[j][1];
            if(collided[curX][curY]) {
                totalCount += atomEnergy[j];
                occupied[curX][curY]--;
                if(occupied[curX][curY] == 0)
                    collided[curX][curY] = false;
                removeAtom(j, curN - 1);
                curN--;
                j--;
            }
        }

        if(curN == 0)
            break;
    }
}


int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {

        cin >> n;

        for(int j = 0; j < n; j++) {
            cin >> atomPos[j][0] >> atomPos[j][1] >> atomDir[j] >> atomEnergy[j];
            atomPos[j][0] += 1000;
            atomPos[j][1] += 1000;
        }

        solve();
        cout << "#" << i + 1 << " " << totalCount << endl;
    }
}