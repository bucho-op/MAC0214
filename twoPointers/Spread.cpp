#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, k; cin >> n >> k; vector<int> a;
	for (int i =0; i<n; i++) {
		int v; cin >> v;
		a.push_back(v);
	}
	multiset<int> vals;
	int i = 0, sum = 0; int max_dif = 0;
       	int minv, maxv;
	for (int j = 0; j<n; j++){
		vals.insert(a[j]);
		minv = *vals.begin();
        	maxv = *vals.rbegin();
		max_dif = maxv - minv;
		while (max_dif > k){
			vals.erase(vals.find(a[i]));
			i++;
			minv = *vals.begin();
        		maxv = *vals.rbegin();
			max_dif = maxv - minv;
			
		}
		sum += (j-i+1);
	}
	cout << sum << endl;
	return 0;
}
