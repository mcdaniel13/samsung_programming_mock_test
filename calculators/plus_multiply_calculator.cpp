#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solve(vector<char> arr) {
    stack<int> numStack;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] - '0' <= 9 && arr[i] - '0' >= 0) {
            int charToInt = arr[i] - '0';
            numStack.push(charToInt);
        }
        else {
            int second = numStack.top();
            numStack.pop();
            int first = numStack.top();
            numStack.pop();
            int calculated;
            if (arr[i] == '+') {
                calculated = first + second;
            } else {
                calculated = first * second;
            }
            numStack.push(calculated);
        }
    }

    return numStack.top();
}

vector<char> findCheckDigit(string str, int n) {
    vector<char> checkDigitArr;
    stack<char> checkDigitStack;

    for (int i = 0; i < n; i++) {
        char curChar = str[i];
        if (curChar == '*') {
            while (!checkDigitStack.empty()) {
                if (checkDigitStack.top() != '*')
                    break;
                else {
                    char topChar = checkDigitStack.top();
                    checkDigitArr.push_back(topChar);
                    checkDigitStack.pop();
                }
            }

            checkDigitStack.push(curChar);
        }
        else if (curChar == '+') {
            while (!checkDigitStack.empty()) {
                char topChar = checkDigitStack.top();
                checkDigitArr.push_back(topChar);
                checkDigitStack.pop();
            }
            checkDigitStack.push(curChar);
        }
        else
            checkDigitArr.push_back(curChar);
    }

    while (!checkDigitStack.empty()) {
        checkDigitArr.push_back(checkDigitStack.top());
        checkDigitStack.pop();
    }

    return checkDigitArr;
}


int main() {
    for (int i = 0; i < 10; i++) {
        int n;
        cin >> n;
        string str;
        cin >> str;

        vector<char> checkDigit = findCheckDigit(str, n);
        int result = solve(checkDigit);

        cout << "#" << i + 1 << " " << result << endl;
    }
}