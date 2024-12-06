#include<bits/stdc++.h>
#define int long long
using namespace std;
vector<int> a(3*10e6);
signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; int sum = 0, sum1 = 0, sum2 = 0;
        for (int i = 1; i<=n; i++){
            cin >> a[i]; sum += a[i];
        

            if (i%2){
                sum1 += a[i];
            } else {
                sum2 += a[i];
            }
        }
        if (sum%n == 0) {
            int meta = sum / n;
            int p1 = (n+1) / 2;
            int p2 = n - p1;

            if (sum1 == p1 * meta && sum2 == p2 * meta){
                cout << "yes" << endl;
            }
            else cout << "no" << endl;
        }
        else cout << "no" << endl;
    }
    return 0;
}