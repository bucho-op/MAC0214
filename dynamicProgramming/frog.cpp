#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k; cin >> n >> k; vector<int> stones;
	for (int i = 0; i<n; i++) {
		int stone; cin >> stone; stones.push_back(stone);
	}
	vector<long long> dp(n, 1000000000000);
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		int atual = stones[i];
		for(int j = i-k; j<i; j++){
			int v = abs(atual-stones[j]);
			if (j < 0) continue;
	//		cout << v << endl;
		//	cout << dp[j] + v << endl;
			dp[i] = min(dp[i],  dp[j] + v);
		}
		//cout << dp[i] << endl;
	}

	cout << dp[n-1] << endl;
	return 0;
}
