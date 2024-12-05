#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; int c0 = 0;
		string s, r; cin >> s >> r;
		for (int i = 0; i<n; i++){
			if (s[i] == '0') c0++;
		}
		int c1 = n - c0;
		bool b1 = false;
		for (int i = 0; i<n-1; i++){
			if (c0 == 0 || c1 == 0) {
				b1 = true; break;
			}
			if (r[i] == '0') c1--;
			else c0--;
			
		}

		if (b1) cout << "NO" << endl;
		else cout << "YES" << endl;

	}
	return 0;

}
