#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n; int sum = 0;
        while (n/10 > 0){
            int v = n % 10;
            n /= 10;
            sum += v;
        }
        sum += n;
        cout << sum << endl;
    }
}