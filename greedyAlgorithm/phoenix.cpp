#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int t; cin >> t;
	while(t--){
		vector<int> values;
		int p1 = 0, p2 = 0;
		int n; cin >> n; int pot = 1;
		for (int i = 1; i<=n; i++){
			values.push_back(2 * pot);
			pot = pot * 2;	
		}
		int a = 0, b = n-1;
		for (int i = 0; i<n; i++){
			if (i % 2 == 0){
				if (p1 > p2){
					p1 += values[a];
					a++;
				} else {
					p1 += values[b];
					b--;
				}

			} else {
				if (p1 > p2){
					p2 += values[b];
					b--;
				} else {
					p2 += values[a];
					a++;
				}
			}
		}
		cout << abs(p1 - p2) << endl;
	}
	
	return 0;
}
