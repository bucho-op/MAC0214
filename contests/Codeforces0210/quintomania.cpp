#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		int f; cin >> f; bool b = 1;
		for(int i = 1; i<n; i++){
			int s; cin >> s;
			if (abs(s-f) != 5 && abs(s-f) != 7){
				b = 0;
			}
			f = s;
		}
		if (b) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}	
