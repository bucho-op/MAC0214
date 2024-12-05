#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed;
    unsigned long long t;
    cin >> t;
    while (t--) {
        unsigned long long n;
        unsigned long long x, y;
        cin >> n >> x >> y;
        vector<unsigned long long> v(n);
        for (unsigned long long i = 0; i < n; i++) 
            cin >> v[i];
        
        map<pair<unsigned long long, unsigned long long>, unsigned long long> myMap;
        for (unsigned long long i = 0; i < n; i++) {
            pair<unsigned long long, unsigned long long> par = {v[i] % x, v[i] % y}; 
            if (myMap.find(par) == myMap.end()) {
                myMap[par] = 1;
            } else {
                myMap[par]++;
            } 
        }
        
        unsigned long long res = 0;
        for (unsigned long long i = 0; i < n; i++) {
            pair<unsigned long long, unsigned long long> par = {v[i] % x, v[i] % y};
            pair<unsigned long long, unsigned long long> second_par = {(x - v[i] % x) % x, v[i] % y}; 
            if (myMap[par] != -1 && par == second_par) {
                if (myMap[par] > 1) res += (myMap[par] * (myMap[par] - 1)) / 2;
                myMap[par] = -1;
            } 
            if (myMap[par] != -1) {
                if (myMap.find(second_par) != myMap.end() && myMap[second_par] != -1) {
                    res += myMap[par] * myMap[second_par];
                    myMap[par] = -1;
                    myMap[second_par] = -1;
                }
                myMap[par] = -1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
