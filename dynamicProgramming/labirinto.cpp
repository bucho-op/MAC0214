#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<char>> lab;
vector<vector<int>> dp;
int calc_dp(int i, int j){
	if (i < 0 || j < 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	if (lab[i][j] == '*') return dp[i][j] = 0;
	if (i == 0 && j == 0) return dp[i][j] = 1;
	
	return dp[i][j] = (calc_dp(i-1,j)%1000000007 + calc_dp(i,j-1)%1000000007)%1000000007;

}
signed main(){
	int n; cin >> n; lab.resize(n, vector<char>(n)); dp.resize(n, vector<int>(n, -1));
	for (int i = 0; i<n; i++){
		string s; cin >> s;
		for (int c = 0; c<n; c++){
			lab[i][c] = s[c];
		}
	}

	cout << calc_dp(n-1, n-1)%1000000007  << endl;
	
	return 0;
}
