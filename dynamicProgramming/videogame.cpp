#include <bits/stdc++.h>
using namespace std;

vector<int> dp, vals;

int calc_dp(int v){
	if (dp[v] != -1) return dp[v];
	if (v == 1) return dp[v] = 0;
	if (v == 2) return dp[v] = abs(vals[v-1] - vals[v-2]);
	return dp[v] = min(abs(vals[v-1] - vals[v-2]) + calc_dp(v-1), abs(vals[v-1] - vals[v-3]) + calc_dp(v-2));
}

int main(){
	int n; cin >> n; dp.resize(n+1, -1);
	for (int i = 0; i<n; i++){	
		int v; cin >> v; vals.push_back(v);
	}	
	cout << calc_dp(n) << endl;

	return 0;		
}
