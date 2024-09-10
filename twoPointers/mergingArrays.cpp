#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m; cin >> n >> m;
	// 'cout << m << endl;
	vector<int> a;
    	vector<int> b;
	vector<int> res;
	while (n--){
		int v; cin >> v;
		a.push_back(v);
	
	}
	
	while (m--) {
		int v; cin >> v;
		b.push_back(v);
	}
	
	int i = 0, j = 0;
	int c = 0;
	int ta = a.size(); int tb = b.size(); int tres = ta + tb; res.resize(tres);
	while (c < tres){
		
		if (i >= ta) {
			res[c] = b[j];
			j++;
		}
		else if (j >= tb) {
			res[c] = a[i];
			i++;
		}
		else if (a[i] >= b[j]) {
			res[c] = b[j];
			j++;
		} else {
			res[c] = a[i];
			i++;
		}
		c++;

	}
	for (int i = 0; i<c-1; i++){
		cout << res[i] << " ";
	}
	cout << res[tres-1] << endl;
	return 0;

}

