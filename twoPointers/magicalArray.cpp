#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	int n, res; cin >> n; res = n;
	int n_m = n-1;
	int temp = -1; int reps = 1;
	while (n--){
		int v; cin >> v;
		if (n != n_m) {
			if (v == temp) {
				reps++;
				res += (reps-1);;

			} else {
				reps = 1;
			}
		}
		temp = v;
	}
	cout << res << endl;
	return 0;

}
