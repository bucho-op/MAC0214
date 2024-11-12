#include <bits/stdc++.h>
using namespace std;

std::vector<int> soma_acumulada_xor(const std::vector<int>& lista) {
    int acumulado = 0;
    std::vector<int> resultado;

    for (int num : lista) {
        acumulado ^= num;  // Operação XOR acumulada
        resultado.push_back(acumulado);  // Adiciona o resultado acumulado à lista
    }

    return resultado;
}

int main(){
	int n; cin >> n; map<int,pair<int,int>> nums; vector<int> vals; vector<int> dp(n+1, 0);
	
	// map com a primeira occrencia e a ultima
	for(int i = 1; i<=n; i++){
		int v; cin >> v;
		vals.push_back(v);
		if (nums.find(v) == nums.end()) {
		    nums[v].first = i;
			nums[v].second = i;
		}
		else nums[v].second = i;
	}
	vector<int> xors = soma_acumulada_xor(vals);
	
	for (int i = 1; i <= n; i++) {
        int firstIndex = nums[vals[i - 1]].first;
        int secondIndex = nums[vals[i - 1]].second;
        
		bool can_choose = true;
        for (int it = firstIndex - 1; it <= secondIndex-1; it++){
			if (nums[vals[it]].first < firstIndex || nums[vals[it]].second > secondIndex) {
				can_choose = false;
				break;
			}
		}
		
		// Calcula o XOR acumulado e evita acessar índices inválidos
        int xorSegment = firstIndex > 1 ? (xors[secondIndex-1] ^ xors[firstIndex - 2]) : xors[secondIndex-1];
        
        // Atualiza o dp com o valor máximo
		if (secondIndex == i && can_choose)
        	if (firstIndex > 1) dp[i] = max(xorSegment + dp[firstIndex - 2], dp[i - 1]);
			else dp[i] = max(xorSegment, dp[i-1]);
		else dp[i] = dp[i-1];
	}
	cout << dp[n] << endl;
	cout << (xors[6]) << endl;

	return 0;
}
