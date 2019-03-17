#include <iostream>

using namespace std;

int solve(int n, int m) {
    if(m == 1)
        return n;

    return n * solve(n, m - 1);
}


int main() {
    for(int i = 0; i < 10; i++) {
        int k, n, m;
        cin >> k >> n >> m;

        cout << "#" << k << " " << solve(n, m) << endl;
    }
}