#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;

int calc(int x, int y)
{
    int cnt1 = 0, cnt2 = 0;
	int bal = 0;
	int ansP = 0;
	for (int i = x; i < y; i++) 
	{
		if (bal % 2 == 0) 
		{	
			cnt1++;
		} 
		else 
		{
			cnt2++;
		}
		if (a[i] < 0)
		{
			bal++;
		}
		if (bal % 2 == 0) 
		{
			ansP += cnt1;
		} 
		else 
		{
			ansP += cnt2;
		}
	}
	return ansP;
    
}

signed main(){
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i<n; i++){
        cin >> a[i];
    }
    int ind = 0; int next = 0; int v1, v2; int cp = 0, cn = 0;
    for (int i = 0; i<n; i++){
        if (a[i] == 0) {
            v1 = calc(next, i);
            v2 = ((i-next)*(i-next+1)/2) - v1;
            next = i+1;
            cp += v1; cn += v2;
        }
    }
    if (next <= n-1) {
        v1 = calc(next, n); 
        v2 = ((n-next)*(n-next+1)/2) - v1;
        cp += v1; cn += v2;
    }
    int c0 = n*(n+1)/2 - cp - cn;
    cout << cn << " " << c0 << " " << cp << endl;
    
    

}