#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		string a, b;
		cin >> a >> b;
		int la = a.length(); int lb = b.length();
		vector<vector<pair<int,int>>> dp(la+1, vector<pair<int,int>>(lb+1,{0, 0}));
		for (int i = 1; i<=la; i++){
			for(int j = 1; j<=lb; j++){
				if (a[i-1] != b[j-1] && dp[i-1][j-1].second){
					dp[i][j].first = dp[i-1][j-1].first + 1;
				}
				else if (a[i-1] == b[j-1] && dp[i-1][j-1].second){
					dp[i][j].first = dp[i-1][j-1].first;
				}
				else if (a[i-1] != b[j-1] && not dp[i-1][j-1].second) {
					dp[i][j].first = dp[i-1][j-1].first + 1 + abs(i-j) + abs((la-i+1)-(lb-j+1));
				}
				else if (a[i-1] == b[j-1] && not dp[i-1][j-1].second){
					dp[i][j].first = dp[i-1][j-1].first + abs(i-j) + abs((la-i+1)-(lb-j+1));
				}
				dp[i][j].second = true;
				//cout << dp[i][j].first << " ";	
			}
			//cout << endl;
		}
		

		int max1 = 3000;
		for (int i = 1; i<=lb; i++) max1 = min(max1, dp[la][i].first);
		for (int i = 1; i<=la; i++) max1 = min(max1, dp[i][lb].first);
		cout << max1 << endl;
		

	}
	
	return 0;
}
