#include <bits/stdc++.h>

using namespace std;
void solve(int c, vector<int>& max_v, vector<int>& max_i, vector<int>& v){
    for (int C = 1; C<c+1; C++){
        for (int j = 1; j<10; j++){
            int teste = C - v[j];
            if (teste >= 0) {
                int valor = 1 + max_v[teste];
                if (valor >= max_v[C]) {
                    max_v[C] = valor;
                    max_i[C] = j;
                }
            }
        }

    }
}
int main() {
    int c;
    cin >> c;
    vector<int> v(10);

    bool tem_resp = false;
    for (int x = 1; x<10; x++){
        cin >> v[x];
        if (v[x] <= c) tem_resp = true; 
    }
    
    if (not tem_resp) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> max_v(c+1, 0);
    vector<int> max_i(c+1);

    solve(c, max_v, max_i, v);
    vector<int> a;
    int v_max = max_v[c];

    while (v_max > 0) {
        int c_atual = c - v[max_i[c]];
        a.push_back(max_i[c]);
        c = c_atual;
        v_max--;
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) cout << a[i];

    return 0;
}
