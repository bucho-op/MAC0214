#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, k; cin >> n >> k; vector<int> a;
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		a.push_back(v);
	}
	
	int final_sum = 0;
	int i = 0; int sum = 0;
	for (int j = 0; j < n; j++){
		sum += a[j];
		while (sum > k) {
			sum -= a[i];
			i++;	
		}

		final_sum += ((j-i+1)*(j-i+2))/2;
	}
	cout << final_sum << endl;
	return 0;
}
