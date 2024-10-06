#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;  vector<int> vs; vector<int> ans(n, 0); vector<int> ans1(n, 0);
	for (int i = 0; i<n; i++){
		int v; cin >> v;
		vs.push_back(v);
	}
	
	ans[0] = 1;
	for (int i = 1; i<n; i++){
		//cout << vs[i-1] << " " << ans[i-1] << endl;
		if (vs[i] > ans[i-1]){
			ans[i] = ans[i-1] + 1;	
		} else {
			ans[i] = vs[i];
		}
	//	cout << ans[i] << " ";
	}
	//cout << endl;
	ans1[n-1] = 1;
	for(int i = n-2; i>=0; i--){
		if (vs[i] > ans1[i+1]){
			ans1[i] = ans1[i+1] + 1;
		} else {
			ans1[i] = vs[i];
		}
		//cout << ans1[i] << " ";
	}
	int max_v = 0;
	for (int i = 0; i<n; i++){
		int min_v = min(ans[i], ans1[i]);
		max_v = max(max_v, min_v);
	}

	cout << max_v << endl;
}
