#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n,k;
        cin >> n >> k;
        if (((n+1)*n/2 - (n-k)*(n-k+1)/2)%2){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}