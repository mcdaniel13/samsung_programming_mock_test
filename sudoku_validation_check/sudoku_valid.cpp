#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(vector<vector<int>> matrix) {
    vector<vector<bool>> rowCheck(9, vector<bool>(9,false));
    vector<vector<bool>> subMatrixCheck(9, vector<bool>(9, false));

    vector<int> trueRowCount(9, 0);
    vector<int> trueColCount(9, 0);
    vector<int> trueSubMatrixCount(9, 0);

    for (int i = 0; i < 9; i++) {
        vector<bool> colCheck(9, false);
        for (int j = 0; j < 9; j++) {
            int curVal = matrix[i][j] - 1;

            if (!colCheck[curVal]) {
                colCheck[curVal] = true;
                trueColCount[i] += curVal;
            }
            else
                return false;

            if (!rowCheck[j][curVal]) {
                rowCheck[j][curVal] = true;
                trueRowCount[j] += curVal;
            } else
                return false;

            if (i >= 0 && i <= 2 && j >= 0 && j <= 2) {
                if (!subMatrixCheck[0][curVal]) {
                    trueSubMatrixCount[0] += curVal;
                    subMatrixCheck[0][curVal] = true;
                } else
                    return false;
            } else if (i >= 0 && i <= 2 && j >= 3 && j <= 5) {
                if (!subMatrixCheck[1][curVal]) {
                    trueSubMatrixCount[1]+= curVal;
                    subMatrixCheck[1][curVal] = true;
                } else
                    return false;
            } else if (i >= 0 && i <= 2 && j >= 6 && j <= 8) {
                if (!subMatrixCheck[2][curVal]) {
                    trueSubMatrixCount[2] += curVal;
                    subMatrixCheck[2][curVal] = true;
                }
                else
                    return false;
            } else if (i >= 3 && i <= 5 && j >= 0 && j <= 2) {
                if (!subMatrixCheck[3][curVal]) {
                    trueSubMatrixCount[3] += curVal;
                    subMatrixCheck[3][curVal] = true;
                }
                else
                    return false;
            } else if (i >= 3 && i <= 5 && j >= 3 && j <= 5) {
                if (!subMatrixCheck[4][curVal]) {
                    trueSubMatrixCount[4] += curVal;
                    subMatrixCheck[4][curVal] = true;
                }
                else
                    return false;
            } else if (i >= 3 && i <= 5 && j >= 6 && j <= 8) {
                if (!subMatrixCheck[5][curVal]) {
                    trueSubMatrixCount[5] += curVal;
                    subMatrixCheck[5][curVal] = true;
                }
                else
                    return false;
            } else if (i >= 6 && i <= 8 && j >= 0 && j <= 2) {
                if (!subMatrixCheck[6][curVal]) {
                    trueSubMatrixCount[6] += curVal;
                    subMatrixCheck[6][curVal] = true;
                }
                else
                    return false;
            } else if (i >= 6 && i <= 8 && j >= 3 && j <= 5) {
                if (!subMatrixCheck[7][curVal]) {
                    trueSubMatrixCount[7] += curVal;
                    subMatrixCheck[7][curVal] = true;
                }
                else
                    return false;
            } else {
                if (!subMatrixCheck[8][curVal]) {
                    trueSubMatrixCount[8] += curVal;
                    subMatrixCheck[8][curVal] = true;
                }
                else
                    return false;
            }
        }
    }

    for (int i = 0; i < 9; i++) {
        if (trueRowCount[i] != 36 && trueColCount[i] != 36 && trueSubMatrixCount[i] != 36)
            return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<bool> res(n);
    for (int i = 0; i < n; i++) {
        vector<vector<int>> matrix(9, vector<int>(9));
        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                cin >> matrix[j][k];
            }
        }

        bool isValid =  solve(matrix);
        res[i] = isValid;
    }

    for (int i = 0; i < n; i++) {
        cout << "#" << i + 1 << " " << res[i] << endl;
    }
}

