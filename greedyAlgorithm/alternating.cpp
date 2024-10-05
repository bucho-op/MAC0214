#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; vector<int> vs;
		for (int i = 0; i<n; i++){
			int v; cin >> v; vs.push_back(v);
		}

		int i = 0; int c = 0;
		while (i<n){
			int max_v = 0;
			while (vs[i] > 0 && i<n){
				max_v = max(max_v, vs[i]);
				i++;
			}
			c += max_v;
			if (i >= n) continue;

			int min_v = -1000000000;
			while(vs[i] < 0 && i<n){
				min_v = max(min_v, vs[i]);
				i++;
			}
			//cout << min_v << endl;
			c += min_v;
		}
		cout << c << endl;
	}
	
	return 0;
}
