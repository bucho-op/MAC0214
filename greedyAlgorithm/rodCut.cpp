#include <bits/stdc++.h>
using namespace std;

vector<int> vs;

int main(){
    int l, k; cin >> l >> k;
    for (int i = 0; i<k; i++){
        int pi; cin >> pi; 
        if (pi < l/2)
            vs.push_back(pi);
        else 
            vs.push_back(l-pi);
    }
    sort(vs.begin(), vs.end());
    reverse(vs.begin(), vs.end());
    vector<bool> tronco(l-1, false);
    int custo = l;
    tronco[vs[0]] = 1;
    for (int i = 1; i<k; i++){
        int a; a = vs[i];
        int b; b = l-vs[i];
        int best;
        bool b1 = 0, b2 = 0;

        while (b >= 0){
            if (tronco[b] == 1){
                break;
            }
        }
        while (a < l){
            if
        }
        // if (tronco[a] == 1) b1 = true;
        // if (tronco[l-a] == 1) b2 = true;
        // cout << b1 << " " << b2 << endl;
        // while (a >= 0 && a<l){
        //     if (tronco[a] == 1 && !b1) {
        //         cout << a << endl;
        //         best = a;
        //         tronco[vs[i]] = 1;
        //         break;
        //     }
        //     if (tronco[l-a] == 1 && !b2) {
        //         cout << l-a << endl;
        //         best = l-a;
        //         tronco[l-vs[i]] = 1;
        //         break;
        //     }
        //     a++;
        // }
        //cout << min(a, l-a) << endl;
        //custo += min(a,l-a);
    }
    cout << custo << endl;
    
    return 0;
}
