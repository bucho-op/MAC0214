#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9+7;
int a, b, n;
vector<int> fat(1000001, -1);

int fatorial(int n){
	if (fat[n] != -1){
		return fat[n];
	}

	if (n == 1 || n == 0) return 1;

	else return fat[n] = (n * fatorial(n-1))%MOD;
}

int exp(int a, int b){
	if(b == 0) return 1;
	int tmp = exp(a, b/2);
	tmp = (tmp * tmp)%MOD;
	if(b%2 == 1){
		tmp = (tmp * a)%MOD;
	}
	return tmp;
}

int modular_inverse(int a){
	return exp(a, MOD-2);
}

int comb(int n, int k){
	int numerator, denominator, d;
	numerator = fatorial(n)%MOD;

	denominator = fatorial(k)%MOD;

	d = fatorial(n-k)%MOD;
	denominator = (denominator*d)%MOD;

	return (numerator * modular_inverse(denominator))%MOD;
}
bool check(int s){
	int r;
	while (s > 0){
		r = s % 10;
		s = s / 10;
		if (r != a && r != b) return false;
	}
	return true;
}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b >> n;
	
	int s = n*a;
	int ans = 0;
	for (int i = 0; i<=n; i++){
		if (check(s)) ans = (ans + comb(n, i)) % MOD;
		s += (b-a);
	}
	cout << ans << endl;
	return 0;
}
