#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int n; cin >> n; vector<pair<int,int>> ini;
	for (int i = 0; i<n; i++){
		int v1, v2; cin >> v1 >> v2;
		ini.push_back({v1, v2});
	}
	sort(ini.begin(), ini.end(), [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        	if (a.second != b.second) {
            		return a.second < b.second;  // Sort by the first element
        	}
        		return a.first < b.first;     // If first elements are equal, sort by the second element
    	});
	int first = ini[0].second; int c = 1;
	for (int i = 0; i<n; i++){
		if (first < ini[i].first){
			first = ini[i].second;
			c++;
		}
	} 
	cout << c << endl;
	return 0;
}
