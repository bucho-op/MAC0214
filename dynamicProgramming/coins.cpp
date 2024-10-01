#include <bits/stdc++.h>
using namespace std;
#define float double
int main(){
	int n; cin >> n; vector<float> probs; vector<vector<float>> dp(n+1, vector<float>(n+1,0));
	for(int i = 0; i<n; i++){
		float v; cin >> v;
		probs.push_back(v);
	}
	
	float soma = 0;
	for(int i = 0; i<=n; i++){
		for(int j = 0; j<=n; j++){
			if (i == 0 && j == 0) dp[i][j] = 1;
			else if (i == 0) dp[i][j] = dp[i][j-1] * (1 - probs[i+j-1]);
			else if (j == 0) dp[i][j] = dp[i-1][j] * probs[i+j-1];
			else if (i + j <= n){
				dp[i][j] = (dp[i-1][j] * probs[i+j-1]) + (dp[i][j-1] * (1 - probs[i+j-1]));
			}
			if (i+j == n && i>j) {
				soma += dp[i][j];
			}
		}
	}
	
	cout << fixed << setprecision(10) <<  soma << endl;

	return 0;
}
