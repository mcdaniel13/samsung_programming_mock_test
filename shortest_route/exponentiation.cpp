#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

pair<int, int> company;
pair<int, int> home;
vector<pair<int, int>> customers;
int minDistance;

int calculateDistance(pair<int, int> point1, pair<int,int> point2) {
    return abs(point1.first - point2.first) + abs(point1.second - point2.second);
}

void move(pair<int,int> curPoint, int startIndex, int sum) {
    int partSum;
    bool isLast = true;
    
    for(int i = startIndex; i < customers.size(); i++) {
        cout << "curPoint = (" << curPoint.first << ", " << curPoint.second << ") sum = " << sum << endl;
        isLast = true;
        partSum = sum + calculateDistance(curPoint, customers[i]);
        cout << "(" << curPoint.first << ", " << curPoint.second << ") -> (" << customers[i].first << ", " << customers[i].second << ")";
        cout << " sum = " << sum << endl;
        move(customers[i], i + 1, partSum);
    }
    
    cout << "curPoint = (" << curPoint.first << ", " << curPoint.second << ") sum = " << sum << endl;
    if(isLast) {
        sum += calculateDistance(curPoint, home);
        minDistance = min(sum, minDistance);
        cout << "(" << curPoint.first << ", " << curPoint.second << ") sum = " << sum << endl;
        cout << "minDistacne = " << minDistance << endl;
    }
}

int main() {
    int testcase;
    cin >> testcase;
    for(int i = 0; i < testcase; i++) {
        int n;
        cin >> n;
        
        customers.clear();
        customers.resize(n);
        
        cin >> company.first >> company.second >> home.first >> home.second;
        for(int j = 0; j < n; j++) {
            cin >> customers[j].first >> customers[j].second;
        }
        
        minDistance = INT_MAX;
        
        move(company, 0, 0);
        
        cout << minDistance << endl;
        
    }
}
