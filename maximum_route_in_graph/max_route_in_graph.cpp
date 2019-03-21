## https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7GOPPaAeMDFAXB

#include <iostream>
#include <vector>

using namespace std;

int node[10][10];
int nodeConnectionLength[10];
bool visited[10];
int maxLength;

void dfs(int curNode, int length) {
    if(length > maxLength) {
        maxLength = length;
    }

    for(int i = 0; i < nodeConnectionLength[curNode]; i++) {
        if(!visited[node[curNode][i]]) {
            visited[node[curNode][i]] = true;
            dfs(node[curNode][i], length + 1);
            visited[node[curNode][i]] = false;
        }
    }
}

void solve(int n) {
    for(int i = 0; i < n; i++) {
        visited[i] = true;
        dfs(i, 1);
        visited[i] = false;
        if(maxLength == n)
            break;
    }
}

int main() {
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;


        for(int j = 0; j < n; j++) {
            nodeConnectionLength[j] = 0;
            visited[j] = false;
        }

        for(int j = 0; j < m; j++) {
            int from, to;
            cin >> from >> to;
            node[from - 1][nodeConnectionLength[from - 1]] = to - 1;
            node[to - 1][nodeConnectionLength[to - 1]] = from - 1;
            nodeConnectionLength[from - 1]++;
            nodeConnectionLength[to - 1]++;
        }


        maxLength = 0;

        solve(n);

        cout << "#" << i + 1 << " " << maxLength << endl;
    }
}