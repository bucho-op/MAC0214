#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    int n; cin >> n; vector<pair<int,int>> eventos;
    for (int i = 0; i<n; i++){
        int a, b; cin >> a >> b;
        eventos.pb({a, 0});
        eventos.pb({b, 1});
    }

    sort(eventos.begin(), eventos.end());
    int c = 0, max_c = 0;
    for (auto& evento : eventos){
        if (evento.second == 0){
            c++;
        } else {
            c--;
        }
        max_c = max(c, max_c);
    }
    cout << max_c << endl;
    return 0;

}