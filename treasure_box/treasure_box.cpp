/*
 * https://www.swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWXRUN9KfZ8DFAUo
 */

#include <iostream>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int N, K;
string arr;
string subArr[100];

long long int result;

void solve() {
    int r = N / 4;
    int numCount = 0;
    for(int j = 0; j < r; j++) {
        int start = N - j;
        for (int i = 0; i < 4; i++) {
            subArr[numCount] = arr.substr(start, r);
            numCount++;
            start = start + r;
        }
    }

//    cout << numCount << endl;
//    for(int i = 0; i <numCount; i++) {
//        cout << subArr[i] << endl;
//    }

    //covertToDecimal
    map<long long int, bool> numberInt;
    for(int i = 0; i < numCount; i++) {
        string hexadecimal = subArr[i];
        long long int decimal = 0;
        for(int j = 0; j < hexadecimal.size(); j++) {
            long long int temp;
            if(hexadecimal[j] == 'A') {
                temp = 10;
            } else if(hexadecimal[j] == 'B') {
                temp = 11;
            } else if(hexadecimal[j] == 'C') {
                temp = 12;
            } else if(hexadecimal[j] == 'D') {
                temp = 13;
            } else if(hexadecimal[j] == 'E') {
                temp = 14;
            } else if(hexadecimal[j] == 'F') {
                temp = 15;
            } else {
                temp = hexadecimal[j] - '0';
            }
            decimal += temp * (long long int) pow(16, hexadecimal.size() - 1 - j);
        }
        numberInt[decimal] = true;
    }

    int findCount = numberInt.size() - K;
    for(map<long long int, bool>::iterator it = numberInt.begin(); it != numberInt.end(); it++) {
        if(findCount == 0) {
            result = it->first;
            break;
        }
        findCount--;
    }
}

int main() {
    int t;
    cin >> t;

    arr.clear();
    for(int k = 0; k < t; k++) {
        cin >> N >> K >> arr;

        arr.append(arr);

        result = 0;
        solve();
        cout << "#" << k + 1 << " " <<  result << endl;
    }
}