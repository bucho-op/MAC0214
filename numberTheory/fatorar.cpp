#include <bits/stdc++.h>
using namespace std;

// Função para fatorar o número n e retornar os fatores primos (O(sqrt(n))
int fatorar(int n) {
    std::vector<int> fatores;
    
    // Remove todos os fatores 2 (deixa o loop de rapido 2x + rapido)
    while (n % 2 == 0) {
        fatores.push_back(2);
        n /= 2;
    }

    // Verifica os fatores ímpares de 3 até a raiz quadrada de n
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            fatores.push_back(i);
            n /= i;
        }
    }

    // Se sobrou um número maior que 2, ele é primo
    if (n > 2) {
        fatores.push_back(n);
        
    }

    return fatores;
}


int main(){
	int n; cin >> n;
	vector<int> ans = fatorar(n);
	
	return 0;
}
