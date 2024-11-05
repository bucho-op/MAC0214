#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; bool achou = false; int s = 1; int v = 2; int ans;
		while (!achou){
			s = s + v;
			if (n%s == 0){
				achou = true;
				ans = n / s;	
			}
			v = v*2;
		
		}
		cout << ans << endl;


	}


	return 0;
}
