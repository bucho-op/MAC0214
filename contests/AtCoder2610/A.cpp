#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	bool a_check = 0, b_check = 0, c_check = 0;
	for (int i = 0; i<3; i++){
		if (s[i] == 'A') a_check = 1;
		if (s[i] == 'B') b_check = 1;
		if (s[i] == 'C') c_check = 1;
	}

	if (a_check && c_check && b_check) cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}
