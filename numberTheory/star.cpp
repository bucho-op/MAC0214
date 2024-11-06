#include <bits/stdc++.h>
#define int long long
using namespace std;

// Função para fatorar o número n e retornar os fatores primos
int fatorar(int n) {
    std::vector<int> fatores;
    int ans = 1;
    
    // Remove todos os fatores 2
    int sum = 0;
    while (n % 2 == 0) {
        fatores.push_back(2);
        n /= 2;
        sum++;
    }
    if (sum > 0) ans *= 1*(pow(2, sum-1));

    // Verifica os fatores ímpares de 3 até a raiz quadrada de n
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        int sum = 0;
        while (n % i == 0) {
            fatores.push_back(i);
            n /= i;
            sum++;
        }
        if (sum > 0) ans *= (i-1)*(pow(i, sum-1));
    }

    // Se sobrou um número maior que 2, ele é primo
    if (n > 2) {
        fatores.push_back(n);
        ans *= (n-1); 
    }

    return ans;
}


signed main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
	while (cin >> n){
        int ans = fatorar(n);
        cout << ans/2 << endl;
    }
    return 0;
}

