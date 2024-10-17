#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n; vector<int> vs;
	for (int i = 0; i<n; i++){
		int v; cin >> v; vs.push_back(v);
	}

	int max_v = 0; vector<int> v_max(n);
	if (vs[0] < 0) v_max[0] = 0;
	else v_max[0] = vs[0];
	for (int i = 1; i<n; i++){
		if (v_max[i-1] + vs[i] < 0) v_max[i] = 0;
		else v_max[i] = v_max[i-1] + vs[i];
		max_v = max(max_v, v_max[i]);
	}
	cout << max_v << endl;
	return 0;
}	
