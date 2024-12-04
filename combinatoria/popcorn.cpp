#include<bits/stdc++.h>
using namespace std;
#define int long long

vector<int> fat(25, -1);

int fatorial(int n){
	if (fat[n] != -1){
		return fat[n];
	}

	if (n == 1 || n == 0) return 1;

	else return fat[n] = (n * fatorial(n-1));
}

int exp(int a, int b){
	if(b == 0) return 1;
	int tmp = exp(a, b/2);
	tmp = (tmp * tmp);
	if(b%2 == 1){
		tmp = (tmp * a);
	}
	return tmp;
}

int modular_inverse(int a){
	return exp(a,-2);
}

int comb(int n, int k){
	int numerator, denominator, d;
	numerator = fatorial(n);

	denominator = fatorial(k);

	d = fatorial(n-k);
	denominator = (denominator*d);

	return (numerator / denominator);
} 

signed main(){
    int t; cin >> t;
    while(t--){
        int n, k; cin >> n >> k; cout << comb(n, k) << endl;
    }
    return 0;
}