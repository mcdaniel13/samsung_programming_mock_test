#include <iostream>
#include <vector>

using namespace std;

bool isAble;

void dfs(const vector<vector<int>> &arr, int p) {
    if(p == 99)
        isAble = true;
    
    for(int i = 0; i < arr[p].size(); i++) {
        if(!isAble) {
            dfs(arr, arr[p][i]);
        } else
            break;
    }
}

bool solve(const vector<vector<int>> &arr, int n) {
    int start = 0;
    isAble = false;
    
    dfs(arr, start);
    
    return isAble;
}


int main() {
    for(int i = 0; i < 10; i++) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> arr(100);
        for(int j = 0; j < m; j++) {
            int from, to;
            cin >> from >> to;
            arr[from].push_back(to);
        }
        
        cout << "#" << n << " " << solve(arr, m) << endl;
        
    }
}
