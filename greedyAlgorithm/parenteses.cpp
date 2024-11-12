#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 1 || s[0] == ')'){
        cout << ":(" << endl;
        return 0;
    }
    int v1 = n / 2;
    for (int i = 0; i<n; i++){
        if (s[i] == '(') v1--;
    }
    
    int c = 1;
    if (s[0] == '?') {
        s[0] = '(';
        v1--;
    }
    for (int i = 1; i<n; i++){
        if (c <= 0 && i < n-1){
            cout << ":(" << endl;
            return 0;
        }

        if (s[i] == '?'){
            if (v1 > 0){
                v1--; c++;
                s[i] = '(';
            } else {
                c--;
                s[i] = ')';
            }
        } else if (s[i] == '(') {
            c++;
        } else if (s[i] == ')') {
            c--;
        }
    }

    if (c != 0) {
        cout << ":(" << endl;
        
    } else {
        cout << s << endl;
    }

    return 0;
}