#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n;
		int c_1 = 0; int min_z, max_z;
		for (int i = 0; i<2*n; i++){
			int v; cin >> v;
			if (v == 1) c_1++;
		}
		if (c_1 % 2 == 0) {
			min_z = 0;
			max_z = n - abs(n - c_1);
		} else {
			min_z = 1;
			max_z = n - abs(n-c_1);
		}
		cout << min_z << " " << max_z << endl;
	}

	return 0;
}
