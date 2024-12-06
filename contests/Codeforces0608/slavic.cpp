#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        string s, t; cin >> s >> t;
    	int ind = 0;
    	for(int i = 0; i < s.size(); ++i) {
    		if(s[i] == '?') {
    			if(ind < (int)t.size()) s[i] = t[ind++];
    			else s[i] = 'a';
    		} else if(s[i] == t[ind]) ++ind;
    	}
    	if(ind >= t.size()) cout << "YES" << endl << s << endl;
    	else cout << "NO" << endl;
    }
}