#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n; vector<string> names; map<string, bool> r;
	for(int i = 0; i<n; i++){
		string s; cin >> s;
		names.push_back(s);
		r[s] = 0;
	}
	for (int i = n-1; i>=0; i--){
		if (r[names[i]] == 0){
			cout << names[i] << endl;
			r[names[i]] = 1;
		}
	}
	
	return 0;
}
