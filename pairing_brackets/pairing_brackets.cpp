#include <iostream>
#include <stack>

using namespace std;

bool solve(string s, int n) {
    stack<char> pranStack;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            pranStack.push(')');
        } else if (s[i] == '{') {
            pranStack.push('}');
        } else if (s[i] == '[') {
            pranStack.push(']');
        } else if (s[i] == '<') {
            pranStack.push('>');
        } else if (s[i] == pranStack.top()) {
            pranStack.pop();
        } else {
            return false;
        }
    }
    
    return true;
}


int main() {
    for(int i = 0; i < 10; i++) {
        int n;
        string s;
        cin >> n;
        cin >> s;
        
        cout << "#" << i + 1 << " " << solve(s, n) << endl;
    }
}
