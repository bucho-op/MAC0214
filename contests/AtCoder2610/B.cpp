#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<int> rows(8, 0), columns(8, 0);
	for (int i = 0; i<8; i++){
		string s; cin >> s;
		for (int j = 0; j<8; j++){
			if (s[j] == '#'){
				rows[i] = 1;
				columns[j] = 1;
			}
		}
	}
	int c1 = 0, c2 = 0;
	for (int i = 0; i<8; i++){
		if (rows[i] == 0) c1++;
		if (columns[i] == 0) c2++;
	}

	cout << c1*c2 << endl;


	return 0;
}
