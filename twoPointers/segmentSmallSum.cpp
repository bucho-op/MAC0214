#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, s; cin >> n >> s;
	vector<int> a;
	
	for (int i = 0; i < n; i++) {
		int v; cin >> v;
		a.push_back(v);
	}


	int max_v = 0; // resposta
	int i = 0, sum = 0;
	int j = -1;
	
	while(j<n){
		
		while (sum <= s && j < n){
			j++;
			sum += a[j];
			
		}
		max_v = max(j-i, max_v);

		while (sum > s){
			sum -= a[i];
			i++;
		}
		
	}
	cout << max_v << endl;
	return 0;
}
