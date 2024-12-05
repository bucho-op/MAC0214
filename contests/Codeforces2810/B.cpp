#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int t; cin >> t;
	while (t--){
		int n; cin >> n; vector<int> difs; vector<int> vals;
		for (int i = 0; i<n; i++){
			int v1; cin >> v1; vals.push_back(v1);
		}

		if (n == 1) {
			cout << 1 << endl;
			continue;
		}

		if (n % 2 == 0){
			for (int i = 0; i<n; i+=2){
				difs.push_back(abs(vals[i] - vals[i+1]));
				
			}
		} else {
			int max_dis = 0; int max_ind;
			for(int i = 0; i<n-1; i++){
				if (abs(vals[i] - vals[i+1]) > max_dis){
					max_dis = abs(vals[i] - vals[i+1]);
					if (i %2 == 0) max_ind = i;
					else max_ind = i+1;
					
				}
				//cout << abs(vals[i] - vals[i+1]) << " a ";	
			}
			vals.erase(vals.begin() + max_ind);
			for (int i = 0; i<n-1; i+=2){
				//cout << vals[i] << " e " << vals[i+1] << endl;
				difs.push_back(abs(vals[i] - vals[i+1]));
				//cout << "dif: " << abs(vals[i] - vals[i+1]) << endl;
			}
			
		}
		
		
		// for (int i = 0; i<difs.size(); i++){
		// 	cout << difs[i] << " ";
		// }
		sort(difs.begin(), difs.end());
		cout << difs[difs.size() - 1] << endl;
		
	}
	
	
	return 0;
}
