#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> lcs;

int main(){
	string s, t; cin >> s >> t;
	int ls, lt; ls = s.length(); lt = t.length();
	lcs.resize(ls+1, vector<pair<int,int>>(lt+1, {0,0}));
	for (int i = 1; i<=ls; i++){
		for(int j = 1; j<=lt; j++){
			
			if (s[i-1] == t[j-1]) {
				lcs[i][j].first = lcs[i-1][j-1].first + 1;
				lcs[i][j].second = 5;
			}
			else if (lcs[i-1][j] >  lcs[i][j-1]){
				lcs[i][j].first = lcs[i-1][j].first;
				lcs[i][j].second = 1;
			} else {
				lcs[i][j].first = lcs[i][j-1].first;
				lcs[i][j].second = 2;

			}
		}
	}
	cout << lcs[ls][lt].first << endl;
	
	int i = ls, j = lt; string ans;
	while(i>0 && j>0){
		if (lcs[i][j].second == 5){
			ans = t[j-1] + ans;  j--; i--;
		}
		else if (lcs[i][j].second == 1){
			i--;
		} else if (lcs[i][j].second == 2){
			j--;
		}
	}

	cout << ans << endl;
	return 0;
}
