#include<bits/stdc++.h>
using namespace std;

void crivo(int n, vector<int>& primes){
	vector<bool> is_composite(n+1, false);
	for(int i=2; i<=n; i++){
		if(not is_composite[i]){
			primes.push_back(i);
			for(int j=i*i; j<=n; j+=i)
				is_composite[j] = true;
		}
	}
}

signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<int> primes;
	crivo(n, primes);
	cout << "Os numeros primos entre 1 e " << n << " sao:\n";
	for(int prime : primes){
		cout << prime << ' ';
	}
	cout << '\n';

	return 0;
}

