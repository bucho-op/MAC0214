#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int a, b; cin >> a >> b;
        int min_v = 100;
        for (int i = a; i<=b; i++){
            min_v = min((i - a) + (b - i), min_v);
        }

        cout << min_v << endl;
    }


    return 0;
}