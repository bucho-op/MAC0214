#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int l, r, k; cin >> l >> r >> k; //int ans = 0;
		int a = r/k - l + 1;
		if (a<0) cout << 0 << endl;
		else cout << a << endl;
	}
	return 0;

}
