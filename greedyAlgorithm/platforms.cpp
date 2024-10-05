#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, d; cin >> n >> m >> d; vector<int> ans(n+1,0); vector<pair<int,int>> ps; int sum = 0;
	for(int i = 0; i<m; i++){
		int v; cin >> v;
		ps.push_back({i+1, v}); // numero e tamanho da plataforma
		sum += v;
	}
	int pos = 0; int i = 0;
	while (i<m){
		if (pos + d <= n-sum+1){
			pos += d;
			int plat = ps[i].first;
			int tam = ps[i].second;
			for (int j = pos; j<pos+tam; j++){
				ans[j] = plat;
			}
			pos += tam - 1;
			i++;
			sum -= tam;
		} else {
			pos = n-sum + 1;
			while (pos <= n){
				int plat = ps[i].first;
				int tam = ps[i].second;
				while (tam > 0){
					ans[pos] = plat;
					pos++; tam--;
				}
				i++;
			}
			break;
		}
		
	}
	pos += d;
	if (pos > n){
		cout << "YES" << endl;
		for (int i = 1; i<n; i++){
			cout << ans[i] << " ";
		}
		cout << ans[n] << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
