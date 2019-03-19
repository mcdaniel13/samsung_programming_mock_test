#include <iostream>

using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        int result = 0;
        for (int j = 0; j < n; j++) {
            char m;
            cin >> m;
            if (m != '+') {
                int k = m - '0';
                result += k;
            }
        }

        cout << "#" << i + 1 << " " << result << endl;
    }
}