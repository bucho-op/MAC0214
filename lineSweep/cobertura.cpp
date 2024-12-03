#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    int n, m; cin >> n >> m; vector<pair<int,int>> eventos; vector<int> ans;
    for (int i = 0; i<n; i++){
        int a, b; cin >> a >> b;
        eventos.pb({a, 0});
        eventos.pb({b, 1});
    }

    sort(eventos.begin(), eventos.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        if (a.first != b.first)
            return a.first < b.first;
        return a.second < b.second; 
    });
    int ind = 0; int c = 0; bool back = false;
    for (int i = 1; i<=m; i++){
        
        if (eventos[ind].first == i && eventos[ind].second == 0){
            c++; ind++; i--; back = true;
        } else if (eventos[ind].first == i && eventos[ind].second == 1) {
            c--; ind++; i--; back = true;
        } else if (c == 0 && !back) {
            ans.push_back(i); back = false;
        } else {
            back = false;
        }
        
        
    }
    cout << ans.size() << endl;
    if (ans.size() > 0){
        for (int i = 0; i<ans.size() - 1; i++){
            cout << ans[i] << " ";
        }
        cout << ans[ans.size() - 1] << endl;
    }
    return 0;

}