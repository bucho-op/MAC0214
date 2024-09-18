#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n, w; cin >> n >> w;
	vector<pair<int,int>> items(n);
	for (int i = 0; i<n; i++){
		cin >> items[i].first >> items[i].second;
	}
	sort(items.begin(), items.end());
	vector<int> tams(w+1, 0); //  vetor de 0 até w capacidades
	vector<vector<int>> dp(w+1, vector<int>(n+1,0));
	for (int i = 0; i<=n; i++){
		dp[0][i] = 0;
	}
	for (int i = 1; i<=w; i++){
		for(int j = 1; j<=n; j++){
			int peso = items[j-1].first;
			int valor = items[j-1].second;
			
			if (peso <= i){
				dp[i][j] = max(valor + dp[i-peso][j-1], dp[i][j-1]);
				
			} else {
				dp[i][j] = dp[i][j-1];
			}
			
				
		}
	}

	cout << dp[w][n] << endl;

	return 0;
}
