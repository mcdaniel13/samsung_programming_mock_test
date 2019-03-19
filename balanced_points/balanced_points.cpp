#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int m;
vector<double> location;
vector<double> mass;

double calculate(double mass, double pos1, double pos2) {
    return mass / ((pos1 - pos2) * (pos1 - pos2));
}

double findBalancedLocation(int posIndex1, int posIndex2, double pos1, double pos2) {
    if(abs(pos1 - pos2) < 1e-12)
        return pos1;
    
    double mid = pos1 + (pos2 - pos1) / 2.0;
    double left = 0;
    double right = 0;
    
    for(int i = 0; i <= posIndex1; i++)
        left += calculate(mass[i], location[i], mid);
    
    
    for(int i = posIndex2; i < m; i++)
        right += calculate(mass[i], location[i], mid);
    
    if(left == right)
        return mid;
    else if(left > right)
        return findBalancedLocation(posIndex1, posIndex2, mid, pos2);
    else
        return findBalancedLocation(posIndex1, posIndex2, pos1, mid);
    
}

vector<double> solve(int m) {
    vector<double> balanced(m - 1);
    for(int i = 0; i < m - 1; i++) {
        balanced[i] = findBalancedLocation(i, i + 1, location[i], location[i + 1]);
    }
    
    return balanced;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        
        location.resize(m);
        mass.resize((m));
        location.clear();
        mass.clear();
        
        for(int j = 0; j < m; j++) {
            cin >> location[j];
        }
        
        for(int j = 0; j < m; j++) {
            cin >> mass[j];
        }
        
        vector<double> result = solve(m);
        cout << "#" << i + 1;
        for(int j = 0; j < result.size(); j++) {
            cout << " " << fixed;
            cout.precision(10);
            cout << result[j];
        }
        cout << endl;
    }
}
