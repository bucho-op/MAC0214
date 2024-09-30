#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;

	while(t--){
		string a, b; cin >> a >> b;
		int la = a.length(); int lb = b.length();
		vector<vector<int>> dp(la+1, vector<int>(lb+1, 0));
		for (int i = 1; i <= la; i++){
			for(int j = 1; j <= lb; j++){
				if (a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1];
				} else{
					dp[i][j] = min(dp[i-1][j-1] + 1, min(dp[i-1][j] + 1, dp[i][j-1] + 1));
				}
			}
		}

		cout << dp[la][lb] << endl;
	}
	return 0;
}
