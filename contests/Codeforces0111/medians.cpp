#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n, k; cin >> n >> k;
		int left = k - 1; int right = k + 1;
		if (n == 1){
			cout << 1 << endl << k << endl;
			continue;
		}
		if (k == n || k == 1) {
			cout << -1 << endl;
			continue;
		}
		if (left % 2 == 1){
			cout << 3 << endl;
			cout << 1 << " " << k << " " << k+1 << endl;

		} else {
			cout << 3 << endl;
			cout << 1 << " " << k-1 << " " << k+2 << endl;
		}
	}
	return 0;
}
