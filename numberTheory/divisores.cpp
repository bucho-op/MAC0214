#include <bits/stdc++.h>
using namespace std;

//O(sqrt(n))
void find_divisors(int n, set<int>& divisors){
	for(int d=1; d*d<=n; d++){
		if(n%d == 0){
			divisors.insert(d);
			divisors.insert(n/d);
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false);
	int n; cin >> n;

	set<int> divisors;
	find_divisors(n , divisors);

	cout << "Os divisores de " << n << " sao ";
	for(auto divisor : divisors) cout << divisor << ' ';
	cout << '\n';

	return 0;
}	


