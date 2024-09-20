#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
vector<vector<int>> vals;
int calc(int num, int bef){
	int x, y;
	if (bef == 0) {
		x = 1; y = 2;
	}
	if (bef == 1) {
		x = 0; y = 2;
	}
	if (bef == 2) {
	      	x = 0; y = 1;	
	}	
	
	//cout << num << " " << bef << endl;
	if (num < 1) return 0;
	if (dp[num][bef] != -1) return dp[num][bef];
	//cout << "valor de y: " << y << endl;
	int a = calc(num-1,x);
	//cout << "valor de y: " << y << endl;
	int b = calc(num-1, y);

	//cout << vals[num][bef] << " + " << a << " compara " << vals[num][bef] << " + " <<  b  << endl;
	return dp[num][bef] = max(vals[num][bef] + a, vals[num][bef] + b);
}

int main(){
	int n; cin >> n;
	dp.resize(n+1, vector<int>(3, -1));
	vals.resize(n+1, vector<int>(3));
	for (int i = 1; i<=n; i++){
		for (int j = 0; j<3; j++){
			int v; cin >> v;
			vals[i][j] = v;
		}
	}

	int res = 0;
	for (int i = 0; i<3; i++){
		res = max(res, calc(n,i));
		//cout << res << "A" << endl;
	}
	cout << res << endl;
	return 0;
}
