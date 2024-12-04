#include <bits/stdc++.h>
using namespace std;

int exp(int a, int b){
	if(b == 0) return 1; // x^0 = 1 (base)
	int tmp = exp(a, b/2); 
	tmp *= tmp;
	if(b%2 == 1){
		tmp *= a; // se b for impar ainda multiplica uma vez
	}
	return tmp;
}

int main(){
	int a, b; cin >> a >> b;
	cout << exp(a,b) << endl;
}
