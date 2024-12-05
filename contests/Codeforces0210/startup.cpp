#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k; vector<int> brand(k, 0);
		for(int i = 0; i<k; i++){
			int b, c; cin >> b >> c;
			brand[b-1] += c;
		}
		sort(brand.begin(), brand.end());
		reverse(brand.begin(), brand.end());
		int ans = 0;
		
		if (n < k){
			for (int i = 0; i<n; i++){
				ans += brand[i];
			}
		} else {
			for (int i = 0; i<k; i++){
				ans += brand[i];
			}
		}
		cout << ans << endl;


	}

	return 0;
}
