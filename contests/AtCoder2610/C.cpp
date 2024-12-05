#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, m; cin >> n >> m;
    map<pair<int, int>, int> tab;
    int cont = 0;

    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        
        // Verifica se o par (a, b) não existe no mapa
        if (tab.find({a, b}) == tab.end()) {
            tab[{a, b}] = 1;
            cont++;
        }

        // Verifica e marca todas as outras posições conforme necessário
        if (a + 2 <= n && b + 1 <= n && tab.find({a + 2, b + 1}) == tab.end()) {
            tab[{a + 2, b + 1}] = 1;
            cont++;
        }
        if (a + 1 <= n && b + 2 <= n && tab.find({a + 1, b + 2}) == tab.end()) {
            tab[{a + 1, b + 2}] = 1;
            cont++;
        }
        if (a - 1 > 0 && b + 2 <= n && tab.find({a - 1, b + 2}) == tab.end()) {
            tab[{a - 1, b + 2}] = 1;
            cont++;
        }
        if (a - 2 > 0 && b + 1 <= n && tab.find({a - 2, b + 1}) == tab.end()) {
            tab[{a - 2, b + 1}] = 1;
            cont++;
        }
        if (a - 2 > 0 && b - 1 > 0 && tab.find({a - 2, b - 1}) == tab.end()) {
            tab[{a - 2, b - 1}] = 1;
            cont++;
        }
        if (a - 1 > 0 && b - 2 > 0 && tab.find({a - 1, b - 2}) == tab.end()) {
            tab[{a - 1, b - 2}] = 1;
            cont++;
        }
        if (a + 1 <= n && b - 2 > 0 && tab.find({a + 1, b - 2}) == tab.end()) {
            tab[{a + 1, b - 2}] = 1;
            cont++;
        }
        if (a + 2 <= n && b - 1 > 0 && tab.find({a + 2, b - 1}) == tab.end()) {
            tab[{a + 2, b - 1}] = 1;
            cont++;
        }
    }

    cout << n * n - cont << endl;
    
    return 0;
}
